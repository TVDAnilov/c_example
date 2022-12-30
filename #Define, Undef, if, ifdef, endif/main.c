/*Стандарт ANSI С определяет следующие директивы препроцессора:
#if #ifdef #ifndef #else #elif #endif  #include #define #undef #line #error #pragma*/

/*здесь про: #if #ifdef #ifndef #else #elif #endif #include #define  #undef*/


/*#if выражение                     //открывает блок
последовательность операторов
#elif выражение 1                   //можно использовать #else или #elif для 
последовательность операторов       // создания лесенки if-else-if
#elif выражение 2
последовательность операторов
#elif выражение 3
последовательность операторов
#elif выражение 4
последовательность операторов
...
#elif выражение N
последовательность операторов
#endif*                             //закрывает блок, #endif всегда один, закрывает блок #if. 
*/



#include <stdio.h>

#define US 0
#define ENGLAND 1
#define FRANCE 2
#define ACTIVE_COUNTRY US

#if ACTIVE_COUNTRY==US
char currency[] = "dollar";
#elif ACTIVE_COUNTRY==ENGLAND
char currency[] = "pound";
#else
char currency[] = "franc";
#endif


/*
#if и #elif могут быть вложенными. 
Каждый #endif, #else или #elif ассоциируется с ближайшим #if или #elif.      */

#define MAX 101
#define SERIAL_VERSION 1

#if MAX > 100
    #if SERIAL_VERSION  == 1
        int port = 198;
    #elif
        int port = 200;
    #endif
#else
    char out_buffer[100] ;
#endif


/*
#ifdef и #ifndef соответ­ственно означает «если определено» и «если не определено». 
Стандартный вид #ifdef следующий:

#ifdef имя_макроса
последовательность операторов
#endif

Kaк #ifdef, так и #ifndef могут использовать оператор #else, но нe #elif.
*/

#define MIN_Count 0
#define MAX_Count 10    


int main(void){

    #undef MIN_Count           //удалем define
    #undef MAX_Count   
                            
    #ifndef MIN_Count           //если define не определен
        #define MIN_Count 0
    #endif
    #ifndef MAX_Count
        #define MAX_Count 10
    #endif

    #ifdef MIN_Count
        #ifdef MAX_Count
            for(int i = MIN_Count; i <= MAX_Count; i++){
                printf("i = %d \n", i);
            }
        #endif    
    #endif 

    return 0;
}










