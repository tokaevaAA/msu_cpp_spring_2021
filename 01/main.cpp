#include<stdio.h>

#include<stdlib.h>

#include"Allocator.h"


int main(void) {

  printf("Hello!\n\n");

  Allocator my_instance_of_allocator;
  char * mas;

  //test1:
  printf("Test1: maxSize==0, cannot alloc 30, so we accept nullptr;\n");
  my_instance_of_allocator.makeAllocator(0);
  mas = my_instance_of_allocator.alloc(30);
  printf("mas=%p\n\n", mas);

  //test2:
  printf("Test2: maxSize==100, can alloc 30 and can use it;\n");
  my_instance_of_allocator.makeAllocator(100);

  mas = my_instance_of_allocator.alloc(30);
  printf("mas=%p\n", mas);
  for (size_t i = 0; i < 30; i = i + 1) {
    mas[i] = 'a';
  }
  for (size_t i = 0; i < 30; i = i + 1) {
    printf("%c", mas[i]);
  }
  printf("\n\n");

  //test3:
  printf("Test3: maxSize==100, 30 is already filled, so cannot alloc 80 more, so we accept nullptr;\n");
  mas = my_instance_of_allocator.alloc(80);
  printf("mas=%p\n\n", mas);

  //test4:
  printf("Test4: maxSize==130, 30 is already filled, so can alloc 80 more and can use it;\n");
  my_instance_of_allocator.makeAllocator(130);
  mas = my_instance_of_allocator.alloc(80);
  printf("mas=%p\n\n", mas);
  for (size_t i = 0; i < 80; i = i + 1) {
    mas[i] = 'b';
  }
  for (size_t i = 0; i < 80; i = i + 1) {
    printf("%c", mas[i]);
  }
  printf("\n\n");

  //test5:
  printf("Test5: maxSize==130, 110 is already filled, we reset it, so we can alloc 130 more and use it;\n");
  my_instance_of_allocator.reset();
  mas = my_instance_of_allocator.alloc(130);
  printf("mas=%p\n\n", mas);
  for (size_t i = 0; i < 130; i = i + 1) {
    mas[i] = 'c';
  }
  for (size_t i = 0; i < 130; i = i + 1) {
    printf("%c", mas[i]);
  }
  printf("\n\n");

  printf("Goodbuy!\n");
  return 0;
}