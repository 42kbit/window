#include <internal/glfw_window.h>
#include <GLFW/glfw3.h>
struct mouse{
	double mpos[2];
	int entered;
	int button;
	int action;
	int flags;
};

static struct mouse mouse;

void set_mouse_cb_pos(struct window* win, mse_cb c){
	win->mpos_cb = c;
}
void set_mouse_cb_enter(struct window* win, mse_cb c){
	win->menter_cb = c;
}
void set_mouse_cb_button(struct window* win, mse_cb c){
	win->mbutton_cb = c;
}
void mouse_pos(struct mouse* mouse, double* d){
	d[0] = mouse->mpos[0];
	d[1] = mouse->mpos[1];
}
int mouse_entered(struct mouse* mouse){
	return mouse->entered;
}
int mouse_button(struct mouse* mouse){
	return mouse->button;
}
int mouse_action(struct mouse* mouse){
	return mouse->action;
}
int mouse_flags(struct mouse* mouse){
	return mouse->flags;
}
void cursor_position_callback(GLFWwindow* window, 
		double xpos, double ypos)
{
	mouse.mpos[0] = xpos;
	mouse.mpos[1] = ypos;
	struct window* win = from_glfw_win(window);
	if (win && win->mpos_cb)
		win->mpos_cb(win, &mouse);
}
void cursor_enter_callback(GLFWwindow* window, int entered){
	mouse.entered = entered;
	struct window* win = from_glfw_win(window);
	if (win && win->menter_cb)
		win->menter_cb(win, &mouse);
}
void mouse_button_callback(GLFWwindow* window, int button, 
		int action, int mods)
{
	mouse.button = button;
	mouse.action = action;
	mouse.flags = mods;
	struct window* win = from_glfw_win(window);
	if (win && win->mbutton_cb)
		win->mbutton_cb(win, &mouse);
}
