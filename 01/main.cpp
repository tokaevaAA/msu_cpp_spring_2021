#include <stdio.h>
#include <stdlib.h>
#include "Allocator.h"
#include <cassert>

void Test0(){
    printf("Test0: check if Allocator can become longer;\n");
    Allocator my_instance_of_allocator;
    char* mas;
    my_instance_of_allocator.makeAllocator(0);
    mas = my_instance_of_allocator.alloc(30);
    assert(mas==nullptr);
    my_instance_of_allocator.makeAllocator(100);
    mas = my_instance_of_allocator.alloc(30);
    assert(mas!=nullptr);
}

void Test1(){
    printf("Test1: maxSize==0, cannot alloc 30, so we accept nullptr;\n");
    Allocator my_instance_of_allocator;
    char* mas;
    my_instance_of_allocator.makeAllocator(0);
    mas = my_instance_of_allocator.alloc(30);
    assert(mas==nullptr);
}

void Test2(){
    printf("Test2: maxSize==100, can alloc 30 and can use it;\n");
    Allocator my_instance_of_allocator;
    char* mas;
    my_instance_of_allocator.makeAllocator(100);
    mas = my_instance_of_allocator.alloc(30);
    assert(mas!=nullptr);
}

void Test3(){
    printf("Test3: maxSize==100, 30 is already filled, so cannot alloc 80 more, so we accept nullptr;\n");
    Allocator my_instance_of_allocator;
    char* mas;
    my_instance_of_allocator.makeAllocator(100);
    mas = my_instance_of_allocator.alloc(30);
    mas = my_instance_of_allocator.alloc(80);
    assert(mas==nullptr);
}

void Test4(){
    printf("Test4: maxSize==100, then 30 is filled, then maxSize==130, 30 is already filled, so can alloc 80 more and can use it;\n");
    Allocator my_instance_of_allocator;
    char* mas;
    my_instance_of_allocator.makeAllocator(100);
    mas = my_instance_of_allocator.alloc(30);
    my_instance_of_allocator.makeAllocator(130);
    mas = my_instance_of_allocator.alloc(80);
    assert(mas!=nullptr);
}

void Test5(){
    printf("Test5: maxSize==130, 110 is already filled, we reset it, so we can alloc 130 more and use it;\n");
    Allocator my_instance_of_allocator;
    char* mas;
    my_instance_of_allocator.makeAllocator(100);
    mas = my_instance_of_allocator.alloc(30);
    my_instance_of_allocator.makeAllocator(130);
    mas = my_instance_of_allocator.alloc(80);
    my_instance_of_allocator.reset();
    mas = my_instance_of_allocator.alloc(130);
    assert(mas!=nullptr);
}

int main(void) {

  printf("Hello!\n");
 
  Test0();
  Test1();
  Test2();
  Test3();
  Test4();
  Test5();

  printf("Success!\n");
  printf("Goodbuy!\n");
  return 0;
}
