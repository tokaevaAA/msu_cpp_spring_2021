#pragma once

using Handler_for_begin_work = void (*)(); //псевдонимы
using Handler_for_end_work = void (*)();
using Handler_for_ints = void (*)(int num);
using Handler_for_strings = void (*)(const char* tek_token );

class Parser{
private:
    Handler_for_begin_work my_handler_for_begin_work;
    Handler_for_end_work my_handler_for_end_work;
    Handler_for_ints my_handler_for_ints;
    Handler_for_strings my_handler_for_strings;
    int cnt_ints;
    int cnt_strings;
public:
    Parser();
    ~Parser(){}
    void parse(const char* text);
    void register_my_handler_for_begin_work(Handler_for_begin_work my_func);
    void register_my_handler_for_end_work(Handler_for_end_work my_func);
    void register_my_handler_for_ints(Handler_for_ints my_func);
    void register_my_handler_for_strings(Handler_for_strings my_func);
    int get_cnt_ints();
    int get_cnt_strings();
    
    
};
