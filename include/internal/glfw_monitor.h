#include <GLFW/glfw3.h>
struct monitor{
	GLFWmonitor* glfw_monitor;
};
typedef struct monitor monitor_t;

static inline GLFWmonitor* __get_glfw_monitor(struct monitor* m){
	if (!m)
		return NULL;
	return m->glfw_monitor;
}
