#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include "VertexBuffer.h"
#include <vector>

class VertexArray {
private:
    unsigned int ID;

public:
    VertexArray();
    VertexArray(const void* data, size_t size);
    void addBuffer(const VertexBuffer& vb, const std::vector<unsigned int>& layout);
    unsigned int getID();
    ~VertexArray();
    void bind() const;
    void unbind() const;
};

#endif