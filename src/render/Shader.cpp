#include "Shader.h"

Shader::Shader(std::string& vertexPath, std::string& fragPath) {
    std::ifstream vertexFile{vertexPath};
    if (!vertexFile) {
        std::cerr << "Unable to get file";
        throw std::runtime_error("Unable to open vertex shader: " + vertexPath);
    }
    std::ifstream fragFile{fragPath};
    if (!fragFile) {
        std::cerr << "Unable to get file";
        throw std::runtime_error("Unable to open fragment shader: " + vertexPath);
    }
    
    std::string vertexSource = readFile(vertexFile);
    std::string fragSource = readFile(fragFile);
    unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexSource);
    unsigned int fragShader = compileShader(GL_FRAGMENT_SHADER, fragSource);
    ID = glCreateProgram();

    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragShader);
    glLinkProgram(ID);

    if (!programSuccessful(ID)) {
        char infoLog[512];
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        throw std::runtime_error("Shader linking failed: " + std::string(infoLog));
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);
}
string Shader::getFragPath() {
    return fragPath;
}

string Shader::getVertexPath() {
    return vertexPath;
}


unsigned int compileShader(unsigned int shaderType, const std::string& shaderSource) {
	unsigned int shader = glCreateShader(shaderType);
    const char* source = shaderSource.c_str();
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);
	
	if (!shaderSuccessful(shader)) {
			std::cerr << "Exiting applicaiton...\n";
			glDeleteShader(shader);
			return -1;
	}

	return shader;
}


bool shaderSuccessful(unsigned int shader) {
	int success, length = 512;
	char infoLog[length];

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	
	if (!success) {
		glGetShaderInfoLog(shader, length, NULL, infoLog);
		std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n"
			  << infoLog << std::endl;
		return false;
	}

	return true;
}

bool programSuccessful(unsigned int program) {
	int success, length = 512;
	char infoLog[length];

	glGetProgramiv(program, GL_LINK_STATUS, &success);

	if (!success) {
		glGetProgramInfoLog(program, length, NULL, infoLog);
		std::cerr << "ERROR::PROGRAM::LINKED_FAILED\n"
			  << infoLog << std::endl;
		return false;
	}

	return true;
}

std::string readFile(std::ifstream& file) {
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}