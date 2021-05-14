#include <iostream>
#include <cassert>
#include "ThreadPool.hpp"

void func(int* a){
    *a+=1;
}

int main(){
    printf("Hello1\n");
    ThreadPool pool(2);
    
    

    printf("Hello2\n");
    auto task2 = pool.exec([]() { return 1; });
    task2.get();
    
    printf("Hello3\n");
    int a=5;
    auto task1 = pool.exec(func, &a);
    printf("a=%d\n",a);
    task1.get();
    
    
    
    

    printf("Goodbuy\n");
    
    return 0;
}
