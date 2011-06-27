/* Escrever um algoritmo que leia três números inteiros e positivos (A,B,C) e calcule a seguinte
   expressão: D = (R + S)/2, onde R = (A + B)^2 e S = (B + C)^2
 */

#include <stdio.h>

int main(void)
{
   unsigned int a = 0, b = 0, c = 0;
   float D = 0.0;
   printf("\n\nEntre com tres valores inteiros e positivos na forma A B C ");
   scanf("%u %u %u", &a, &b, &c);
   D =   ( ((a + b)*(a + b)) + ((b + c)*(b + c)) ) / 2.0;
   printf("D = %.5f onde D = ((A + B)^2 + (B + C)^2)/2\n\n", D);
   return 0;
}
