#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void process_input(GLFWwindow* window);

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;


int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//- GLFW window creation
	//----------------------
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL_Project", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//- Init GLAD
	//-----------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {

		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//- Render loop
	//-------------
	while (!glfwWindowShouldClose(window)) {

		//input
		process_input(window);

		//commands
		glClearColor(0.3f, 0.4f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//events and buffers swap
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
//=== End of main() ===


//=========================================


//- Function to reset the viewport on window resizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

//- Function to process input
void process_input(GLFWwindow* window) {
	if ( glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS ) {
		glfwSetWindowShouldClose(window, true);
	}
}
