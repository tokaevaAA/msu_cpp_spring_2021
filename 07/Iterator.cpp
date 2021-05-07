#include <stdio.h>
#include <stdlib.h>
#include "Iterator.h"



template<class T>
Iterator<T>::
Iterator(T* given):tek(given){}


template<class T>
T& Iterator<T>::
operator*() const{
    return *tek;
}


template<class T>
Iterator<T>& Iterator<T>::
operator++(){
    ++tek;
    return *this;
}

template<class T>
Iterator<T> Iterator<T>::
operator++(int){
    auto old = *this;
    (*this).operator++();
    return old;
}


template<class T>
Iterator<T>& Iterator<T>::
operator--(){
    --tek;
    return *this;
}

template<class T>
Iterator<T> Iterator<T>::
operator--(int){
    auto old = *this;
    (*this).operator--();
    return old;
}

template<class T>
Iterator<T> Iterator<T>::
operator-(size_t n) const{
        return Iterator(tek - n);
}

template<class T>
bool Iterator<T>::
operator==(const Iterator<T>& other)const{
    return tek == other.tek;
}


template<class T>
bool Iterator<T>::
operator!=(const Iterator<T>& other)const{
    return !(*this == other);
}


template<class T>
bool Iterator<T>::
operator<(const Iterator<T>& other)const{
    return ((*this).tek < other.tek);
}


template<class T>
bool Iterator<T>::
operator>(const Iterator<T>& other)const{
    return (*this).tek > other.tek;
}


template<class T>
bool Iterator<T>::
operator>=(const Iterator<T>& other)const{
    return (*this).tek >= other.tek;
}


template<class T>
bool Iterator<T>::
operator<=(const Iterator<T>& other)const{
    return (*this).tek <= other.tek ;
}
