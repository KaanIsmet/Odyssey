#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "render/VertexArray.h"
#include "render/VertexBuffer.h"
#include "render/Shader.h"

GLFWwindow* createWindow();
void run(std::string vP, std::string fP, float vertices[], size_t size, GLFWwindow* window);

int main() {
	std::string vertexPath = "assets/shaders/basic.vert";
	std::string fragPath = "assets/shaders/basic.frag";
	std::cout << "Running Odyssey...\n";
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	std::cerr << "Creating window...\n";
	auto window = createWindow();
	if (window == nullptr) {
		std::cerr << "Failed to create window" << std::endl;
		return -1;
	}
	std::cerr << "Window created successfully.\n";
	
	std::cerr << "Initializing GLAD...\n";
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
	glViewport(0, 0, 800, 600);
	std::cerr << "GLAD initialized successfully.\n";
	float vertices[] = {
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, //bottom right
		 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, //bottom left
		 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f //top
	};

	run(vertexPath, fragPath, vertices, sizeof(vertices), window);
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

void run(std::string vertexPath, std::string fragPath, float vertices[], size_t size, GLFWwindow* window) {
	std::cout << "Creating VertexArray...\n";
		VertexArray vao;
		std::cout << "Creating VertexBuffer...\n";
		VertexBuffer vbo(vertices, size);
		std::cout << "Creating Shader...\n";
		Shader shader(vertexPath, fragPath);
		std::cout << "Initialization complete.\n";

		glBindVertexArray(vao.getID());
		vbo.bind();

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);


		while (!glfwWindowShouldClose(window)) {
			glClearColor(1.0f, 1.0f, 0.7f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glUseProgram(shader.getID());
			glBindVertexArray(vao.getID());
			glDrawArrays(GL_TRIANGLES, 0, 3);

			
			glfwPollEvents();
			glfwSwapBuffers(window);
		}
		// OpenGL objects (shader, vbo, vao) are automatically destroyed here
		// while the OpenGL context is still valid
}


