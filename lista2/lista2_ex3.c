/*Ler um  conjunto de  valores i,a,b,c  onde i eh  um valor  inteiro e
  positivo  e  a,b,c  sao  quaisquer  valores  reais  distintos  e  os
  escreva. A seguir.  Se i = 1 escrever os tres  valores a,b,c e ordem
  crescente.   Se   i  =  2   escrever  os  valores  a,b,c   em  ordem
  descrescente. Se  i =  3 escrever  os valores de  forma que  o maior
  entre a,b,c fique entre os outros.*/

#include <stdio.h>

int main(void)
{
  unsigned int i = 0; 
  float a = 0.0, b = 0.0, c = 0.0;
  printf("Entre com os valores de i a b c, respectivamente : ");
  scanf("%u %f %f %f", &i, &a, &b, &c);
  if( (i < 1) || (i > 3) )
  {
    printf("\nErro!! Os valores permitidos para i sao 1,2 ou 3\n\n");
    return 0;
  }
  if(i == 1)
  {
    if( (a > b) && (a > c) )
      if(b > c)
        printf("\nPara i = %u temos %.3f < %.3f < %.3f\n\n", i, c, b, a);
      else
        printf("\nPara i = %u temos %.3f < %.3f < %.3f\n\n", i, b, c, a);
    if( (a < b) && (a > c) || (a > b) && (a < c))
      if(b > c)
        printf("\nPara i = %u temos %.3f < %.3f < %.3f\n\n", i, c, a, b);
	else
	  printf("\nPara i = %u temos %.3f < %.3f < %.3f\n\n", i, b, a, c);
    if( (a < b) && (a < c) )
      if(b > c)
        printf("\nPara i = %u temos %.3f < %.3f < %.3f\n\n", i, a, c, b);
      else
        printf("\nPara i = %u temos %.3f < %.3f < %.3f\n\n", i, a, b, c);
  }
  if(i == 2)
  {
    if( (a > b) && (a > c) )
      if(b > c)
        printf("\nPara i = %u temos %.3f > %.3f > %.3f\n\n", i, a, b, c);
      else
        printf("\nPara i = %u temos %.3f > %.3f > %.3f\n\n", i, a, c, b);
    if( (a < b) && (a > c) || (a > b) && (a < c))
      if(b > c)
        printf("\nPara i = %u temos %.3f > %.3f > %.3f\n\n", i, b, a, c);
      else
        printf("\nPara i = %u temos %.3f > %.3f > %.3f\n\n", i, c, a, b);
    if( (a < b) && (a < c) )
      if(b > c)
        printf("\nPara i = %u temos %.3f > %.3f > %.3f\n\n", i, b, c, a);
      else
        printf("\nPara i = %u temos %.3f > %.3f > %.3f\n\n", i, c, b, a);
  }
  if(i == 3)
  {
    if( (a > b) && (a > c) )
      printf("\nPara i = %u temos %.3f > %.3f > %.3f\n\n", i, b, a, c);
    if( (a < b) && (a < c) )
      printf("\nPara i = %u temos %.3f > %.3f > %.3f\n\n", i, c, b, a);
    else
      printf("\nPara i = %u temos %.3f > %.3f > %.3f\n\n", i, b, c, a);
  }
  return 0;
}
