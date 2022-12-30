#include <stdio.h>



struct sPoint{
    int x,y;
};


struct mPoint{
    int x, y, z;
}mPoint_deff;


typedef struct mPoint center_Space;

struct{                              //анонимная структура
    int height, width, lenght;
}Table;

typedef struct{                              //анонимная структура
    int height, width, lenght;
}Table_1;

struct Table_position{                   //структуры можно вкладывать
    struct mPoint position;
    int height, width, lenght;
};

typedef struct {                     //тоже самое, но через typedef
    struct mPoint position;
    int height, width, lenght;
}Table_position_1;










int main(void){
    printf("\n\n");

    struct sPoint tPoint;
    tPoint.x = 10; tPoint.y = 5;
    printf("tPoint.x = %d \t tPoint.y = %d  ", tPoint.x, tPoint.y);

    printf("\n\n");

    mPoint_deff.x = 5; mPoint_deff.y = 10; mPoint_deff.z = 15;
    printf("mPoint_deff.x = %d \t mPoint_deff.y = %d  mPoint_deff.z = %d", mPoint_deff.x, mPoint_deff.y, mPoint_deff.z);
    
    printf("\n\n");

    struct mPoint my_mPoint;
    my_mPoint.x = 25; my_mPoint.y = 50; my_mPoint.z = 100;
    printf("my_mPoint.x = %d \t my_mPoint.y = %d  my_mPoint.z = %d", my_mPoint.x, my_mPoint.y, my_mPoint.z);
    
    printf("\n\n");


    // struct mPoint_deff my_mPoint;   //Так нельзя, mPoint_deff - всего лишь экземпляр структуры mPoint
    

    center_Space new_center;
    new_center.x = 100; new_center.y = 200; new_center.z = 300;
    printf("new_center.x = %d \t new_center.y = %d  new_center.z = %d", new_center.x, new_center.y, new_center.z);
    
    printf("\n\n");



    Table.height = 70;  Table.width = 60; Table.lenght = 160;
    printf("Table.height = %d \t Table.width = %d  Table.lenght = %d", Table.height, Table.width, Table.lenght);

    printf("\n\n");
    

    //struct Table my_table;   Так нельзя, снова Table экземпляр уже анонимной структуры.
    //Table_1."какое то поле"    - Так тоже нельзя, так как это название типа анонимной структуры, а не имя существующей структуры.          Но далее:

    Table_1 my_table;  //Table_1 переопределенный тип анонимной структуры.
    my_table.height = 75; my_table.width = 50; my_table.lenght = 90;
    printf("my_table.height = %d \t my_table.width = %d  my_table.lenght = %d", my_table.height, my_table.width, my_table.lenght);

    printf("\n\n");

    struct Table_position my_table_position;   //структуры можно вкладывать
    my_table_position.position.x  = 10;
    my_table_position.position.y  = 10;

    Table_position_1  my_Table_position_1;  // это так же работает через typedef
    my_Table_position_1.position.x = 10;
    my_Table_position_1.position.y = 10;
    printf("my_Table_position_1.position.x = %d \t my_Table_position_1.position.y = %d", my_Table_position_1.position.x, my_Table_position_1.position.y);

    printf("\n\n");      


    return 0;
}