#include <stdexcept>
#include "Allocator.h"



template<class T>
T* Allocator<T>::
allocate(size_t N){
    T* mas=(T*)(malloc(N*sizeof(T)));
    if (!mas){printf("No memory in allocate!\n"); throw std::out_of_range("No memory in allocate!\n");}
    return mas;
}
    
template<class T>
void Allocator<T>::
deallocate(T* mas, size_t N){
    free(mas);
}
    


