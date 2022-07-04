#ifndef _H_GLFW_WINDOW_H
#define _H_GLFW_WINDOW_H
#include <window/window.h>
#include <bin_tree.h>

/* window and monitors */
struct monitor{
	GLFWmonitor* glfw_monitor;
};
typedef struct monitor monitor_t;

struct window{
	GLFWwindow* glfw_win;
	gen_cb key_cb;
	gen_cb mouse_cb;

	/* tree key is glfw_win (assumed restrict)! */
	struct tree_node bst_node;
};
typedef struct window window_t;

struct glfw_key_data{
	int keycode;
	int scancode;
	int press_type;
	int key_flags;
} glfw_key_data;

#endif /* _H_GLFW_WINDOW_H */
