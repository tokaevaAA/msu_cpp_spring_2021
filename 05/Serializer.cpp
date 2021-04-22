#include <iostream>
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



Error Deserializer::process(bool& object){
    std::string tmp;
    in_ >> tmp;
    if (tmp == "true"){object = true;}
    else if (tmp == "false"){object = false;}
    else {return Error::CorruptedArchive;}
    return Error::NoError;
}

Error Deserializer::process(uint64_t& object){
    in_ >> object;
    if (in_.fail()) {return Error::CorruptedArchive;}
    return Error::NoError;
}



