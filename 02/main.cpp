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

void my_func_for_ints(uint64_t num){
  printf("We have int: %llu\n", num);
}

void my_func_for_strings(const char *tek_word){
    printf("We have string: %s\n", tek_word);
}

void Test1_EmptyString(){
    printf("Test1: empty string;\n");
    std::vector<std::string> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("");
    assert(otv.size()==0);
}

void Test2_TooBigInt(){
    printf("Test2: too big int;\n");
    std::vector<std::string> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("18446744073709551619");
    assert(otv.size()==1);
    assert(otv[0]=="too_big_int");
}

void Test3_SeveralInts(){
    printf("Test3: several ints;\n");
    std::vector<std::string> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("18 446 744 ");
    assert(otv.size()==3);
    assert(otv[0]=="int");
    assert(otv[1]=="int");
    assert(otv[2]=="int");
}

void Test4_SpacesOnly(){
    printf("Test4: spaces only;\n");
    std::vector<std::string> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("      ");
    assert(otv.size()==0);
}

void Test5_1(){
    printf("Test5: 1;\n");
    std::vector<std::string> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("1");
    assert(otv.size()==1);
    assert(otv[0]=="int");
}


void Test6_a(){
    printf("Test6: a;\n");
    std::vector<std::string> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("a");
    assert(otv.size()==1);
    assert(otv[0]=="string");
}

void Test7_AtEnds(){
    printf("Test7: atEnds;\n");
    std::vector<std::string> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("  a a12  123 12a  ");
    assert(otv.size()==4);
    assert(otv[0]=="string");
    assert(otv[1]=="string");
    assert(otv[2]=="int");
    assert(otv[3]=="string");
}

void Test8_EndWorkHandler(){
    printf("Test8: we have handler for end work;\n");
    std::vector<std::string> otv;
    Parser my_instance_of_parser;
    my_instance_of_parser.register_my_handler_for_end_work(my_func_for_end);
    otv=my_instance_of_parser.parse("abc 123 123a a123");
    assert(otv.size()==4);
    assert(otv[0]=="string");
    assert(otv[1]=="int");
    assert(otv[2]=="string");
    assert(otv[3]=="string");
    
}

void Test9_AllHandlers(){
    printf("Test9: we have all handlers;\n");
    std::vector<std::string> otv;
    Parser my_instance_of_parser;
    my_instance_of_parser.register_my_handler_for_begin_work(my_func_for_begin);
    my_instance_of_parser.register_my_handler_for_end_work(my_func_for_end);
    my_instance_of_parser.register_my_handler_for_ints(my_func_for_ints);
    my_instance_of_parser.register_my_handler_for_strings(my_func_for_strings);
    otv=my_instance_of_parser.parse("abc 123 123a a123");
    assert(otv.size()==4);
    assert(otv[0]=="string");
    assert(otv[1]=="int");
    assert(otv[2]=="string");
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
    Test8_EndWorkHandler();
    Test9_AllHandlers();
    
    
    
    printf("Goodbye!\n");
    return 0;
}
