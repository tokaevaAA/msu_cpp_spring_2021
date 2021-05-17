#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <sstream>
#include <string>
#include "Serializer.h"




struct Data1bool{
    bool a;
    Error serialize(Serializer& serializer){
        return serializer.process(a);
    }
    Error deserialize(Deserializer& deserializer){
        Error otv= deserializer.process(a);
        if (deserializer.in_.rdbuf()->in_avail() !=1){return Error::CorruptedArchive;}
        return otv;
    }
};

struct Data1int{
    uint64_t a;
    Error serialize(Serializer& serializer){
        return serializer.process(a);
    }
    Error deserialize(Deserializer& deserializer){
        Error otv= deserializer.process(a);
        if (deserializer.in_.rdbuf()->in_avail() !=1){return Error::CorruptedArchive;}
        return otv;
    }
};


struct Data2{
    uint64_t a;
    bool b;
    Error serialize(Serializer& serializer){
        return serializer.process(a,b);
    }
    Error deserialize(Deserializer& deserializer){
        Error otv= deserializer.process(a,b);
        if (deserializer.in_.rdbuf()->in_avail() !=1){return Error::CorruptedArchive;}
        return otv;
    }
};



struct Data3{
    uint64_t a;
    bool b;
    uint64_t c;
    Error serialize(Serializer& serializer){
        return serializer.process(a,b,c);
    }
    Error deserialize(Deserializer& deserializer){
        Error otv= deserializer.process(a,b,c);
        if (deserializer.in_.rdbuf()->in_avail() !=1){return Error::CorruptedArchive;}
        return otv;
    }
};

struct Data4{
    uint64_t a;
    bool b;
    uint64_t c;
    bool d;
    Error serialize(Serializer& serializer){
        return serializer.process(a,b,c,d);
    }
    Error deserialize(Deserializer& deserializer){
        Error otv= deserializer.process(a,b,c,d);
        if (deserializer.in_.rdbuf()->in_avail() !=1){return Error::CorruptedArchive;}
        return otv;
    }
};

void Test1_save_and_load(){
    printf("Test1: save and load;\n");
    
    Data3 x { 1, true, 2 };
    std::stringstream stream;
    Serializer serializer(stream);
    serializer.save(x);
    
    std::string tek_str;
    
    tek_str=serializer.getMyString();
    printf("tek_str=%s\n",tek_str.c_str());
    assert(strcmp(tek_str.c_str(),"1 true 2 ")==0);


    
    Data3 y { 0, false, 0 };
    Deserializer deserializer(stream);
    const Error err = deserializer.load(y);
    
    tek_str=deserializer.getMyString();
    printf("tek_str=%s\n",tek_str.c_str());
    assert(strcmp(tek_str.c_str()," ")==0);
    
    assert(err == Error::NoError);
    assert(x.a == y.a);
    assert(x.b == y.b);
    assert(x.c == y.c);
    printf("Success!\n\n");
}


void Test2_oneBool(){
    printf("Test2: one bool;\n");
    Data1bool x {1}; // !!!the same as Data1bool x {true};
    std::stringstream stream;
    Serializer serializer(stream);
    serializer.save(x);
    
    std::string tek_str;
    
    tek_str=serializer.getMyString();
    printf("tek_str=%s\n",tek_str.c_str());
    assert(strcmp(tek_str.c_str(),"true ")==0);

    
    Data1bool y {false};
    Deserializer deserializer(stream);
    const Error err = deserializer.load(y);
    
    tek_str=deserializer.getMyString();
    printf("tek_str=%s\n",tek_str.c_str());
    assert(strcmp(tek_str.c_str()," ")==0);
    
    assert(err == Error::NoError);
    assert(x.a == y.a);
    printf("Success!\n\n");
}

void Test3_oneInt(){
    printf("Test3: one int;\n");
    Data1int x {1};
    std::stringstream stream;
    Serializer serializer(stream);
    serializer.save(x);
    
    std::string tek_str;
    
    tek_str=serializer.getMyString();
    printf("tek_str=%s\n",tek_str.c_str());
    assert(strcmp(tek_str.c_str(),"1 ")==0);
    
    Data1int y {0};
    Deserializer deserializer(stream);
    const Error err = deserializer.load(y);
    
    tek_str=deserializer.getMyString();
    printf("tek_str=%s\n",tek_str.c_str());
    assert(strcmp(tek_str.c_str()," ")==0);
    
    assert(err == Error::NoError);
    assert(x.a == y.a);
    printf("Success!\n\n");
}


void Test4_wrong_number_param2to3(){
    printf("Test4: wrong_number_param2to3;\n");
    Data2 x {1,true};
    std::stringstream stream;
    Serializer serializer(stream);
    serializer.save(x);
    
    std::string tek_str;
    
    tek_str=serializer.getMyString();
    printf("tek_str=%s\n",tek_str.c_str());
    assert(strcmp(tek_str.c_str(),"1 true ")==0);
    
    Data3 y {0,false,10};
    Deserializer deserializer(stream);
    const Error err = deserializer.load(y);
    assert(err == Error::CorruptedArchive);
    
    tek_str=deserializer.getMyString();
    printf("tek_str=%s\n",tek_str.c_str());
    assert(strcmp(tek_str.c_str(),"")==0);
    
    printf("Success!\n\n");
}


void Test5_wrong_number_param4to3(){
    printf("Test5: wrong_number_param4to3;\n");
    
    
    Data4 z {1,true,10,false};
    std::stringstream stream;
    Serializer serializer(stream);
    serializer.save(z);
    
    std::string tek_str;
    
    tek_str=serializer.getMyString();
    printf("tek_str=%s\n",tek_str.c_str());
    assert(strcmp(tek_str.c_str(),"1 true 10 false ")==0);

    Data3 w {0,false,10};
    Deserializer deserializer(stream);
    const Error err = deserializer.load(w);
    assert(err == Error::CorruptedArchive);
    
    tek_str=deserializer.getMyString();
    printf("tek_str=%s\n",tek_str.c_str());
    assert(strcmp(tek_str.c_str()," false ")==0);
    
    printf("Success!\n\n");
}


int main(){
    printf("Hello!\n");
    
    Test1_save_and_load();
    Test2_oneBool();
    Test3_oneInt();
    Test4_wrong_number_param2to3();
    Test5_wrong_number_param4to3();
    
    printf("Goodbye!\n");
}
