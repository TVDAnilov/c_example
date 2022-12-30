#include "foo.h"

int foo(int x){
    printf("this foo \n");
    int  a = bar(x) * 5;
    return a;
}


int foo_1 (int x){
    printf("this foo_1");
    return x *5;
}