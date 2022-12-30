#include <stdio.h>



int main(void){
    

    int i, j, n, summ_n;

    int array_1x[10];
    int array_2x[10][10];
    int array_3x[10][10][10];


    printf("\n\n");

    for(i=0; i < 10; i++){
        if (i == 4){
            array_1x[i] = 5;
        }else{
            array_1x[i] = 0;
        }
        printf("%d \t", array_1x[i]);
    }
    printf("\n\n\n");

    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            if (i == j){
                array_2x[i][j] = 5;
            }else{
            array_2x[i][j] = 0;
            }
            printf("%d \t", array_2x[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");


    summ_n = 0;
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            for (n = 0; n < 10; n++){
                if (i == j){
                    array_3x[i][j][n] = n;
                    summ_n += n; 
                }else{
                    array_3x[i][j][n] = 0;
                }
            }
            printf("%d \t", summ_n);
            summ_n = 0;
        }
        printf("\n");

    }
    return 0;
}