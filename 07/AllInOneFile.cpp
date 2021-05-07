#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <iterator>
#include <initializer_list>


template<class T>
class Allocator{
private:
    
public:
    T* allocate(size_t N){
        T* mas=(T*)(malloc(N*sizeof(T)));
        if (!mas){printf("No memory in allocate!\n"); throw std::out_of_range("No memory in allocate!\n");}
        return mas;
    }
    
    void deallocate(T* mas, size_t N){
        free(mas);
    }
    
};

template<class T>
class Iterator{
    T* tek;
public:
    Iterator(T* given):tek(given){}

    T& operator*() const{
        return *tek;
    }

    Iterator& operator++(){
        ++tek;
        return *this;
    }

    Iterator& operator--(){
        --tek;
        return *this;
    }

    bool operator==(const Iterator<T>& other)const{
        return tek == other.tek;
    }

    bool operator!=(const Iterator<T>& other)const{
        return !(*this == other);
    }

    bool operator<(const Iterator<T>& other)const{
        return ((*this).tek < other.tek);
    }

    bool operator>(const Iterator<T>& other)const{
        return (*this).tek > other.tek;
    }

    bool operator>=(const Iterator<T>& other)const{
        return (*this).tek >= other.tek;
    }

    bool operator<=(const Iterator<T>& other)const{
        return (*this).tek <= other.tek ;
    }
};


template<class T, class Alloc = Allocator<T>>
class Vector{
private:
    size_t my_size;
    size_t my_capacity;
    T* my_mas;
    Alloc my_allocator;
public:
    Vector(size_t N=0):my_size(0),my_capacity(N),my_allocator(){
        my_mas=my_allocator.allocate(my_capacity);
        
    }
    
    Vector(std::initializer_list<T> init):my_size(0),my_capacity(2*init.size()),my_allocator(){
        my_mas=my_allocator.allocate(my_capacity);
        auto curr = init.begin();
        const auto end = init.end();
        while(curr!=end){
            (*this).push_back(*curr);
            curr++;
        }
    }
    
    ~Vector(){
        if (my_mas){
            my_allocator.deallocate(my_mas,my_capacity);
        }
    }
    
    T& operator[](size_t pos){
        if (pos<my_size){
            return my_mas[pos];
        }
        else
            throw std::out_of_range("out of range in operator[]");
    }
    
    void push_back(const T& elem){
        if (my_size>=my_capacity){
            (*this).reserve(2*my_capacity);
        }
        my_mas[my_size]=elem;
        my_size+=1;
        
    }
    
    
    template<class... Args>
    void emplace_back(Args... args){
        (*this).push_back(T(std::forward<Args>(args)...));
    }
    
    
    const T& pop_back(){
        if (my_size==0){throw std::out_of_range("out of range in pop_back");}
        my_size-=1;
        return my_mas[my_size];
    }
    
    
    
    void reserve(size_t new_size){
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
    
    void resize(size_t new_size){
        if (new_size<my_size){my_size=new_size;}
        else if (new_size > my_size){
            (*this).reserve(new_size);
        }
        
    }
    
    
    
    Iterator<T> begin(){
        return Iterator<T>(my_mas);
    }

    Iterator<T> end(){
        return Iterator<T>(my_mas + my_size);
    }

    std::reverse_iterator<Iterator<T>> rbegin(){
        return std::reverse_iterator<Iterator<T>>(Iterator<T>(my_mas+my_size-1));
    }

    std::reverse_iterator<Iterator<T>> rend(){
        return std::reverse_iterator<Iterator<T>>(Iterator<T>(my_mas-1));
    }
    
    size_t size(){
        return my_size;
    }
    
    size_t capacity(){
        return my_capacity;
    }
    
    bool empty(){
        return (my_size!=0);
    }
    
    void clear(){
        my_size=0;
    }
    
    void pechat_int(){
        printf("Pechat: ");
        for (size_t i=0; i<my_size; i=i+1){
            printf("%d ",my_mas[i]);
        }
        printf("\n");
    }
};


int main(void){
    printf("Hello!\n");
    
    
    Vector<int, Allocator<int>> vect1(5);
    vect1.push_back(7);
    vect1.push_back(8);
    printf("capacity=%lu\n",vect1.capacity());
    printf("size=%lu\n",vect1.size());
    vect1.pechat_int();
    
    int a=vect1.pop_back();
    printf("a=%d\n",a);
    printf("size=%lu\n",vect1.size());
    vect1.pechat_int();
    
    
    Vector<int, Allocator<int>> vect2 = {1,2,3,4,5,6,7,8,9};
    printf("capacity=%lu\n",vect2.capacity());
    printf("size=%lu\n",vect2.size());
    vect2.pechat_int();
    
    printf("Goodbuy!\n");
}
