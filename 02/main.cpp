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

void Test1_EmptyString(){
    std::vector<std::string> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("");
    assert(otv.size()==0);
}

void Test2_TooBigInt(){
    std::vector<std::string> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("18446744073709551619");
    assert(otv.size()==1);
    assert(otv[0]=="too_big_int");
}

void Test3_SeveralInts(){
    std::vector<std::string> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("18 446 744 ");
    assert(otv.size()==3);
    assert(otv[0]=="int");
    assert(otv[1]=="int");
    assert(otv[2]=="int");
}

void Test4_SpacesOnly(){
    std::vector<std::string> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("      ");
    assert(otv.size()==0);
}

void Test5_1(){
    std::vector<std::string> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("1");
    assert(otv.size()==1);
    assert(otv[0]=="int");
}


void Test6_a(){
    std::vector<std::string> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("a");
    assert(otv.size()==1);
    assert(otv[0]=="string");
}

void Test7_AtEnds(){
    std::vector<std::string> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("  a a12  123 12a  ");
    assert(otv.size()==4);
    assert(otv[0]=="string");
    assert(otv[1]=="string");
    assert(otv[2]=="int");
    assert(otv[3]=="string");
}


int main(void){
    printf("Hello!\n");
    
    Test1_EmptyString();
    Test2_TooBigInt();
    Test3_SeveralInts();
    Test4_SpacesOnly();
    Test5_1();
    Test6_a();
    Test7_AtEnds();
    
    
    
    printf("Goodbye!\n");
    return 0;
}
