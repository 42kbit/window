#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <internal/glfw_window.h>
#include <bin_tree.h>

void swindow_free(void* node){
	struct window *entry = get_entry(
			(struct tree_node*)node, 
			struct window, bst_node);
	glfwDestroyWindow(entry->glfw_win);
	free(entry);
}

int swindow_cmp_key(struct tree_node* node, const void* key){
	struct window *entry = get_entry(node, struct window, bst_node);
	return (int)((char*)entry->glfw_win - (char*)key);
}

int swindow_cmp_node(struct tree_node* node0, struct tree_node* node1){
	return swindow_cmp_key(node0, get_entry(node1, struct window, 
				bst_node));
}

static struct tree_node* win_root = NULL;

static inline window_t* from_glfw_win(GLFWwindow* win){
	struct tree_node* node = bst_find(win_root, win, swindow_cmp_key);
	if (!node)
		return NULL;
	else
		return get_entry(node, struct window, bst_node);
}

void glfw_key_callback(
		GLFWwindow* window,
		int key,
		int scancode,
		int action,
		int mods)
{
	window_t* win = from_glfw_win(window);
	win->key_cb(win);
}

monitor_t* create_monitor(void){
	monitor_t* monitor = (monitor_t*)malloc(sizeof(monitor_t));
	monitor->glfw_monitor = glfwGetPrimaryMonitor();
	return monitor;
}
void free_monitor(monitor_t* monitor){
	free(monitor);
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
	win->glfw_win = glfwCreateWindow(
			w,
			h,
			name,
			monitor? monitor->glfw_monitor : NULL,
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
	glfwSetKeyCallback(win->glfw_win, glfw_key_callback);

	return win;
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
void free_window(struct window* win){
	/* TODO:remove from static array */
	bst_remove(win_root, &(win->bst_node), swindow_cmp_node);
	if (&(win->bst_node) == win_root)
		win_root = NULL;
	swindow_free(&(win->bst_node));
}
char* get_window_title(struct window* win){
	return NULL;
}
void set_window_title(struct window* win, char* new_name){
	glfwSetWindowTitle(win->glfw_win, new_name);
}
int vsync_state;
int init_window_lib(void){
	vsync_state = 0;
	return glfwInit();
}
void free_window_lib(void){
	bst_remove_subtree(win_root, win_root, 
			swindow_cmp_node, swindow_free);
	glfwTerminate();
}

int vsync_get(){
	return vsync_state;
}
void vsync_set(int value){
	vsync_state = value?1:0;
	glfwSwapInterval(vsync_state);
}

/* input */
void poll_events(window_t* win){
	glfwPollEvents();
}
void set_key_cb(window_t* win, gen_cb newcb){
	win->key_cb = newcb;
}
void set_mouse_cb(struct window* win, gen_cb newcb){
	win->mouse_cb = newcb;
}
