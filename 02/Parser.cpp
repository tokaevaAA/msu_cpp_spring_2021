#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "Parser.h"


Parser::Parser():
my_handler_for_begin_work(nullptr),
my_handler_for_end_work(nullptr),
my_handler_for_ints(nullptr),
my_handler_for_strings (nullptr){}

void Parser::register_my_handler_for_begin_work(Handler_for_begin_work my_func){
    my_handler_for_begin_work=my_func;}

void Parser::register_my_handler_for_end_work(Handler_for_end_work my_func){
    my_handler_for_end_work=my_func;}

void Parser::register_my_handler_for_ints(Handler_for_ints my_func){
    my_handler_for_ints=my_func;}

void Parser::register_my_handler_for_strings(Handler_for_strings my_func){
    my_handler_for_strings=my_func;}




std::vector<std::string> Parser::parse(const std::string& text){
    printf("parsing this:%s\n",text.c_str());
    if (my_handler_for_begin_work != nullptr ) {my_handler_for_begin_work(); }

    std::vector<std::string> otv;
    if (text.length() == 0){
        if (my_handler_for_end_work != nullptr ) {my_handler_for_end_work();
            return otv;
        }
            
    }
    
    /*
    char* buffer=new char[text.length()+1];
    text.copy(buffer,text.length(),0);
    std::string new_text=std::string(buffer);
    new_text.push_back(' ');
    
     */
    
    std::size_t pos_to_start_from = 0;
    std::size_t pos_where_found = text.find_first_of(" \n\t",pos_to_start_from);
    std::string tek_token;
    
    

    
    while (pos_where_found != std::string::npos){
        tek_token=text.substr(pos_to_start_from,pos_where_found-pos_to_start_from);
        int looks_like_number=1;
        for (int i=0; i<tek_token.length(); i=i+1){
            if (!isdigit(tek_token[i])){
                looks_like_number=0;
                break;
            }
        }
        if (tek_token.length() > 0 && looks_like_number==1){
            try{
            uint64_t num = std::stoull(tek_token.c_str());
            if (my_handler_for_ints != nullptr) {my_handler_for_ints(num);}
            otv.push_back("int");
            }
            catch(...){
                if (my_handler_for_strings != nullptr){my_handler_for_strings(tek_token.c_str());}
                otv.push_back("too_big_int");
            }
        }
        if (tek_token.length() > 0 && looks_like_number==0){
            if (my_handler_for_strings != nullptr){my_handler_for_strings(tek_token.c_str());}
            otv.push_back("string");
        }
        pos_to_start_from = text.find_first_not_of(" \n\t",pos_where_found);
        pos_where_found = text.find_first_of(" \n\t",pos_to_start_from);
        
        
        
    }
    
    
    
    if (pos_to_start_from!=std::string::npos &&  pos_where_found==std::string::npos){
        tek_token=text.substr(pos_to_start_from,text.length()-pos_to_start_from);
        int looks_like_number=1;
        for (int i=0; i<tek_token.length(); i=i+1){
            if (!isdigit(tek_token[i])){
                looks_like_number=0;
                break;
            }
        }
        if (tek_token.length() > 0 && looks_like_number==1){
            try{
            uint64_t num = std::stoull(tek_token.c_str());
            if (my_handler_for_ints != nullptr) {my_handler_for_ints(num);}
            otv.push_back("int");
            }
            catch(...){
                if (my_handler_for_strings != nullptr){my_handler_for_strings(tek_token.c_str());}
                otv.push_back("too_big_int");
            }
        }
        if (tek_token.length() > 0 && looks_like_number==0){
            if (my_handler_for_strings != nullptr){my_handler_for_strings(tek_token.c_str());}
            otv.push_back("string");
        }
        return otv;
    }
    
          
    if (my_handler_for_end_work != nullptr ) {my_handler_for_end_work(); }
    return otv;



}
