#ifndef _H_GLFW_CALLBACKS_H
#define _H_GLFW_CALLBACKS_H

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
		int action, int mods);
void character_callback(GLFWwindow* window, unsigned int codepoint);

static inline void init_glfw_callbacks(GLFWwindow* glfw_win){
	glfwSetKeyCallback(glfw_win, glfw_key_callback);
	glfwSetMouseButtonCallback(glfw_win, mouse_button_callback);
	glfwSetCursorPosCallback(glfw_win, cursor_position_callback);
	glfwSetCursorEnterCallback(glfw_win, cursor_enter_callback);
	glfwSetCharCallback(glfw_win, character_callback);
}

#endif /* _H_GLFW_CALLBACKS_H */
