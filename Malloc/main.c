#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *x = NULL;

    x = malloc(sizeof(int));    // malloc выделит в "куче"кол-во байт = int и вернет указатель на первый байт.
    if(x != NULL){
        *x = 100;

        printf("\n *x = %d", *x);

        free(x);        // Освобождаем память, удаляем указатель
        x = NULL;
    }



    int *array = NULL;
    int i, n = 10;

    array = malloc(sizeof(int) * n);

    printf("\n");
    for (i = 0; i < n; i++){
        *(array+i) = i;
    }
    //
    //можно сказать так:
    //free(array);   //освободить память 
    //array = NULL;     //удалить указатель
    //но для примера продлжу
    n = n * 2;
    array = realloc(array, sizeof(int) * n);
    for (i = n/2; i < n; i++){
        *(array+i) = i;
    }
    for (i = 0; i < n; i++){
        printf("array[%d] = %d \t", i, *(array+i) );
        printf("\n");
    }



    return 0;
}