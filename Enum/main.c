#include <stdio.h>



enum Color {
    Red, Green, Blue
}clr;

typedef enum {UP, DOWN} Vertical;


char* print_color(enum Color *clr){
    int start = 1, end = sizeof(*clr), i;   //sizeof вернет 4, нулевой элемент хранит текущее значенте
    //  clr[0] == 1 - в нулевом элементе хранится значение активного элемента 
    

    for(i = start; i < end; i++ ){
        switch (i)
        {
        case Red:
            //printf("\n RED = %d", Red);
            if(*clr == i){
                //printf("\nclr = RED");
                return "RED";
            }
            break;
        case Green:
            //printf("\n Green = %d", Green);
            if(*clr == i){
                //printf("\nclr = Green");
                return "GREEN";
            }
            break;
        case Blue:
            //printf("\n Blue = %d", Blue);
            if(*clr == i){
                //printf("\nclr = Blue");
                return "BLUE";
            }
            break;    
        default:
            return "WHITE";
            break;
        }
    }
    return 0;
    
}


char* print_color(enum Color*);

int main(void){
    clr = Green;
    printf("\n =========================");
    printf("\n%s", print_color(&clr));
    clr = Blue;
    printf("\n%s", print_color(&clr));
    printf("\n =========================");

    Vertical vertical = UP;
    Vertical *vertical_p = NULL;

    vertical_p = &vertical;
    printf("\n vertical_p = %d", *vertical_p); // 0 - т.е. UP
    
    *vertical_p = DOWN;
    printf("\n vertical_p = %d", *vertical_p); // 1 - т.е. DOWN

    enum Color  color = Blue;
    printf("\ncolor = %d", color);

    return 0;
}