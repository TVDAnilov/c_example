                                                            //https://gcc.gnu.org/onlinedocs/gcc/Common-Function-Attributes.html#Common-Function-Attributes

#include <stdio.h>
                                                        //Эти атрибуты только для GCC
void __attribute__((constructor (100))) start_1(void);   // Это подобие #pragma startup имя_функции();
void __attribute__((constructor (120))) start_2(void);  // Только приоритет для пользователей от 100 до 255, а не 65-255



int main(void){
    printf("In main\n");
return 0;
}

void start_1 (void){
    printf("In start_1\n");
}


void start_2 (void){
    printf("In start_2\n");
}