/*Escrever  um programa  em  C para  ler  a uma  temperatura em  graus
 Celsius,  calcular  e  escrever   o  valor  correspondente  em  graus
 Fahrenheit, de acordo com a fórmula C/5 = (F - 32)/9 */

#include <stdio.h>

int main(void)
{
  float c = 0.0, f = 0.0;
  printf("\n\nEntre com o valor da temperatura em Celsius : ");
  scanf("%f",&f);
  c = (5*f - 160)/9;
  printf("\n%.3f C eh igual a %.3f F\n\n",f,c);
  return 0;
}
