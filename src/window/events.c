#include <internal/glfw_window.h>
#include <internal/glfw_callbacks.h>
void poll_events(window_t* win){
	glfwPollEvents();
}
void wait_events(window_t*){
	glfwWaitEvents();
}
