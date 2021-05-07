#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <iterator>
#include <initializer_list>
#include "Allocator.h"
#include "Iterator.h"


template<class T, class Alloc = Allocator<T>>
class Vector{
private:
    size_t my_size;
    size_t my_capacity;
    T* my_mas;
    Alloc my_allocator;
public:
    Vector(size_t N=0);
    Vector(std::initializer_list<T> init);
    ~Vector();
    T& operator[](size_t pos);
    void push_back(const T& elem);
    
    template<class... Args>
    void emplace_back(Args... args){
        (*this).push_back(T(std::forward<Args>(args)...));
    }
    
    const T& pop_back();
    void reserve(size_t new_size);
    void resize(size_t new_size);
    Iterator<T> begin();
    Iterator<T> end();
    std::reverse_iterator<Iterator<T>> rbegin();
    std::reverse_iterator<Iterator<T>> rend();
    size_t size();
    size_t capacity();
    bool empty();
    void clear();
    void pechat_int();
};

