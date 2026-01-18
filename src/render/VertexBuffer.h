#include <cstddef>
#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

class VertexBuffer {
private:
    unsigned int ID;
    
public:
    VertexBuffer(const void* data, size_t size);
    ~VertexBuffer();
    void bind() const;
    void unbind() const;
};

#endif