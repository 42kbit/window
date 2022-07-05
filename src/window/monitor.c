#include <internal/glfw_monitor.h>
#include <stdlib.h>

struct monitor* create_monitor(void){
	struct monitor* monitor = (struct monitor*)malloc(
			sizeof(struct monitor));
	monitor->glfw_monitor = glfwGetPrimaryMonitor();
	return monitor;
}
void free_monitor(struct monitor* monitor){
	free(monitor);
}
