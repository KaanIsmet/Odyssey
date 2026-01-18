#include "VertexBuffer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

VertexBuffer::VertexBuffer(const void* data, size_t size) {
    glGenBuffers(1, &ID);
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &ID);
}

void VertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VertexBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}