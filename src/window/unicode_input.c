#include <internal/glfw_window.h>

void character_callback(GLFWwindow* window, unsigned int codepoint){
	struct window* win = from_glfw_win(window);
	if (win){
		win->uni_cb(win, codepoint);
	}
}

void set_unicode_cb(struct window* win, uni_cb uni){
	win->uni_cb = uni;
}
