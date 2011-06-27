/* Escrever a soma dos multiplos de 7 entre 100 e 200 */
#define NMBR 7
#include <stdio.h>

int main(void)
{
   int soma = 0, flag = 0, count = 0; /*Variaveis do Programa*/
   for(flag = 100; flag <= 201; flag++) /*Loop que lista os multiplos de NMBR entre 100 e 200 inclusive*/
      if( !(flag % NMBR) )/*Se o numero for divisivel por NMBR faça*/
      {
	 printf("%d ",flag);/*Imprime-o na tela*/
	 soma += flag;/*Acumula sua soma com o anterior*/
	 count++;/*Contador para registro da quantidade de numeros que sao multiplos de NMBR*/
      }
   printf("\n\nsoma = %d, em %d iteraccoes\n\n",soma,count);/*Imprime os resultados na tela*/
   return 0;
}
