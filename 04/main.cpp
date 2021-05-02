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
    assert(b1==BigInt(1807));
    printf("\n");
}

void Test2_fromString(){
    printf("Test2: fromString\n");
    BigInt b1=BigInt("1807");
    b1.pechat();
    assert(b1.getInt()==1807);
    assert(b1==BigInt(1807));
    printf("\n");
    
}

void Test3_add2BigInts(){
    printf("Test3: add2BigInts\n");
    BigInt b1=BigInt("1807");
    BigInt b2=BigInt("17534");
    BigInt b3=b1+b2;
    b3.pechat();
    assert(b3.getInt()==19341);
    assert(b3!=b1);
    
    b1=BigInt(1000);
    b2=BigInt("-7");
    b3=b1+b2;
    b3.pechat();
    assert(b3.getInt()==993);
    assert(b3<b1);
    
    b1=BigInt(-1001);
    b2=BigInt(1000);
    assert(b2>b1);
    b3=b1+b2;
    b3.pechat();
    assert(b3.getInt()==-1);
    assert(b3<BigInt("0"));
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

void Test5_subtractBigInts(){
    printf("Test5: subtractBigInts\n");
    BigInt b1=BigInt("1001");
    BigInt b2=BigInt("2");
    BigInt b3=b1-b2;
    b3.pechat();
    assert(b3.getInt()==999);
    printf("\n");
}

void Test6_mult2BigInts(){
    printf("Test6: mult2BigInts\n");
    BigInt b1=BigInt("1807");
    BigInt b2=BigInt("17534");
    BigInt b3=b1*b2;
    b3.pechat();
    assert(b3.getInt()==31683938);
    
    b1=BigInt(5);
    b2=BigInt(-1000);
    b3=b1*b2;
    b3.pechat();
    assert(b3.getInt()==-5000);
    printf("\n");
}

void Test7_multByInt(){
    printf("Test7_multByInt\n");
    BigInt b1=BigInt("105");
    BigInt b2=b1*5;
    b2.pechat();
    assert(b2.getInt()==525);
    printf("\n");
}


void Test8_move(){
    printf("Test8: move\n");
    BigInt a = 1;
    printf("a=");
    a.pechat();
    assert(a.getInt()==1);
    
    BigInt b("123456789012345678901234567890");
    printf("b=");
    b.pechat();
    assert(strcmp(b.getString().c_str(), "123456789012345678901234567890")==0);
    
    BigInt c = a * b + 2;
    printf("c=");
    c.pechat();
    assert(strcmp(c.getString().c_str(), "123456789012345678901234567892")==0);
    
    BigInt d;
    d = std::move(c);
    assert(c.my_mas==nullptr);
    assert(c.my_dlina==0);
    printf("d=");
    d.pechat();
    assert(strcmp(d.getString().c_str(), "123456789012345678901234567892")==0);
    
    printf("c=");
    c.pechat();
    assert(strcmp(c.getString().c_str(), "")==0);
    
    a = d + b;
    printf("a=");
    a.pechat();
    assert(strcmp(a.getString().c_str(), "246913578024691357802469135782")==0);
    printf("\n");
    
}

void Test9_okolo0(){
    printf("Test9: okolo0;\n");
    BigInt a = 1;
    BigInt b = 0;
    BigInt c = a+b;
    assert(a==c);
    c=c-BigInt(1);
    assert(c==b);
    printf("\n");
}

void Test10_okoloBase(){
    printf("Test10: okoloBase;\n");
    BigInt a = BigInt(999999);
    a.pechat();
    BigInt b = BigInt(1);
    b.pechat();
    BigInt c = a+b;
    c.pechat();
    assert(c==BigInt(1000000));
    printf("\n");
}

int main(){
    printf("Hello!\n");
    
    Test1_fromInt();
    Test2_fromString();
    Test3_add2BigInts();
    Test4_addBigInt_Int();
    Test5_subtractBigInts();
    Test6_mult2BigInts();
    Test7_multByInt();
    Test8_move();
    Test9_okolo0();
    Test10_okoloBase();
    
    
    printf("Goodbye!\n");
}
