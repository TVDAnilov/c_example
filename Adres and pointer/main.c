#include <stdio.h>

typedef struct {
    int x;
    int y;

} Tpoint;

int sum(int*);
int* square(int*);
int* perim(int*);
int set_point(Tpoint*, int, int);
int create_pointer(int**);


int main(void){

    int i = 5;
    int *iPtr = NULL;    //Указатель лучше сразу инициализировать
    //int* iPtr; //Тоже самое


    iPtr = &i; //Операция взятия адреса
    if (iPtr != NULL){                        // При работе лучше убедиться что в нем что то отличное от NULL
        
        *iPtr = 10;  // Разыменование указателя
        printf("\ni = %d  \t *iPtr = %d  \t iPtr = ", i, *iPtr, iPtr);

        sum(iPtr);
        printf("%d \t %d", i, *iPtr);

        int square_value;
        square_value = *(square(iPtr));
        printf("\nsquare_value = %d", square_value);
        printf("\n");

        //==================================================================================================
        {
            int *tmp_pointer = NULL;
            tmp_pointer = perim(iPtr);
            printf("\ntmp_pointer = %d, \t *tmp_pointer = ", tmp_pointer, *tmp_pointer);                     // Этот блок скомпилируется без Warning, но это 
            square_value = *tmp_pointer;    // мусор                                                         // не может работать.
            printf("\nsquare_value = %d", square_value);
            printf("\n");
        }
        //==================================================================================================
        

        Tpoint sPoint;
        Tpoint *sPoint_ptr = NULL;
        sPoint_ptr = &sPoint;
        if (sPoint_ptr !=NULL){
            (*sPoint_ptr).x = 15;               // В скобках т.к. у точки больший приоритет, чем у звездочки. Далее есть про "->"
            (*sPoint_ptr).y = 15;
            printf("\n x = %d \t y = %d", (*sPoint_ptr).x, (*sPoint_ptr).y);

            set_point(sPoint_ptr, 20, 20);
            printf("\n x = %d \t y = %d", (*sPoint_ptr).x, (*sPoint_ptr).y);
        }
    }



                                                //и последнее - void*

        int a = 5, b = 10, *p_a, *p_b;
        float c = 15.5, *p_c;
        void *p = NULL;         //void* - для хранения адреса, со значениями работать нельзя, если только присвоить указателю какого то типа адрес хранящийся в void*

        p_a = &a;
        p_b = &b;

        if (p_a!= NULL &&   p_b!= NULL && p_c!= NULL){
            p = p_a;
            p_b = p;
            printf("\n b = %d", *p_b);
            printf("\n");

            //*p = 5;   //Ошибка т.к. непонятно как работать с void.
        }                              



        // указатели на указатель
        int m = 10;
        int *ptr = &m;
        int **ptr2 = &ptr;
        **ptr2 = 20;
        printf("\n m = %d", **ptr2);

        ptr2 = NULL;
        ptr = NULL;


        create_pointer(&ptr);
        if (ptr != NULL){
            
            printf("\nptr = %d", *ptr);  // 50

            *ptr = 100;

            printf("\nptr = %d", *ptr);  // 100
        }
        free(ptr);
        ptr = NULL;
    return 0;
}

int create_pointer(int **pointer){
    *pointer = malloc(sizeof(int));
    **pointer = 50;
}


int* square(int *x){
    if (x != NULL){
        *x = (*x) * (*x);
    }
    return x;
}


int sum(int *x){
    int sum;
    if (x != NULL){
        sum = *x = (*x) + (*x);
    }
    return sum;
}


int* perim(int *x){
    int permim_value;
    int *PV =NULL;
    PV = &permim_value;
    printf("\n");
    printf("PV = %d", PV);
    if (x != NULL){
        permim_value = (*x) * (*x);
    }
    return PV;
}


int set_point(Tpoint *sPoint, int x, int y){
    if(sPoint != NULL){
        sPoint-> x = x;
        sPoint-> y = y;
    }
    return 0;
}