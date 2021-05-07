#pragma once


template<class T>
class Allocator{
private:
    
public:
    T* allocate(size_t N);
    void deallocate(T* mas, size_t N);
    
};

