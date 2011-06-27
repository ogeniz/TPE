/* Calcular e escrever o de pi, com precisao de 0.0001, usando a serie
 pi = 4 - 4/3 + 4/5 - 4/7 + 4/9 - 4/11 + .....*/

#include <stdio.h>
#include <math.h>/*Header necessario para o uso da funcao pow() e acos()*/

int main(void)
{
   unsigned i = 1; /*Variavel de controle do loop*/
   double aux = 0.0; /*Variavel de aculumulaccao*/
   double const pi = acos(-1), precisao = 0.0001; /*Constantes*/
   printf("\n**************************************************\n\n");      
   for(;;i++)
   {
      aux += pow(-1.0,i)/(2.0*i + 1.0);/*Efetua o somatorio*/
      if( fabs(pi - (4.0 * (1.0 + aux))) < precisao )/*Compara com o valor de referencia de pi*/
      {
	 /*printf("Apos %d iteracoes.\n", i);*/ /*Quantidade de iteraccoes*/
	 printf("Valor de Pi dado por arccos(-1) %.5lf.\n",pi);
	 printf("Valor de Pi calculado pela serie 4(1 + (-1)^p/2p + 1) = %.5lf ",4.0 * (1.0 + aux));
	 printf("com erro de %.4lf\n",precisao);
	 break;
      }
   }
   printf("\n\n**************************************************\n");
   return 0;
}
