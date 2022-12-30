#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	int i = 0;

	srand(time(NULL));    //Начальная точка генерации последовательности

	i = rand();			  // Диапазон 0..rand_Max
	printf("Range 0..RandMax: %d \n", i);

	int a = -10, b = 10;	//Диапазон -10..10
	i = rand() % (b - a + 1) + a;

	printf("Range -10..10:    %d \n", i);


	return 0;
}

