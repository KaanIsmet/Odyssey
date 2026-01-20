#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>
#include <iostream>

using std::string;

class Shader {
private:
    unsigned int ID;
    string vertexPath;
    string fragPath;
    static int shaderCount;


public:
    Shader(string& vertexPath, string& fragPath);
    ~Shader();

    void use();
    string getVertexPath();
    string getFragPath();
    unsigned int getID();
    bool checkCompileErrors(unsigned int shader, string type);
};
#endif