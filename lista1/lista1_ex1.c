/*Escrever  um programa  em  C para  ler  a uma  temperatura em  graus
 Fahrenheit,  calcular  e escrever  o  valor  correspondente em  graus
 Celsius, de acordo com a fórmula C/5 = (F - 32)/9 */


#include <stdio.h>

int main(void)
{
  float c = 0.0, f = 0.0;
  printf("Entre com o valor da temperatura em Fahrenheit : ");
  scanf("%f", &c);
  f = (9*c + 160)/5;
  printf("\n%.3f F eh igual a %.3f C\n\n",c,f);
  return 0;
}
