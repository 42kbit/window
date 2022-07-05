#include <internal/glfw_window.h>

struct key{
	int keycode;
	int action;
	int flags;
};
/* parse glfw keycodes, to our keycodes */
int key_keycode(struct key* k){
	return k->keycode;
}
int key_action(struct key* k){
	return k->action;
}
int key_flags(struct key* k){
	return k->flags;
}

void set_key_cb(window_t* win, key_cb newcb){
	win->key_cb = newcb;
}

struct key key;

void glfw_key_callback(
		GLFWwindow* window,
		int keycode,
		int scancode,
		int action,
		int mods)
{
	key.keycode = keycode;
	key.action = action;
	key.flags = mods;
	struct window* win = from_glfw_win(window);
	if (win->key_cb)
		win->key_cb(win, &key);
}

const char* key_to_str(struct key*){
	return glfwGetKeyName(key.keycode, key.keycode);
}
