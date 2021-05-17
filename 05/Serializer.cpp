#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Serializer.h"


Error Serializer::process(bool& object){
    if (object==true){out_ << "true" << Separator;}
    else {out_ << "false" << Separator;}
    return Error::NoError;
}


Error Serializer::process(uint64_t& object){
    out_ << object << Separator;
    return Error::NoError;
}

std::string Serializer::getMyString(){
    std::stringstream ss2;
    ss2 << out_.rdbuf(); //out_ in now empty
    out_<<ss2.str(); //filling out_ back again
    return ss2.str();

    
}




Error Deserializer::process(bool& object){
    std::string tmp;
    in_ >> tmp;
    if (tmp.size()==0){return Error::CorruptedArchive;};
    if (tmp == "true"){object = true;}
    else if (tmp == "false"){object = false;}
    else {return Error::CorruptedArchive;}
    
    return Error::NoError;
}

Error Deserializer::process(uint64_t& object){
    
    std::string buf;
    in_ >> buf;
    if (buf.size()==0){return Error::CorruptedArchive;};
    if (!std::all_of(buf.begin(), buf.end(), ::isdigit)) {return Error::CorruptedArchive;}
    object = std::stoi(buf);
    
    return Error::NoError;
}


std::string Deserializer::getMyString(){
    std::stringstream ss2;
    ss2 << in_.rdbuf(); //in_ is now empty, even if used to have smth
    return ss2.str();
}


