#include <cstddef>
#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H

class IndexBuffer {
private:
    unsigned int ID;

public:
    IndexBuffer(const void* data, size_t size);
    ~IndexBuffer();
    void bind() const;
    void unbing() const;
};

#endif