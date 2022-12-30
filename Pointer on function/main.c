#include <stdio.h>

typedef int (*TFunc_min) (int, int);
typedef int (*TFunc) (int, int);

int get_five(){
    return 5;
}

int max(int a, int b){
    if (a < b){
        return b;
    }else{
        return a;
    }
}

int min(int a, int b){
    if (a > b){
        return b;
    }else{
        return a;
    }
}


int get_number(TFunc fn, int a, int b){
    return fn(a,b);
}

int get_five_func(int  (*fn)()){
        return fn();
}



int main(void){
    int (*func_five)();
    int (*func_max)(int, int);
    
    func_five = get_five;
    func_max = max;
    
    TFunc_min  func_min;
    func_min = min;



    printf("get_five ===  %d\n",   get_five_func(get_five));

    printf("func = %d", func_five());
    printf("\n");
    printf("func_max = %d", func_max(10, 20));
    printf("\n");
    printf("func_min = %d", func_min(10, 20));

    TFunc func;
    func = max;
    printf("\nfn_max = %d", get_number(func, 10,20));
    printf("\nfn_max = %d", get_number(max, 10,20));
    func = min;
    printf("\nfn_min = %d", get_number(func, 10,20));
    printf("\nfn_min = %d", get_number(min, 10,20));
    
    



    return 0;
}
