#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    int i = 10;
    float j = 10.5;
    printf("%f", round(j));
    printf("\n");
    printf("%d", (int)round(j));
    printf("\n");
    printf("%f", j - (int)j);
    printf("\n");


    char ch[50];
    sprintf(ch, "%f", j);
    printf(ch);

    printf("\n");
    printf(ch);

    printf("\n");

    itoa(i,ch,10);  //10
    printf(ch);
    printf("\n");
    itoa(i,ch,2);   //1010
    printf(ch);
    printf("\n");
    itoa(i,ch,16);  // A
    printf(ch);
    printf("\n");



    sprintf(ch, "100");
    j = atoi(ch);
    printf("%f", j);   //100
    
    printf("\n");

    itoa(i,ch,10);  //100
    printf("%d", i);  //10

    printf("\n");

    sprintf(ch, "150.7");
    j = atof(ch);
    printf("%f", j);  //150.7

    printf("\n");

    printf("%f", round(j));  //151
    printf("\n");


    return 0;
}