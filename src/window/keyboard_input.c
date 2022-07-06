#include <internal/glfw_window.h>

/* parse glfw keycodes, to our keycodes */
int key_keycode(struct window* w){
	return w->input->keyboard_keycode;
}
int key_action(struct window* w){
	return w->input->keyboard_action;
}
int key_flags(struct window* w){
	return w->input->keyboard_flags;
}

void set_keyboard_key_cb(struct window* win, gen_cb newcb){
	win->keyboard_cb = newcb;
}

void glfw_key_callback(
		GLFWwindow* window,
		int keycode,
		int scancode,
		int action,
		int mods)
{
	struct window* win = from_glfw_win(window);
	win->input->keyboard_keycode = keycode;
	win->input->keyboard_action = action;
	win->input->keyboard_flags = mods;
	if (win->keyboard_cb)
		win->keyboard_cb(win);
}

const char* key_to_str(struct window* w){
	return glfwGetKeyName(w->input->keyboard_keycode, 
			w->input->keyboard_keycode);
}
