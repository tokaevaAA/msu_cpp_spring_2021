#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include "Parser.h"




void Test1_EmptyString(){
    printf("Test1: empty string;\n");
    
    std::vector<uint64_t> vectInts;
    std::vector<std::string> vectStrings;
    
    std::function<void(uint64_t)>
    my_func_for_ints=[&vectInts](uint64_t num){
        printf("We have int:%llu\n", num);
        vectInts.push_back(num);
    };

    std::function<void(const char *)>
    my_func_for_strings=[&vectStrings](const char *tek_word){
        printf("We have string:%s\n", tek_word);
        vectStrings.push_back(tek_word);
    };

    Parser my_instance_of_parser;
    my_instance_of_parser.register_my_handler_for_ints(my_func_for_ints);
    my_instance_of_parser.register_my_handler_for_strings(my_func_for_strings);
    my_instance_of_parser.parse("");
    assert(vectInts.size()==0);
    assert(vectStrings.size()==0);
    printf("\n");
    
}

void Test2_TooBigInt(){
    printf("Test2: too big int;\n");
    
    std::vector<uint64_t> vectInts;
    std::vector<std::string> vectStrings;
    
    std::function<void(uint64_t)>
    my_func_for_ints=[&vectInts](uint64_t num){
        printf("We have int:%llu\n", num);
        vectInts.push_back(num);
    };

    std::function<void(const char *)>
    my_func_for_strings=[&vectStrings](const char *tek_word){
        printf("We have string:%s\n", tek_word);
        vectStrings.push_back(tek_word);
    };

    Parser my_instance_of_parser;
    my_instance_of_parser.register_my_handler_for_ints(my_func_for_ints);
    my_instance_of_parser.register_my_handler_for_strings(my_func_for_strings);
    
    my_instance_of_parser.parse("18446744073709551615");
    assert(vectInts.size()==1);
    assert(vectStrings.size()==0);
    assert(vectInts[0]==18446744073709551615uLL);
    
    vectInts.clear();
    vectStrings.clear();
    my_instance_of_parser.parse("18446744073709551616");
    assert(vectInts.size()==0);
    assert(vectStrings.size()==1);
    assert(strcmp(vectStrings[0].c_str(),"18446744073709551616")==0);
    printf("\n");
    
}




void Test3_SeveralInts(){
    printf("Test3: several ints;\n");
   
    std::vector<uint64_t> vectInts;
    std::vector<std::string> vectStrings;
    
    std::function<void(uint64_t)>
    my_func_for_ints=[&vectInts](uint64_t num){
        printf("We have int:%llu\n", num);
        vectInts.push_back(num);
    };

    std::function<void(const char *)>
    my_func_for_strings=[&vectStrings](const char *tek_word){
        printf("We have string:%s\n", tek_word);
        vectStrings.push_back(tek_word);
    };
    
    Parser my_instance_of_parser;
    my_instance_of_parser.register_my_handler_for_ints(my_func_for_ints);
    my_instance_of_parser.register_my_handler_for_strings(my_func_for_strings);
    my_instance_of_parser.parse("18 446 744 ");
    
    assert(vectInts.size()==3);
    assert(vectInts[0]==18);
    assert(vectInts[1]==446);
    assert(vectInts[2]==744);
    printf("\n");
}


void Test4_SpacesOnly(){
    printf("Test4: spaces only;\n");
    
    std::vector<uint64_t> vectInts;
    std::vector<std::string> vectStrings;
    
    std::function<void(uint64_t)>
    my_func_for_ints=[&vectInts](uint64_t num){
        printf("We have int:%llu\n", num);
        vectInts.push_back(num);
    };

    std::function<void(const char *)>
    my_func_for_strings=[&vectStrings](const char *tek_word){
        printf("We have string:%s\n", tek_word);
        vectStrings.push_back(tek_word);
    };
    
    Parser my_instance_of_parser;
    my_instance_of_parser.register_my_handler_for_ints(my_func_for_ints);
    my_instance_of_parser.register_my_handler_for_strings(my_func_for_strings);
    my_instance_of_parser.parse("      ");
    assert(vectInts.size()==0);
    assert(vectStrings.size()==0);
    printf("\n");
    
}

void Test5_1(){
    printf("Test5: 1;\n");
    std::vector<uint64_t> vectInts;
    std::vector<std::string> vectStrings;
    
    std::function<void(uint64_t)>
    my_func_for_ints=[&vectInts](uint64_t num){
        printf("We have int:%llu\n", num);
        vectInts.push_back(num);
    };

    std::function<void(const char *)>
    my_func_for_strings=[&vectStrings](const char *tek_word){
        printf("We have string:%s\n", tek_word);
        vectStrings.push_back(tek_word);
    };
    
    Parser my_instance_of_parser;
    my_instance_of_parser.register_my_handler_for_ints(my_func_for_ints);
    my_instance_of_parser.register_my_handler_for_strings(my_func_for_strings);
    
    my_instance_of_parser.parse("1");
    assert(vectInts.size()==1);
    assert(vectStrings.size()==0);
    assert(vectInts[0]==1);
    printf("\n");
}


void Test6_a(){
    printf("Test6: a;\n");
    
    std::vector<uint64_t> vectInts;
    std::vector<std::string> vectStrings;
    
    std::function<void(uint64_t)>
    my_func_for_ints=[&vectInts](uint64_t num){
        printf("We have int:%llu\n", num);
        vectInts.push_back(num);
    };

    std::function<void(const char *)>
    my_func_for_strings=[&vectStrings](const char *tek_word){
        printf("We have string:%s\n", tek_word);
        vectStrings.push_back(tek_word);
    };
    
    Parser my_instance_of_parser;
    my_instance_of_parser.register_my_handler_for_ints(my_func_for_ints);
    my_instance_of_parser.register_my_handler_for_strings(my_func_for_strings);
    
    my_instance_of_parser.parse("a");
    assert(vectInts.size()==0);
    assert(vectStrings.size()==1);
    assert(strcmp(vectStrings[0].c_str(),"a")==0);
    printf("\n");
}



void Test7_AtEnds(){
    printf("Test7: atEnds;\n");
    
    std::vector<uint64_t> vectInts;
    std::vector<std::string> vectStrings;
    
    std::function<void(uint64_t)>
    my_func_for_ints=[&vectInts](uint64_t num){
        printf("We have int:%llu\n", num);
        vectInts.push_back(num);
    };

    std::function<void(const char *)>
    my_func_for_strings=[&vectStrings](const char *tek_word){
        printf("We have string:%s\n", tek_word);
        vectStrings.push_back(tek_word);
    };
    
    
    Parser my_instance_of_parser;
    my_instance_of_parser.register_my_handler_for_ints(my_func_for_ints);
    my_instance_of_parser.register_my_handler_for_strings(my_func_for_strings);
    my_instance_of_parser.parse("  a a12  123 12a  ");
    assert(vectInts.size()==1);
    assert(vectStrings.size()==3);
    assert(vectInts[0]==123);
    assert(strcmp(vectStrings[0].c_str(),"a")==0);
    assert(strcmp(vectStrings[1].c_str(),"a12")==0);
    assert(strcmp(vectStrings[2].c_str(),"12a")==0);
    printf("\n");
}


void Test8_StrangInt(){
    printf("Test8: strangeInt;\n");

    std::vector<uint64_t> vectInts;
    std::vector<std::string> vectStrings;
    
    std::function<void(uint64_t)>
    my_func_for_ints=[&vectInts](uint64_t num){
        printf("We have int:%llu\n", num);
        vectInts.push_back(num);
    };

    std::function<void(const char *)>
    my_func_for_strings=[&vectStrings](const char *tek_word){
        printf("We have string:%s\n", tek_word);
        vectStrings.push_back(tek_word);
    };
    
    Parser my_instance_of_parser;
    my_instance_of_parser.register_my_handler_for_ints(my_func_for_ints);
    my_instance_of_parser.register_my_handler_for_strings(my_func_for_strings);
    my_instance_of_parser.parse("000123");
    assert(vectInts.size()==1);
    assert(vectStrings.size()==0);
    assert(vectInts[0]==123);
    printf("\n");
    
}

 
void Test9_AllHandlers(){
    printf("Test9: we have all handlers;\n");
    
    std::vector<uint64_t> vectInts;
    std::vector<std::string> vectStrings;
    
    std::function<void(uint64_t)>
    my_func_for_ints=[&vectInts](uint64_t num){
        printf("We have int:%llu\n", num);
        vectInts.push_back(num);
    };

    std::function<void(const char *)>
    my_func_for_strings=[&vectStrings](const char *tek_word){
        printf("We have string:%s\n", tek_word);
        vectStrings.push_back(tek_word);
    };
    
    std::function<void()>my_func_for_begin=[](){
      printf("Hello from my_register_for_begin_work\n");

    };

    std::function<void()> my_func_for_end=[](){
      printf ("Hello from my_register_for_end_work\n");
    };

    
    
    Parser my_instance_of_parser;
    my_instance_of_parser.register_my_handler_for_begin_work(my_func_for_begin);
    my_instance_of_parser.register_my_handler_for_end_work(my_func_for_end);
    my_instance_of_parser.register_my_handler_for_ints(my_func_for_ints);
    my_instance_of_parser.register_my_handler_for_strings(my_func_for_strings);
    my_instance_of_parser.parse("abc 123 ");
    assert(vectInts.size()==1);
    assert(vectStrings.size()==1);
    assert(vectInts[0]==123);
    assert(strcmp(vectStrings[0].c_str(),"abc")==0);
    printf("\n");
    
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
    Test8_StrangInt();
    Test9_AllHandlers();
    
    
    
    printf("Goodbye!\n");
    return 0;
}
