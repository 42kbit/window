void glfw_key_callback(
		GLFWwindow* window,
		int key,
		int scancode,
		int action,
		int mods);

void cursor_position_callback(GLFWwindow* window, 
		double xpos, double ypos);
void cursor_enter_callback(GLFWwindow* window, int entered);
void mouse_button_callback(GLFWwindow* window, int button, 
		int action, int mods)

static inline void init_glfw_callbacks(GLFWwindow* glfw_win){
	glfwSetKeyCallback(glfw_win, glfw_key_callback);
}
