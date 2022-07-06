#include <internal/glfw_window.h>

void character_callback(GLFWwindow* window, unsigned int codepoint){
	struct window* win = from_glfw_win(window);
	if (!win) return;
	win->input->unicode_char = codepoint;
	if (win->unicode_cb)
		win->unicode_cb(win);
}

void set_unicode_cb(struct window* win, gen_cb uni){
	win->unicode_cb = uni;
}
