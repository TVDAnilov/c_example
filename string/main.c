#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    char *str = "string";
    printf("%s", str);
    // srt[0] = 'S';   // ошибка, т.к. литерал "string" в read only памяти
    //sprintf(str,"%s", "String");    // то же ошибка по этой же  причине
    // НО!
    str = "String"; // Выделит место под новый литерал 
    printf("\n%s", str);

    str = NULL;
    str = (char*)malloc(50);   //Теперь можно динамически менять строку
    if (str !=NULL){
        sprintf(str, "%s", "New String thought sprintf()!!!");
        str[0] = 'N';
        printf("\n%s", str);
                                        //НО! Что бы снова использовать литерад
                                        // нужно освободить память, иначе утечка.
        free(str);
        str = "The end";                // и снова read only

    }
    
    printf("\n%s", str);



    char str1[] = "str1";
    char str2[] = "str2";
    char *str3 = NULL;
    int i;
    i = (strlen(str1) + strlen(str2) + 1) + strlen(" \t ");  // (+ 1) -  для символа конца строки
    str3 = (char*) malloc(i);
    sprintf(str3, "%s \t %s", str1, str2);
    printf("\nstr1 = %s", str3);
    free(str3);
    return 0;
}

