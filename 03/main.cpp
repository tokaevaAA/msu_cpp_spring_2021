#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <cassert>
#include "ProxyRow.h"
#include "Matrix.h"


void Test1_getNrowsNcols(){
    printf("Test1: getNrowsNcols\n");
    
    Matrix my_matr1(3,4);
    
    int m=my_matr1.getNRows();
    int n=my_matr1.getNCols();
    assert(m==3);
    assert(n==4);
    printf("\n");
    
}

void Test2_assignElements(){
    printf("Test2: Can assign elements\n");
    
    Matrix my_matr1(3,4);
    
    for (size_t i=0; i<my_matr1.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr1.getNCols(); j=j+1){
            my_matr1[i][j]=100*(i+1) + j;
        }
    }
    
    printf("matr1:\n");
    my_matr1.pechat();
    
    for (size_t i=0; i<my_matr1.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr1.getNCols(); j=j+1){
            assert(my_matr1[i][j]==100*(i+1) + j);
        }
    }
    
    printf("\n");
    
}

void Test3_takeElements(){
    printf("Test3: Can take elements\n");
    
    Matrix my_matr1(3,4);
    
    for (size_t i=0; i<my_matr1.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr1.getNCols(); j=j+1){
            my_matr1[i][j]=100*(i+1) + j;
        }
    }
    
    printf("matr1:\n");
    my_matr1.pechat();
    
    double x=my_matr1[1][2];
    assert(x==202);
    
    printf("\n");
    
}

void Test4_multiplyBy(){
    printf("Test4: can multiply by 5;\n");
    
    Matrix my_matr2(3,4);
    for (size_t i=0; i<my_matr2.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr2.getNCols(); j=j+1){
            my_matr2[i][j]=1;
        }
    }
    my_matr2*=5;
    printf("matr2:\n");
    my_matr2.pechat();
    
    for (size_t i=0; i<my_matr2.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr2.getNCols(); j=j+1){
            assert(my_matr2[i][j]==5);
        }
    }
    printf("\n");
    
}



void Test5_addProxyRows(){
    printf("Test5: can add two rows;\n");
    
    ProxyRow row1(3);
    row1[0]=0;
    row1[1]=1;
    row1[2]=2;
    
    ProxyRow row2(3);
    row2[0]=30;
    row2[1]=40;
    row2[2]=50;
    
    
    printf("row1:\n");
    row1.pechat();
    printf("row2:\n");
    row2.pechat();
    

    ProxyRow row3=row1+row2;
    printf("row3:\n");
    row3.pechat();
    
    assert(row3.getSize()==3);
    assert(row3[0]==30);
    assert(row3[1]==41);
    assert(row3[2]==52);
    printf("\n");
    
}

void Test6_addMatrices(){
    printf("Test6: can add two matrices;\n");
    
    Matrix my_matr1(3,4);
    for (size_t i=0; i<my_matr1.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr1.getNCols(); j=j+1){
            my_matr1[i][j]=100*(i+1)+j;
        }
    }
    
    printf("matr1:\n");
    my_matr1.pechat();
    
    Matrix my_matr2(3,4);
    for (size_t i=0; i<my_matr2.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr2.getNCols(); j=j+1){
            my_matr2[i][j]=1;
        }
    }
   
    printf("matr2:\n");
    my_matr2.pechat();
    
    Matrix my_matr3=my_matr1+my_matr2;
    printf("matr3:\n");
    my_matr3.pechat();
    
    for (size_t i=0; i<my_matr3.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr3.getNCols(); j=j+1){
            assert(my_matr3[i][j]==100*(i+1)+j+1);
        }
    }
    printf("\n");
    
}


void Test7_NotEqual(){
    printf("Test7: can see whether equal or not;\n");
    
    Matrix my_matr1(3,4);
    for (size_t i=0; i<my_matr1.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr1.getNCols(); j=j+1){
            my_matr1[i][j]=100*(i+1)+j;
        }
    }
    
    Matrix my_matr2(3,4);
    for (size_t i=0; i<my_matr2.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr2.getNCols(); j=j+1){
            my_matr2[i][j]=1;
        }
    }
    
    printf("matr1:\n");
    my_matr1.pechat();
    printf("matr2:\n");
    my_matr2.pechat();
    
    bool otv=(my_matr1==my_matr2);
    printf("Matr1 and Matr2 are equal: %d\n",otv);
    assert(otv==false);
    printf("\n");
    
}

void Test8_OutOfRange(){
    printf("Test8: OutOfRange because different NRows, Ncols;\n");
    Matrix my_matr1(1,2);
    for (size_t i=0; i<my_matr1.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr1.getNCols(); j=j+1){
            my_matr1[i][j]=100*(i+1)+j;
        }
    }
    
    Matrix my_matr2(2,1);
    for (size_t i=0; i<my_matr2.getNRows(); i=i+1){
        for (size_t j=0; j<my_matr2.getNCols(); j=j+1){
            my_matr2[i][j]=1;
        }
    }
    
    printf("matr1:\n");
    my_matr1.pechat();
    printf("matr2:\n");
    my_matr2.pechat();
    
    try {
        Matrix my_matr3=my_matr1+my_matr2;
        }
    catch(std::out_of_range){
        printf("Out of range caugth!\n");
        
    }
    printf("\n");

}

void Test9_Matr1x1(){
    printf("Test9: Matr1x1;\n");
    Matrix my_matr1(1,1);
    my_matr1[0][0]=5;
    printf("%d\n",my_matr1[0][0]);
    Matrix my_matr2(1,1);
    my_matr2[0][0]=10*my_matr1[0][0];
    
    assert(my_matr1[0][0]==5);
    assert(my_matr2[0][0]==50);
    Matrix my_matr3=my_matr1+my_matr2;
    assert(my_matr3.getNRows()==1);
    assert(my_matr3.getNCols()==1);
    assert(my_matr3[0][0]==55);
    
}



int main(void){
    printf("Hello!\n");
    
    Test1_getNrowsNcols();
    Test2_assignElements();
    Test3_takeElements();
    Test4_multiplyBy();
    Test5_addProxyRows();
    Test6_addMatrices();
    Test7_NotEqual();
    Test8_OutOfRange();
    Test9_Matr1x1();
    
    printf("Googbuy!\n");
    
}
