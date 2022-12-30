
#include <stdio.h>
#include <stdlib.h>
int main() {
  char temp;
  union
  {
    unsigned char p[2];
    unsigned int t;
  } type;
  type.p[0] = 0;
  type.p[1] = 0;
  printf("Enter int : ");
  scanf("%d", &type.t);
  printf("%d = %x .\n", type.t, type.t);
  // Замена байтов
  temp = type.p[0];
  type.p[0] = type.p[1];
  type.p[1] = temp;
  printf("byte replace = \n");
  printf("%d = %x.\n", type.t, type.t);
  getchar(); getchar();
  return 0;
}