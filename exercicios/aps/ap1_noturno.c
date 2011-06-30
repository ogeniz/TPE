/* Implementar um programa que leia um vetor de 10 inteiros, e gere
   um segundo vetor a partir do vetor lido seguindo as seguintes regras:
   a. o valor dos elementos pares do vetor original devem aparecer como o
   dobro no novo vetor;
   b. o valor dos elementos ímpares do vetor original devem aparecer como o
   triplo no novo vetor;
   - Exiba os elementos do novo vetor;
   - Mostrar também a soma de todos os elementos do novo vetor.
 */

#include <stdio.h>

int main(void)
{
   unsigned char i;
   int soma = 0;
   int vetor1[10] = {0,0,0,0,0,0,0,0,0,0},vetor2[10] = {0,0,0,0,0,0,0,0,0,0};/*declaração dos vetores*/

   printf("Entre com os 10 elementos do vetor de inteiros.:\n");

   for(i = 0; i < 10; i++)/*percorre todos os elementos do vetor*/
   {
      printf("v1[%d] = ",i + 1);
      scanf("%i",(vetor1 + i));/*preenche o vetor com valores lidos do teclado*/
   }
   printf("\n");
   
   for(i = 0; i < 10; i++)/*percorre todos os elementos do vetor*/
   {
      if(*(vetor1 + i) % 2)/*testa a condição se par ou ímpar*/
	 *(vetor2 + i) = *(vetor1 + i) * 3;/*se impar*/
      else
	 *(vetor2 + i) = *(vetor1 + i) * 2;/*se par*/
      soma += *(vetor2 + i);/*acumula a soma dos elementos de vetor2*/
   }
   
   for(i = 0; i < 10; i++)/*percorre todos os elementos do vetor*/
      printf("vetor2[%d] = %i\n",i + 1,*(vetor2 + i));/*imprime os elementos do vetor2*/
   printf("\n");

   printf("A soma dos valores do vetor2 eh %i\n\n",soma);/*imprime a soma dos elementos de vetor2*/

   return 0;
}
