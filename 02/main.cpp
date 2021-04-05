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
    std::tuple<std::vector<std::string>,std::vector<std::string>> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("");
    assert((std::get<0>(otv)).size()==0);
    
}

void Test2_TooBigInt(){
    printf("Test2: too big int;\n");
    std::tuple<std::vector<std::string>,std::vector<std::string>> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("18446744073709551619");
    assert((std::get<0>(otv)).size()==1);
    assert((std::get<0>(otv))[0]=="too_big_int");
    assert(strcmp( ((std::get<1>(otv))[0]).c_str(),"18446744073709551619")==0);

}

void Test3_SeveralInts(){
    printf("Test3: several ints;\n");
    std::tuple<std::vector<std::string>,std::vector<std::string>> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("18 446 744 ");
    assert((std::get<0>(otv)).size()==3);
    assert((std::get<0>(otv))[0]=="int");
    assert((std::get<0>(otv))[1]=="int");
    assert((std::get<0>(otv))[2]=="int");
    assert(strcmp( ((std::get<1>(otv))[0]).c_str(),"18")==0);
    assert(strcmp( ((std::get<1>(otv))[1]).c_str(),"446")==0);
    assert(strcmp( ((std::get<1>(otv))[2]).c_str(),"744")==0);

}

void Test4_SpacesOnly(){
    printf("Test4: spaces only;\n");
    std::tuple<std::vector<std::string>,std::vector<std::string>> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("      ");
    assert((std::get<0>(otv)).size()==0);
}

void Test5_1(){
    printf("Test5: 1;\n");
    std::tuple<std::vector<std::string>,std::vector<std::string>> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("1");
    assert((std::get<0>(otv)).size()==1);
    assert((std::get<0>(otv))[0]=="int");
    assert(strcmp( ((std::get<1>(otv))[0]).c_str(),"1")==0);

}


void Test6_a(){
    printf("Test6: a;\n");
    std::tuple<std::vector<std::string>,std::vector<std::string>> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("a");
    assert((std::get<0>(otv)).size()==1);
    assert((std::get<0>(otv))[0]=="string");
    assert(strcmp( ((std::get<1>(otv))[0]).c_str(),"a")==0);

}

void Test7_AtEnds(){
    printf("Test7: atEnds;\n");
    std::tuple<std::vector<std::string>,std::vector<std::string>> otv;
    Parser my_instance_of_parser;
    otv=my_instance_of_parser.parse("  a a12  123 12a  ");
    assert((std::get<0>(otv)).size()==4);
    assert((std::get<0>(otv))[0]=="string");
    assert((std::get<0>(otv))[1]=="string");
    assert((std::get<0>(otv))[2]=="int");
    assert((std::get<0>(otv))[3]=="string");
    assert(strcmp( ((std::get<1>(otv))[0]).c_str(),"a")==0);
    assert(strcmp( ((std::get<1>(otv))[1]).c_str(),"a12")==0);
    assert(strcmp( ((std::get<1>(otv))[2]).c_str(),"123")==0);
    assert(strcmp( ((std::get<1>(otv))[3]).c_str(),"12a")==0);

}

void Test8_EndWorkHandler(){
    printf("Test8: we have handler for end work;\n");
    std::tuple<std::vector<std::string>,std::vector<std::string>> otv;
    Parser my_instance_of_parser;
    my_instance_of_parser.register_my_handler_for_end_work(my_func_for_end);
    otv=my_instance_of_parser.parse("abc 123 123a a123");
    assert((std::get<0>(otv)).size()==4);
    assert((std::get<0>(otv))[0]=="string");
    assert((std::get<0>(otv))[1]=="int");
    assert((std::get<0>(otv))[2]=="string");
    assert((std::get<0>(otv))[3]=="string");
    assert(strcmp( ((std::get<1>(otv))[0]).c_str(),"abc")==0);
    assert(strcmp( ((std::get<1>(otv))[1]).c_str(),"123")==0);
    assert(strcmp( ((std::get<1>(otv))[2]).c_str(),"123a")==0);
    assert(strcmp( ((std::get<1>(otv))[3]).c_str(),"a123")==0);

    
}

void Test9_AllHandlers(){
    printf("Test9: we have all handlers;\n");
    std::tuple<std::vector<std::string>,std::vector<std::string>> otv;
    Parser my_instance_of_parser;
    my_instance_of_parser.register_my_handler_for_begin_work(my_func_for_begin);
    my_instance_of_parser.register_my_handler_for_end_work(my_func_for_end);
    my_instance_of_parser.register_my_handler_for_ints(my_func_for_ints);
    my_instance_of_parser.register_my_handler_for_strings(my_func_for_strings);
    otv=my_instance_of_parser.parse("abc 123 123a a123");
    assert((std::get<0>(otv)).size()==4);
    assert((std::get<0>(otv))[0]=="string");
    assert((std::get<0>(otv))[1]=="int");
    assert((std::get<0>(otv))[2]=="string");
    assert((std::get<0>(otv))[3]=="string");
    assert(strcmp( ((std::get<1>(otv))[0]).c_str(),"abc")==0);
    assert(strcmp( ((std::get<1>(otv))[1]).c_str(),"123")==0);
    assert(strcmp( ((std::get<1>(otv))[2]).c_str(),"123a")==0);
    assert(strcmp( ((std::get<1>(otv))[3]).c_str(),"a123")==0);

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
