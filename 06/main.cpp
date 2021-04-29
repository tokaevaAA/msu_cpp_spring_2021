#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stdexcept>
#include "Formater.h"


void Test1_NormStroka(){
    printf("Test1: NormStroka\n");
    std::string otv=format("{1}+{1} = {0}", 2, "one");
    assert(otv=="one+one = 2");
}

void Test2_NoParamsAtAll(){
    printf("Test2: NoParamsAtAll\n");
    std::string otv=format("No params to format!");
    assert(otv=="No params to format!");
}

void Test3_TooBigNumberInBrackets(){
    printf("Test3: TooBigNumberInBrackets\n");
    try{
    std::string otv=format("{1} is {10}","hello");
    }
    catch (CountArgumentError){
        printf("CountArgumentError caught!\n");
    }
}

void Test4_BadElemInBrackets(){
    printf("Test4: BadElemInBrackets\n");
    try{
    std::string otv=format("{0} is { gdsd ","hello");
    }
    catch (WrongArgumentInBracketsError){
        printf("WrongArgumentInBracketsError caught!\n");
    }
}

void Test5_BadOrderOfBrackets(){
    printf("Test5: BadOrderOfBrackets\n");
    try{
    std::string otv=format("{0} {0} is } { gdsd ","hello");
    }
    catch (BracketsError){
        printf("BracketsError caught!\n");
    }
}

int main(void){
    printf("Hello!\n");
    
    Test1_NormStroka();
    Test2_NoParamsAtAll();
    Test3_TooBigNumberInBrackets();
    Test4_BadElemInBrackets();
    Test5_BadOrderOfBrackets();
    
    
    printf("Goodbuy!\n");
}
