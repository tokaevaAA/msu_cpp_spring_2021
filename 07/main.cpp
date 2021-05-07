#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <algorithm>
#include "Vector.cpp"
#include "Allocator.cpp"
#include "Iterator.cpp"



void Test1_push_back_pop_back(){
    printf("Tes1: push_back_pop_back\n");
    Vector<int, Allocator<int>> vect(5);
    vect.push_back(7);
    vect.push_back(8);
    
    size_t cap=vect.capacity();
    size_t sz=vect.size();
    printf("capacity=%lu\n",cap);
    printf("size=%lu\n",sz);
    assert(cap==5);
    assert(sz==2);
    vect.pechat_int();
    
    int a=vect.pop_back();
    printf("a=%d\n",a);
    assert(a==8);
    sz=vect.size();
    printf("size=%lu\n",sz);
    assert(sz==1);
    vect.pechat_int();
    printf("\n");
}

void Test2_initializer_list(){
    printf("Tes2: initializer_list\n");
    Vector<int, Allocator<int>> vect = {1,2,3,4,5,6,7,8,9};
    size_t cap=vect.capacity();
    size_t sz=vect.size();
    printf("capacity=%lu\n",cap);
    printf("size=%lu\n",sz);
    assert(cap==18);
    assert(sz==9);
    vect.pechat_int();
    printf("\n");
}

void Test3_iterator_for_each(){
    printf("Tes3: iterator for each\n");
    Vector<int> vect = {1,2,3,4,5,6,7,8,9};
        std::for_each(vect.begin(), vect.end(), [](int x) { printf("x=%d ",x); });
    printf("\n");
    printf("\n");
}

void Test4_iterator(){
    printf("Tes4: iterator\n");
    Vector<int> vect = {1,2,3,4,5,6,7,8,9};
    auto tek = vect.begin();
    auto stop= vect.end();
    while(tek!=stop){
        printf("el=%d ",*tek);
        tek++;
    }
    printf("\n");
    printf("\n");
}

void Test5_iterator_reverse(){
    printf("Tes5: iterator_reverse\n");
    Vector<int> vect = {1,2,3,4,5,6,7,8,9};
    auto tek = vect.end()-1;
    auto stop= vect.begin()-1;
    while(tek!=stop){
        printf("el=%d ",*tek);
        tek--;
    }
    printf("\n");
    printf("\n");
}

int main(void){
    printf("Hello!\n");
    
    Test1_push_back_pop_back();
    Test2_initializer_list();
    Test3_iterator_for_each();
    Test4_iterator();
    Test5_iterator_reverse();
    
    
    printf("Goodbuy!\n");
}
