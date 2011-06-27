/*O que imprime o programa a seguir*/

#include<stdio.h>


void func(int *a, int b);

int main(void)
{
   int a = 10, b = 20;
   func(&a, b);
   printf("\na = %d, b = %d\n\n", a, b);
   return 0;
}

void func(int *a, int b)
{
   int temp;
   temp = *a;
   *a = b;
   b = temp;
}
