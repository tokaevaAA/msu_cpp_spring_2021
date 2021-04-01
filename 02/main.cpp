#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include "Parser.h"


void my_func_for_begin(){
  printf("Hello from my_register_for_begin_work\n");

}

void my_func_for_end(){
  printf ("Hello from my_register_for_end_work\n");
}

void my_func_for_ints(int num){
  printf("We have int: %d\n", num);
}

void my_func_for_strings(const char *tek_word){
    printf("We have string: %s\n", tek_word);
}

void Test1(){
    printf("Test1: no handlers, but right parsing;\n");
    Parser my_instance_of_parser;
    my_instance_of_parser.parse("abc 123a 123 a123");
    int cnt1=my_instance_of_parser.get_cnt_ints();
    int cnt2=my_instance_of_parser.get_cnt_strings();
    assert(cnt1==1);
    assert(cnt2==3);
}

void Test2(){
    printf("Test2: we have handler for end work;\n");
    Parser my_instance_of_parser;
    my_instance_of_parser.register_my_handler_for_end_work(my_func_for_end);
    my_instance_of_parser.parse("abc 123a 123 a123");
    int cnt1=my_instance_of_parser.get_cnt_ints();
    int cnt2=my_instance_of_parser.get_cnt_strings();
    assert(cnt1==1);
    assert(cnt2==3);
}

void Test3(){
    printf("Test3: we have all handlers;\n");
    Parser my_instance_of_parser;
    my_instance_of_parser.register_my_handler_for_begin_work(my_func_for_begin);
    my_instance_of_parser.register_my_handler_for_end_work(my_func_for_end);
    my_instance_of_parser.register_my_handler_for_ints(my_func_for_ints);
    my_instance_of_parser.register_my_handler_for_strings(my_func_for_strings);
    my_instance_of_parser.parse("abc 123a 123 a123");
    int cnt1=my_instance_of_parser.get_cnt_ints();
    int cnt2=my_instance_of_parser.get_cnt_strings();
    assert(cnt1==1);
    assert(cnt2==3);
}

int main(void){
    printf("Hello!\n");
    
    Test1();
    Test2();
    Test3();
    
    printf("Goodbye!\n");
    return 0;
}
