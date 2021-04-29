#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>



struct CountArgumentError: public std::exception{};
struct WrongArgumentInBracketsError: public std::exception{};
struct BracketsError: public std::exception{};


template<typename T>
void nakopit_params_in_vec(std::vector<std::string>& args, T& item){
    std::stringstream ss;
    ss << item;
    args.push_back(ss.str());
}

template<typename T, typename... Targs>
void nakopit_params_in_vec(std::vector<std::string>& args_vec, T& arg, Targs... remaining_args){
    nakopit_params_in_vec(args_vec, arg);
    nakopit_params_in_vec(args_vec, remaining_args...);
}


std::string put_vec_of_params_into_place(std::string stroka_to_format, std::vector<std::string>& vec_to_store_params);


template<typename... Targs>
std::string format(const std::string& stroka_to_format){
    return stroka_to_format;
}

template<typename... Targs>
std::string format(const std::string& stroka_to_format, Targs... params_of_formating){
    std::vector<std::string> vec_to_store_params;
    nakopit_params_in_vec(vec_to_store_params, params_of_formating...);
    return put_vec_of_params_into_place(stroka_to_format, vec_to_store_params);
}
