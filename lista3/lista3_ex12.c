/* Calcular e escrever o valor das seguintes somas
S1 = 2^1/50 + 2^2/49 + .... + 2^50 e S2 = 1 - 2/4 + 3/9 - .... - 10/100
 */
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
      /*printf("\n%f\n",sm1);*/ /*Mostra a soma dos termos a cada iteraccao*/
   }
   for(x = 1; x <= 10; x++)
   {
      sm2 += (double) ((-1)*pow(-1,x))/x;/*Soma as parcelas impares e subtrai as pares*/
      /*printf("\n%f\n",sm2);*/ /*Imprime as somas parciais para cada execuccao do loop*/
   }
   printf("\nS1 = 2^1/50 + 2^2/49 + .... + 2^50 = %.4f ",sm1); /*Imprime o resultado final de S1*/
   printf("e S2 = 1 - 2/4 + 3/9 - .... - 10/100 = %.4f \n\n",sm2); /*Imprime o resultado final de S2*/
   return 0;
}
