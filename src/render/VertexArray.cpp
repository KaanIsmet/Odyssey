#include "VertexArray.h"
#include <cstddef>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

VertexArray::VertexArray(const void* data, size_t size) {
    glGenVertexArrays(1, &ID);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &ID);
}

void VertexArray::bind() const {
    glBindVertexArray(ID);
}

void VertexArray::unbind() const {
    glBindVertexArray(0);
}