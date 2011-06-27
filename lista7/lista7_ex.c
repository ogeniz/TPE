#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef unsigned char uchar;/*define unsigned char como uchar*/

int main(void)
{
   uchar i,j,k,flag = TRUE;/*variaveis de controle de lacco*/
   short la,ca,lb,cb;/*dimensoes das matrizes*/
   float **matrizA, **matrizB, **matrizC; /*ponteiros para as matrizes*/
   
   while(flag) /*repete a entrada ate que o usuario entre com dados validos*/
   {
      printf("Entre com os valores do das linhas e colunas ");
      printf("das matrizes a serem multiplicadas, na forma ");
      printf("la ca lb cb.: ");
      scanf("%hd %hd %hd %hd",&la,&ca,&lb,&cb);
      if( (la*ca*lb*cb) <= 0 )/*testa se as dimensoes das matrizes sao numeros naturais*/
      {
	 printf("\nErro!!! As dimensoes das matrizes devem ser numeros naturais\n\n");
	 continue; /*retorna para o inicio do lacco*/
      }
      if(ca != lb)
      {
	 printf("\nErro!!! O numero de colunas de A tem que ser o mesmo das linhas de B\n\n");
	 continue;
      }
      flag = FALSE;/*condiccao de saida do lacco*/
   }
   
   if( (matrizA = (float **) malloc(la*sizeof(float *))) == NULL ) /*testa se a alocaccao de memoria ocorreu corretamente*/
   {
      printf("\nErro!!! Nao foi possivel alocar memoria para a Matriz A[%hd,%hd]\n\n",la,ca);
      exit(1);
   }
   printf("\nMemoria alocada para a matriz A[%hd,%hd]\n",la,ca);
   if( (matrizB = (float **) malloc(lb*sizeof(float *))) == NULL )
   {
      printf("\nErro!!! Nao foi possivel alocar memoria para a Matriz B[%hd,%hd]\n\n",lb,cb);
      exit(1);
   }
   printf("\nMemoria alocada para a matriz B[%hd,%hd]\n",lb,cb);
   if( (matrizC = (float **) malloc(la*sizeof(float *))) == NULL )
   {
      printf("\nErro!!! Nao foi possivel alocar memoria para a Matriz C[%hd,%hd]\n\n",la,cb);
      exit(1);
   }
   printf("\nMemoria alocada para a matriz C[%hd,%hd]\n\n",la,cb);
   
   for(i = 0; i < la; i++)/*processo de alocaccao de memoria para as linhas da matriz*/
   {
      if( (*(matrizA + i) = (float *) malloc(ca*sizeof(float))) == NULL )/*teste para verificar se a alocaccao ocorreu corretamente*/
      {
	 printf("\nErro!!! Nao foi possivel alocar memoria para a matriz A[%hd,%hd]\n\n",la,ca);
	 exit(1);
      }
      printf("\nMemoria alocada para a %da. linha de A",i+1);
   }
   for(i = 0; i < lb; i++)
   {
      if( (*(matrizB + i) = (float *) malloc(cb*sizeof(float))) == NULL )
      {
	 printf("\nErro!!! Nao foi possivel alocar memoria para a matriz B[%hd,%hd]\n\n",lb,cb);
	 exit(1);
      }
      printf("\nMemoria alocada para a %da. linha de B",i+1);
   }
   for(i = 0; i < la; i++)
      if( (*(matrizC + i) = (float *) malloc(cb*sizeof(float))) == NULL )
      {
	 {
	    printf("\nErro!!! Nao foi possivel alocar memoria para a matriz C[%hd,%hd]\n\n",la,cb);
	    exit(1);
	 }
	 printf("\nMemoria alocada para a %da. linha de C",i+1);
      }

   printf("\n\nA[%hd,%hd]*B[%hd,%hd] = C[%hd,%hd]\n\n",la,ca,lb,cb,la,cb); /*imprime as dimensoes das matrizes*/

   for(i = 0; i < la; i++) /*inicializa as matrizes com 0.0*/
      for(j = 0; j < ca; j++)
	 *(*(matrizA + i) + j) = 0.0;
   for(i = 0; i < lb; i++)
      for(j = 0; j < cb; j++)
	 *(*(matrizB + i) + j) = 0.0;
   for(i = 0; i < la; i++)
      for(j = 0; j < cb; j++)
	 *(*(matrizC + i) + j) = 0.0;
   
   for(i = 0; i < la; i++)/*entrada de valores para cada posiccao da matriz*/
      for(j = 0; j < ca; j++)
      {
	 printf("Entre com o valor da posiccao A[%hd,%hd] = ",i+1,j+1);
	 scanf("%f",*(matrizA + i) + j);
      }
   for(i = 0; i < lb; i++)
      for(j = 0; j < cb; j++)
      {
	 printf("Entre com o valor da posiccao B[%hd,%hd] = ",i+1,j+1);
	 scanf("%f",*(matrizB + i) + j);
      }
   printf("\n");
   
   for(i = 0; i < la; i++)/*multiplica as matrizes A e B e guarda o resultado na matriz C*/
      for(j = 0; j < cb; j++)
	 for(k = 0; k < ca; k++)
	    *(*(matrizC + i) + j) += (*(*(matrizA + i) + k)) * (*(*(matrizB + k) + j));
   
   for(i = 0; i < la; i++) /*imprime na tela a matriz*/
   {
      for(j = 0; j < ca; j++)
	 printf("A[%hd,%hd] = %.2f ",i+1,j+1,*(*(matrizA + i) + j));
      printf("\n");
   }
   printf("\n");
   for(i = 0; i < lb; i++)
   {
      for(j = 0; j < cb; j++)
	 printf("B[%hd,%hd] = %.2f ",i+1,j+1,*(*(matrizB + i) + j));
      printf("\n");
   }
   printf("\n");
   for(i = 0; i < la; i++)
   {
      for(j = 0; j < cb; j++)
	 printf("C[%hd,%hd] = %.2f ",i+1,j+1,*(*(matrizC + i) + j));
      printf("\n");
   }
   printf("\n");
   
   for(i = 0; i < la; i++) /*libera a memoria alocada para as linhas da matriz*/
   {
      free(*(matrizA + i));
      printf("\nMemoria para a %da. linha de A liberada",i+1);
   }
   for(i = 0; i < lb; i++)
   {
      free(*(matrizB + i));
      printf("\nMemoria para a %da. linha de B liberada",i+1);
   }
   for(i = 0; i < la; i++)
   {
      free(*(matrizC + i));
      printf("\nMemoria para a %da. linha de C liberada",i+1);
   }
   printf("\n\n");
   
   free(matrizA); /*libera a memoria alocada para a matriz*/
   free(matrizB);
   free(matrizC);
   return 0;
}
