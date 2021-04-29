#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "Formater.h"



std::string put_vec_of_params_into_place(std::string stroka_to_format, std::vector<std::string>& vec_to_store_params){
    std::string otv;
    std::string buf_for_ints;
    bool last_bracket_was_closing=true;
    for (int i=0; i<stroka_to_format.size(); i=i+1){
        char tek_el = stroka_to_format.c_str()[i];
        //printf("%c\n",tek_el);
        
        if (last_bracket_was_closing){
            if (tek_el=='{'){last_bracket_was_closing=false;}
            else if (tek_el=='}'){throw BracketsError();}
            else{otv+=tek_el;}
        }
        
        else if (!last_bracket_was_closing){
            if (tek_el==' ' or tek_el=='\n' or tek_el=='\t'){continue;}
            else if (tek_el=='{'){throw BracketsError();}
            else if (isdigit(tek_el)){buf_for_ints+=tek_el;}
            else if (tek_el=='}'){
                if (buf_for_ints.empty()){throw CountArgumentError();}
                else if (stoi(buf_for_ints) >= vec_to_store_params.size() || stoi(buf_for_ints) < 0){throw CountArgumentError();}
                else{
                    last_bracket_was_closing=true;
                    otv+=vec_to_store_params[stoi(buf_for_ints)];
                    buf_for_ints.clear();
                }
            }
            else{throw WrongArgumentInBracketsError();}
        }
        
    }

    return otv;
}
