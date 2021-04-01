#include <stdio.h>
#include <stdlib.h>
#include "Allocator.h"
#include <cassert>


void Test1(){
    printf("Test1: what if alloc is called before makeAllocator;\n");
    Allocator my_instance_of_allocator;
    char* mas;
    mas = my_instance_of_allocator.alloc(10);
    assert(mas == nullptr);
}

void Test2(){
    printf("Test2: fully filled then reseted;\n");
    Allocator my_instance_of_allocator;
    char* mas;
    my_instance_of_allocator.makeAllocator(10);
    mas = my_instance_of_allocator.alloc(10);
    assert(mas != nullptr);
    mas = my_instance_of_allocator.alloc(1);
    assert(mas == nullptr);
    my_instance_of_allocator.reset();
    mas = my_instance_of_allocator.alloc(10);
    assert(mas != nullptr);
}


void Test3(){
    printf("Test3: check if Allocator can become longer using makeAllocator;\n");
    Allocator my_instance_of_allocator;
    char* mas;
    my_instance_of_allocator.makeAllocator(0);
    mas = my_instance_of_allocator.alloc(30);
    assert(mas == nullptr);
    my_instance_of_allocator.makeAllocator(100);
    mas = my_instance_of_allocator.alloc(30);
    assert(mas != nullptr);
}


int main(void) {

  printf("Hello!\n");
 

  Test1();
  Test2();
  Test3();

  printf("Success!\n");
  printf("Goodbuy!\n");
  return 0;
}
