#include <stdio.h>
#include <math.h>/*Header necessario para o uso da funcao pow()*/

int main(void)
{
  char x =0, y = 0;/*Inicia as variaveis de controle do loop*/
  double sm1 = 0.0, sm2 = 0.0; /*Inicia as variaveis de acumulaccao das somas*/
  for(x = 1, y = 50; x <= 50; x++,y--)/*loop que varre ou inteiros positivos de 1 a 50 e de 50 1*/
    {
       /*printf("x = %i e y = %i\n", x, y);*/ /*Imprime os pares x e y*/
       sm1 += (double) pow(2,x)/y; /*Efetua a operacao e a soma acumulativa desejada*/
    }
  for(x = 1; x <= 10; x++)
  {
     /*printf("x = %d, x^2 = %d ",x,x*x);*/
     if(x%2) /*Se o indice for impar (x%2) != 0*/
     {
        sm2 += (double) 1/x; /*Soma os indices impares da contagem*/
        printf("soma impar %d/%d\n",x,x*x); /*Imprime na tela a sequencia de impares e sua potencia ao quadrado*/
     }
     else /*Se o indice for par (x%2) == 0*/
     {
        sm2 -= (double) 1/x; /*Subtrai os indices pares da contagem*/
        printf("subtrai par %d/%d\n",x,x*x); /*Imprime na tela a sequencia de pares e sua potencia ao quadrado*/
     }
  }
  printf("\nS1 = %f e S2 = %f\n\n",sm1,sm2);/*Imprime o resultado final*/
  return 0;
}
