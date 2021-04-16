#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <string>
#include "BigInt.h"

void Test1_fromInt(){
    printf("Test1: fromInt.\n");
    BigInt b1=BigInt(1807);
    b1.pechat();
    assert(b1.getInt()==1807);
    printf("\n");
}

void Test2_fromString(){
    printf("Test2: fromString\n");
    BigInt b1=BigInt("1807");
    b1.pechat();
    assert(b1.getInt()==1807);
    printf("\n");
    
}

void Test3_add2BigInts(){
    printf("Test3: add2BigInts\n");
    BigInt b1=BigInt("1807");
    BigInt b2=BigInt("17534");
    BigInt b3=b1+b2;
    b3.pechat();
    assert(b3.getInt()==19341);
    printf("\n");
}

void Test4_addBigInt_Int(){
    printf("Test4: addBigInt_Int\n");
    BigInt b1=BigInt("1807");
    BigInt b2=BigInt("17534");
    BigInt b3=b1+b2+105007;
    b3.pechat();
    assert(b3.getInt()==124348 );
    printf("\n");
    
}

void Test5_mult2BigInts(){
    printf("Test5: mult2BigInts\n");
    BigInt b1=BigInt("1807");
    BigInt b2=BigInt("17534");
    BigInt b3=b1*b2;
    b3.pechat();
    assert(b3.getInt()==31683938);
    printf("\n");
}

void Test6_multByInt(){
    printf("Test6_multByInt\n");
    BigInt b1=BigInt("105");
    BigInt b2=b1*5;
    b2.pechat();
    assert(b2.getInt()==525);
    printf("\n");
}


void Test7_move(){
    printf("Test7: move\n");
    BigInt a = 1;
    a.pechat();
    assert(a.getInt()==1);
    BigInt b("123456789012345678901234567890");
    b.pechat();
    assert(strcmp(b.getString().c_str(), "123456789012345678901234567890")==0);
    BigInt c = a * b + 2;
    c.pechat();
    assert(strcmp(c.getString().c_str(), "123456789012345678901234567892")==0);
    BigInt d;
    d = std::move(c);
    d.pechat();
    assert(strcmp(d.getString().c_str(), "123456789012345678901234567892")==0);
    c.pechat();
    assert(strcmp(c.getString().c_str(), "")==0);
    a = d + b;
    a.pechat();
    assert(strcmp(a.getString().c_str(), "246913578024691357802469135782")==0);
    
}

int main(){
    printf("Hello!\n");
    
    Test1_fromInt();
    Test2_fromString();
    Test3_add2BigInts();
    Test4_addBigInt_Int();
    Test5_mult2BigInts();
    Test6_multByInt();
    Test7_move();
    
    
    printf("Goodbye!\n");
}
