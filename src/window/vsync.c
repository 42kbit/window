#include <internal/glfw_window.h>
static int vsync_state;
int vsync_get(){
	return vsync_state;
}
void vsync_set(int value){
	vsync_state = value?1:0;
	glfwSwapInterval(vsync_state);
}
