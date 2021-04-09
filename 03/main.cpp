#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <cassert>
#include "ProxyRow.h"
#include "Matrix.h"


void Test1(){
    printf("Test1: Can change elements\n");
    
    Matrix my_matr1(3,4);
    
    for (size_t i=0; i<my_matr1.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr1.getNCols(); j=j+1){
            my_matr1[i][j]=200;
        }
    }
    
    my_matr1.pechat();
    printf("\n");
    
}

void Test2(){
    printf("Test2: can see whether equal or not;\n");
    
    Matrix my_matr1(3,4);
    for (size_t i=0; i<my_matr1.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr1.getNCols(); j=j+1){
            my_matr1[i][j]=i+j;
        }
    }
    
    Matrix my_matr2(3,4);
    for (size_t i=0; i<my_matr2.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr2.getNCols(); j=j+1){
            my_matr2[i][j]=1;
        }
    }
    
    
    my_matr1.pechat();
    my_matr2.pechat();
    
    bool otv=(my_matr1==my_matr2);
    printf("Matr1 and Matr2 are equal: %d\n",otv);
    assert(otv==false);
    printf("\n");
    
}

void Test3(){
    printf("Test3: can take an element;\n");
    Matrix my_matr1(3,4);
    for (size_t i=0; i<my_matr1.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr1.getNCols(); j=j+1){
            my_matr1[i][j]=i+j;
        }
    }
    
    size_t aaa=my_matr1[0][0];
    printf("aaa=%lu\n",aaa);
    assert(aaa==0);
    printf("\n");
}

void Test4(){
    printf("Test4: can multiply by 5;\n");
    
    Matrix my_matr2(3,4);
    for (size_t i=0; i<my_matr2.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr2.getNCols(); j=j+1){
            my_matr2[i][j]=1;
        }
    }
    my_matr2*=5;
    my_matr2.pechat();
    printf("\n");
    
}

void Test5(){
    printf("Test5: can add two rows;\n");
    
    ProxyRow row1(3);
    row1[0]=0;
    row1[1]=1;
    row1[2]=2;
    
    ProxyRow row2(3);
    row2[0]=3;
    row2[1]=4;
    row2[2]=5;
    
    row2.pechat();
    row2=row1;
    row2.pechat();
    
    //(row1+row2).pechat();
    ProxyRow row3=row1+row2;
    row3.pechat();
    printf("%lu\n",row1.getSize());
    
    
}

void Test6(){
    printf("Test6: can add two matrices;\n");
    
    Matrix my_matr1(3,4);
    for (size_t i=0; i<my_matr1.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr1.getNCols(); j=j+1){
            my_matr1[i][j]=i+j;
        }
    }
    
    Matrix my_matr2(3,4);
    for (size_t i=0; i<my_matr2.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr2.getNCols(); j=j+1){
            my_matr2[i][j]=1;
        }
    }
    
    printf("kkkkkk\n");
    
//    ProxyRow row1;
//    row1=my_matr1[0];
//    row1.pechat();
//
//    ProxyRow row2;
//    row2=my_matr2[0];
//    row2.pechat();
//
//
//    ProxyRow row3;
//    row3=row1+row2;
//    row3.pechat();
//
    
    
    Matrix my_matr3=my_matr1+my_matr2;
    my_matr3.pechat();
    printf("\n");
    
}





int main(void){
    printf("Hello!\n");
    
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    
    printf("Googbuy!\n");
    
}
