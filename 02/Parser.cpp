#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Parser.h"


Parser::Parser():my_handler_for_begin_work(nullptr),my_handler_for_end_work(nullptr), my_handler_for_ints(nullptr), my_handler_for_strings (nullptr), cnt_ints(0), cnt_strings(0){}

void Parser::register_my_handler_for_begin_work(Handler_for_begin_work my_func){
    my_handler_for_begin_work=my_func;}

void Parser::register_my_handler_for_end_work(Handler_for_end_work my_func){
    my_handler_for_end_work=my_func;}

void Parser::register_my_handler_for_ints(Handler_for_ints my_func){
    my_handler_for_ints=my_func;}

void Parser::register_my_handler_for_strings(Handler_for_strings my_func){
    my_handler_for_strings=my_func;}

int Parser::get_cnt_ints(){return cnt_ints;}

int Parser::get_cnt_strings(){return cnt_strings;}


void Parser::parse(const char* text){
    printf("parsing this: %s\n",text);
    if (my_handler_for_begin_work !=nullptr ) {my_handler_for_begin_work(); }

    bool looks_like_number=0;
    if (text[0] >= '0' && text[0] <= '9') {looks_like_number=1;}
    std::string tek_token;

    
    char tek;

    size_t text_len = std::strlen(text);

    int i=0;
    while(text[i]==' '){i++;}

    tek=text[i];

    while (tek){
        if(tek==' '){
                //printf("new word %s: looks_like_number=%d\n",tek_token.c_str(),looks_like_number);
                
                if(looks_like_number==1) {
                    cnt_ints+=1;
                    if (my_handler_for_ints != nullptr ){
                                                         int num=atoi(tek_token.c_str());
                                                         my_handler_for_ints(num);
                                                 }
                }
                                

                if(looks_like_number==0) {
                    cnt_strings+=1;
                    if (my_handler_for_strings != nullptr ) {my_handler_for_strings(tek_token.c_str()); }}
            

                tek_token.clear();


                
                while( (i<=(text_len-1)) &&(text[i]==' ')){i++;}

                i=i-1;

                if ((i<(text_len-1)) && (text[i+1] >= '0' && text[i+1] <= '9')) {looks_like_number=1;}

            }

        else if (!(tek >= '0' && tek <= '9')) {looks_like_number=0;}

        if(tek!=' '){tek_token+=tek;}
        
        i=i+1;
        tek=text[i];
    
    
           }

    //printf("new word %s : looks_like_number=%d\n",tek_token.c_str(),looks_like_number);
    
    if(looks_like_number==1) {
        cnt_ints+=1;
        if (my_handler_for_ints !=nullptr ){
                                           int num=atoi(tek_token.c_str());
                                           my_handler_for_ints(num);
                                     }
    }
                                

    if(looks_like_number==0){
        cnt_strings+=1;
        if (my_handler_for_strings !=nullptr ){my_handler_for_strings(tek_token.c_str()); }
        
    }
            


    

    //printf("parse ended! \n");
    
    if (my_handler_for_end_work !=nullptr ) {my_handler_for_end_work(); }



}
