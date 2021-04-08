#pragma once
#include <string>
#include <vector>


using Handler_for_begin_work = std::function<void()>; //псевдонимы
using Handler_for_end_work = std::function<void()>;
using Handler_for_ints = std::function<void(uint64_t)>;
using Handler_for_strings = std::function<void(const char*)>;


class Parser{
private:
    Handler_for_begin_work my_handler_for_begin_work;
    Handler_for_end_work my_handler_for_end_work;
    Handler_for_ints my_handler_for_ints;
    Handler_for_strings my_handler_for_strings;
   
public:
    Parser();
    ~Parser(){}
    void parse(const std::string& text);
    void register_my_handler_for_begin_work(Handler_for_begin_work my_func);
    void register_my_handler_for_end_work(Handler_for_end_work my_func);
    void register_my_handler_for_ints(Handler_for_ints my_func);
    void register_my_handler_for_strings(Handler_for_strings my_func);
    
    
    
};
