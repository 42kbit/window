#include <internal/glfw_window.h>
#include <GLFW/glfw3.h>

void set_mouse_pos_cb(struct window* win, gen_cb c){
	win->mouse_pos_cb = c;
}
void set_mouse_enter_cb(struct window* win, gen_cb c){
	win->mouse_enter_cb = c;
}
void set_mouse_button_cb(struct window* win, gen_cb c){
	win->mouse_button_cb = c;
}
void mouse_pos(struct window* win, double* d){
	d[0] = win->input->mouse_pos[0];
	d[1] = win->input->mouse_pos[1];
}
int mouse_entered(struct window* win){
	return win->input->mouse_entered;
}
int mouse_button(struct window* win){
	return win->input->mouse_button;
}
int mouse_action(struct window* win){
	return win->input->mouse_action;
}
int mouse_flags(struct window* win){
	return win->input->mouse_flags;
}
void cursor_position_callback(GLFWwindow* window, 
		double xpos, double ypos)
{
	struct window* win = from_glfw_win(window);
	if (!win) return;
	win->input->mouse_pos[0] = xpos;
	win->input->mouse_pos[1] = ypos;
	if (win->mouse_pos_cb)
		win->mouse_pos_cb(win);
}
void cursor_enter_callback(GLFWwindow* window, int entered){
	struct window* win = from_glfw_win(window);
	if (!win) return;
	win->input->mouse_entered = entered;
	if (win->mouse_enter_cb)
		win->mouse_enter_cb(win);
}
void mouse_button_callback(GLFWwindow* window, int button, 
		int action, int mods)
{
	struct window* win = from_glfw_win(window);
	if (!win) return;
	win->input->mouse_button = button;
	win->input->mouse_action = action;
	win->input->mouse_flags = mods;
	if (win->mouse_button_cb)
		win->mouse_button_cb(win);
}
