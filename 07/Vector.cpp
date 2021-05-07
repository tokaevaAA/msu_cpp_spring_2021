#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <iterator>
#include <initializer_list>
#include "Vector.h"
#include "Allocator.h"
#include "Iterator.h"



template<class T, class Alloc >
Vector<T, Alloc>::
Vector(size_t N):my_size(0),my_capacity(N),my_allocator(){
        my_mas=my_allocator.allocate(my_capacity);
        
    }
    
template<class T, class Alloc>
Vector<T, Alloc>::
Vector(std::initializer_list<T> init):my_size(0),my_capacity(2*init.size()),my_allocator(){
        my_mas=my_allocator.allocate(my_capacity);
        auto curr = init.begin();
        const auto end = init.end();
        while(curr!=end){
            (*this).push_back(*curr);
            curr++;
        }
    }
    
template<class T, class Alloc>
Vector<T, Alloc>::
~Vector(){
        if (my_mas){
            my_allocator.deallocate(my_mas,my_capacity);
        }
    }
    
template<class T, class Alloc>
T& Vector<T, Alloc>::
operator[](size_t pos){
        if (pos<my_size){
            return my_mas[pos];
        }
        else
            throw std::out_of_range("out of range in operator[]");
    }
    
template<class T, class Alloc>
void Vector<T, Alloc>::
push_back(const T& elem){
        if (my_size>=my_capacity){
            (*this).reserve(2*my_capacity);
        }
        my_mas[my_size]=elem;
        my_size+=1;
        
    }
    
template<class T, class Alloc>
const T& Vector<T, Alloc>::
pop_back(){
        if (my_size==0){throw std::out_of_range("out of range in pop_back");}
        my_size-=1;
        return my_mas[my_size];
    }
    
    
template<class T, class Alloc>
void Vector<T, Alloc>::
reserve(size_t new_size){
        if (new_size > my_capacity){
            T* new_mas=(T*)(new_size*sizeof(T));
            for (size_t i=0; i<my_size; i=i+1){
                new_mas[i]=my_mas[i];
            }
            my_allocator.deallocate(my_mas,my_capacity);
            my_capacity=2*my_capacity;
            my_mas=new_mas;
        }
    }
   
template<class T, class Alloc>
void Vector<T, Alloc>::
resize(size_t new_size){
        if (new_size<my_size){my_size=new_size;}
        else if (new_size > my_size){
            (*this).reserve(new_size);
        }
        
    }
    
template<class T, class Alloc>
Iterator<T> Vector<T, Alloc>::
begin(){
        return Iterator<T>(my_mas);
    }

template<class T, class Alloc>
Iterator<T> Vector<T, Alloc>::
end(){
        return Iterator<T>(my_mas + my_size);
    }

template<class T, class Alloc>
std::reverse_iterator<Iterator<T>> Vector<T, Alloc>::
rbegin(){
        return std::reverse_iterator<Iterator<T>>(Iterator<T>(my_mas+my_size-1));
    }

template<class T, class Alloc>
std::reverse_iterator<Iterator<T>> Vector<T, Alloc>::
rend(){
        return std::reverse_iterator<Iterator<T>>(Iterator<T>(my_mas-1));
    }
    
template<class T, class Alloc>
size_t Vector<T, Alloc>::
size(){
        return my_size;
    }
    
template<class T, class Alloc>
size_t Vector<T, Alloc>::
capacity(){
        return my_capacity;
    }
    
template<class T, class Alloc>
bool Vector<T, Alloc>::
empty(){
        return (my_size!=0);
    }
    
template<class T, class Alloc>
void Vector<T, Alloc>::
clear(){
        my_size=0;
    }
    
template<class T, class Alloc>
void Vector<T, Alloc>::
pechat_int(){
        printf("Pechat: ");
        for (size_t i=0; i<my_size; i=i+1){
            printf("%d ",my_mas[i]);
        }
        printf("\n");
    }


