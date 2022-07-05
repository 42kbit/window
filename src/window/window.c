#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <internal/glfw_window.h>
#include <internal/glfw_callbacks.h>
#include <internal/glfw_monitor.h>
#include <bin_tree.h>

static struct tree_node* win_root = NULL;

window_t* from_glfw_win(GLFWwindow* win){
	struct tree_node* node = bst_find(win_root, win, swindow_cmp_key);
	if (!node)
		return NULL;
	else
		return get_entry(node, struct window, bst_node);
}

window_t* create_window(
		char* name,
		int w, 
		int h, 
		monitor_t* monitor
		)
{
	window_t* win = (window_t*)malloc(sizeof(window_t));
	if (!win){
		return NULL;
	}
	GLFWmonitor* glfw_moni = __get_glfw_monitor(monitor);
	win->glfw_win = glfwCreateWindow(
			w,
			h,
			name,
			glfw_moni? glfw_moni : NULL,
			NULL);
	if (!win->glfw_win){
		return NULL;
	}

	tree_init_node(&(win->bst_node));
	/* if first node, make it root. 
	 * else insert in existing tree */
	if (!win_root)
		win_root = &(win->bst_node);
	else
		bst_insert(win_root, &(win->bst_node), swindow_cmp_node);

	/* here init callbacks */
	init_glfw_callbacks(win->glfw_win);

	return win;
}
void free_window(struct window* win){
	bst_remove(win_root, &(win->bst_node), swindow_cmp_node);
	if (&(win->bst_node) == win_root)
		win_root = NULL;
	swindow_free(&(win->bst_node));
}
int is_open(window_t* win){
	return !glfwWindowShouldClose(win->glfw_win);
}
void swap_buffers(window_t* win){
	glfwSwapBuffers(win->glfw_win);
}
void make_cur_context(window_t* win){
	glfwMakeContextCurrent(win->glfw_win);
}
int init_window_lib(void){
	return glfwInit();
}
void free_window_lib(void){
	bst_remove_subtree(win_root, win_root, 
			swindow_cmp_node, swindow_free);
	glfwTerminate();
}
