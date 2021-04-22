#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>

enum class Error{
    NoError,
    CorruptedArchive
};





class Serializer{
private:
    static constexpr char Separator = ' ';
    std::ostream& out_;
public:
    Serializer(std::ostream& given_out):out_(given_out){};
    
    ~Serializer(){}
    
    template<class T>
    Error save(T& object){return object.serialize(*this);}
    
    
    Error process(bool& object);
    
    Error process(uint64_t& object);
    
    template<class T, class... ArgsT>
    Error process(T& object, ArgsT&... args){
        if (process(object) == Error::NoError) {return process(args...);}
        else {return Error::CorruptedArchive;}
    }
        
    
};



//---------------------------------------------

class Deserializer{
private:
    static constexpr char Separator = ' ';
    std::istream& in_;
public:
    Deserializer(std::istream& given_in):in_(given_in){}
    
    ~Deserializer(){}
    
    template<class T>
    Error load(T& object){return object.deserialize(*this);}
    
    
    Error process(bool& object);
    
    Error process(uint64_t& object);
    
    template<class T, class... ArgsT>
    Error process(T& object, ArgsT&... args){
        if (process(object) == Error::NoError) {return process(args...);}
        else {return Error::CorruptedArchive;}
    }
    
};

