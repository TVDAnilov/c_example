#include <stdio.h>
#include <stdarg.h>



void func(int a, int b, int c){
    printf("%d %d %d", a, b, c);
    printf("\n");

    int *p = &a;
    printf("%d %d %d", *p, *(p+1), *(p+2));
}


int sum(int cnt, ...){
    int res = 0;
    int *ptr = &cnt + 1;
    for (; cnt > 0; cnt--){
        res = res + *(ptr++);
    }
    return res;
}

int summa(int cnt, ...){
    int res = 0;
    va_list ptr;
    va_start(ptr, cnt);
    for(; cnt >0; cnt--){
        res = res + va_arg(ptr, int);
    }
    va_end(ptr);

    return res;
}







int main(void){

func(10, 20, 30);

printf("\nsum = %d",sum(3, 10, 20, 30));
printf("\nsum = %d",summa(3, 10, 20, 30));


return 0;
}