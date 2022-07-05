#ifndef _H_GLFW_WINDOW_H
#define _H_GLFW_WINDOW_H
#include <window/window.h>
#include <GLFW/glfw3.h>
#include <bin_tree.h>
#include <stdlib.h>

/* window and monitors */
struct window{
	GLFWwindow* glfw_win;
	key_cb key_cb;

	/* tree key is glfw_win (assumed restrict)! */
	struct tree_node bst_node;
};
typedef struct window window_t;

window_t* from_glfw_win(GLFWwindow*);

static inline void swindow_free(void* node){
	struct window *entry = get_entry(
			(struct tree_node*)node, 
			struct window, bst_node);
	glfwDestroyWindow(entry->glfw_win);
	free(entry);
}

static inline int swindow_cmp_key(struct tree_node* node, const void* key){
	struct window *entry = get_entry(node, struct window, bst_node);
	return (int)((char*)entry->glfw_win - (char*)key);
}

static inline int swindow_cmp_node(struct tree_node* node0, 
		struct tree_node* node1)
{
	return swindow_cmp_key(node0, get_entry(node1, struct window, 
				bst_node));
}

#endif /* _H_GLFW_WINDOW_H */
