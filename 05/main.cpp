#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <sstream>
#include "Serializer.h"


struct Data{
    uint64_t a;
    bool b;
    uint64_t c;
    Error serialize(Serializer& serializer){
        return serializer.process(a,b,c);
    }
    Error deserialize(Deserializer& deserializer){
        return deserializer.process(a,b,c);
    }
};


void Test1_save_and_load(){
    printf("Test1: save and load;\n");
    Data x { 1, true, 2 };
    std::stringstream stream;
    Serializer serializer(stream);
    serializer.save(x);
    Data y { 0, false, 0 };
    Deserializer deserializer(stream);
    const Error err = deserializer.load(y);
    assert(err == Error::NoError);
    assert(x.a == y.a);
    assert(x.b == y.b);
    assert(x.c == y.c);
    printf("Success!\n");
}

int main(){
    printf("Hello!\n");
    
    Test1_save_and_load();
    
    printf("Goodbye!\n");
}
