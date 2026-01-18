#include "VertexBuffer.h"
#include <vector>
#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

class VertexArray {
private:
    unsigned int ID;

public:
    VertexArray(const void* data, size_t size);
    void addBuffer(const VertexBuffer& vb, const std::vector<unsigned int>& layout);
    ~VertexArray();
    void bind() const;
    void unbind() const;
};

#endif