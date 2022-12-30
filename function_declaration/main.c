#include<stdio.h>

int sum(int a, int b);

int main() {
	printf("sum = %d", sum(2,2));
}

int sum(int a, int b) {
	return a + b;
}