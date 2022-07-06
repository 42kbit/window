#include <internal/glfw_window.h>
char* get_window_title(struct window* win){
	return NULL;
}
void set_window_title(struct window* win, char* new_name){
	glfwSetWindowTitle(win->glfw_win, new_name);
}
