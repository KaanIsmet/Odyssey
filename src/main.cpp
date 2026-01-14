#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

GLFWwindow* createWindow();

int main() {
	std::cout << "Running Odyssey...\n";
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	auto window = createWindow();
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return 0;
}

GLFWwindow* createWindow() {
	GLFWwindow* window = glfwCreateWindow(800, 600, "Odyssey", NULL, NULL);
	if (window == NULL) {
		std::cerr << "Failed to open window\n";
		glfwTerminate();
		return nullptr;
	}

	glfwMakeContextCurrent(window);
	return window;
}
