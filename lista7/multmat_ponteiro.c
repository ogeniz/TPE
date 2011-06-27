/* Fazer um programa que multiplique duas matrizes, de tal forma que: o usuário entre com
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   unsigned short la = 0, ca = 0, lb = 0, cb = 0;/*variaveis de linhas e colunas das matrizes*/
   unsigned short i,j,k;/*variaveis para controle de contagem*/

   float **matrizA, **matrizB, **matrizC;/*ponteiros para as linhas das matrizes*/

   printf("Entre com o numero de linhas e colunas da matriz A e B ");
   printf("na forma la ca lb cb.: ");
   scanf("%hu %hu %hu %hu",&la,&ca,&lb,&cb);/*entrada de dados sobre as linhas e colunas das matrizes A e B*/

   if(la < 1 || ca < 1 || lb < 1 || cb < 1) /*testa se numero de linhas e colunas eh um numero natural*/
   {
      printf("Erro!!! O numero de linhas e colunas de uma matriz tem que ser um numero natural\n\n");
      exit(1);
   }
   if(ca != lb)/*verifica se o no. de colunas de A eh igual ao no. de linhas de B*/
   {
      printf("Erro!!! O numero de colunas de A deve ser o mesmo do numero de linhas de B\n\n");
      exit(1);
   }
   if( (matrizA = (float **) malloc(la*sizeof(float *))) == NULL )/*testa se a alocaccao foi bem sucedida*/
   {/*para as linhas de A*/
      printf("Erro!!! Memoria Insuficiente para a alocaccao das linhas da Matriz A\n\n");
      exit(2);
   }
   if( (matrizB = (float **) malloc(lb*sizeof(float *))) == NULL )/*testa se a alocaccao foi bem sucedida*/
   {/*para as linhas de B*/
      printf("Erro!!! Memoria Insuficiente para a alocaccao das linhas da Matriz B\n\n");
      exit(2);
   }
   if( (matrizC = (float **) malloc(la*sizeof(float *))) == NULL )/*verifica se ocorreu corretamente a alocaccao de memoria*/
   {/*para as linhas de C*/
      printf("Erro!!! Memoria Insuficiente para a alocaccao das linhas da Matriz C\n\n");
      exit(2);
   }         
   for(i = 0; i < la; i++)/*aloca memoria para as colunas de cada linha de A*/
      if( (*(matrizA + i) = (float *) malloc(ca*sizeof(float))) == NULL )/*testa se a alocaccao foi bem sucedida*/
      {
	 printf("Erro!!! Memoria Insuficiente para a alocaccao das colunas da Matriz A\n\n");
	 exit(2);
      }
   for(i = 0; i < lb; i++)/*aloca memoria para as colunas de cada linha de B*/
      if( (*(matrizB + i) = (float *) malloc(cb*sizeof(float))) == NULL )/*testa se a alocaccao foi bem sucedida*/
      {
	 printf("Erro!!! Memoria Insuficiente para a alocaccao das colunas da Matriz A\n\n");
	 exit(2);
      }
   for(i = 0; i < la; i++)/*aloca memoria para as colunas de cada linha de C*/
      if( (*(matrizC + i) = (float *) malloc(cb*sizeof(float))) == NULL )/*testa se a alocaccao foi bem sucedida*/
      {
	 printf("Erro!!! Memoria Insuficiente para a alocaccao das colunas da Matriz A\n\n");
	 exit(2);
      }

   printf("\nAs matrizes A e B podem ser multiplicadas ");
   printf("resultando uma matriz C[%huX%hu]\n\n",la,cb);

   for(i = 0; i < la; i++)
      for(j = 0; j < ca; j++)
      {
	 printf("Entre com o elemento A[%hu,%hu].: ",i,j);
	 scanf("%f",*(matrizA + i) + j);
      }
   for(i = 0; i < lb; i++)
      for(j = 0; j < cb; j++)
      {
	 printf("Entre com o elemento B[%hu,%hu].: ",i,j);
	 scanf("%f",*(matrizB + i) + j);
      }

   for(i = 0; i < la; i++)
      for(j = 0; j < cb; j++)
	 *(*(matrizC + i) + j) = 0.0;

      printf("\nMatriz A\n");
   for(i = 0; i < la; i++)
   {
      for(j = 0; j < ca; j++)
	 printf("%f ",*(*(matrizA + i) + j));
      printf("\n");
   }
   
   printf("\nMatriz B\n");
   for(i = 0; i < lb; i++)
   {
      for(j = 0; j < cb; j++)
	 printf("%f ",*(*(matrizB + i) + j));
      printf("\n");
   }

   printf("\nMatriz C \n");
   for(i = 0; i < la; i++)
   {
      for(j = 0; j < cb; j++)
	 printf("%f ",*(*(matrizC + i) + j));
      printf("\n");
   }

   for(i = 0; i < la; i++)
      for(j = 0; j < cb; j++)
	 for(k = 0; k < ca; k++)
	    *(*(matrizC + i) + j) += (*(*(matrizA + i) + k)) * (*(*(matrizB + k) + j));
   
   printf("\n\nMatriz C = A * B\n");
   for(i = 0; i < la; i++)
   {
      for(j = 0; j < cb; j++)
	 printf("%f ",*(*(matrizC + i) + j));
      printf("\n");
   }
   
   for(i = 0; i < la; i++)/*libera a memoria alocada para as colunas das linhas de A*/
      free(*(matrizA + i));
   for(i = 0; i < lb; i++)/*libera a memoria alocada para as colunas das linhas de B*/
      free(*(matrizB + i));
   for(i = 0; i < la; i++)/*libera a memoria alocada para as colunas das linhas de C*/
      free(*(matrizC + i));

   free(matrizA);/*libera a memora alocada para as linhas de A*/
   free(matrizB);/*libera a memora alocada para as linhas de B*/
   free(matrizC);/*libera a memora alocada para as linhas de C*/
   
   printf("\n\n");
   return 0;
}
