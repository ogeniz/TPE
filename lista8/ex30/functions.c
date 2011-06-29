#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/*multiplica duas matrizes e guarda o resultado em uma matriz resultante*/
void multiplica_matrizes(void)
{
  Matriz matriz_A = {NULL,1,1}, matriz_B = {NULL,1,1}, matriz_Mult = {NULL,1,1};
  ushort i,j,k;
  uchar flag = TRUE;
  while(flag)
    {
      ler_matriz(&matriz_A);/*le valores para linha e coluna e aloca memoria para a matriz*/
      ler_matriz(&matriz_B);/*le valores para linha e coluna e aloca memoria para a matriz*/
      if(matriz_A.col != matriz_B.row)/*verifica se a multiplicaccao e possivel*/
	{
	  printf("\nErro o numero de linhas de colunas de A tem que ser igual ao numero de linhas de B\n");
	  libera_matriz(matriz_A.address, &(matriz_A.row));/*libera a memoria alocada anteriormente*/
	  libera_matriz(matriz_B.address, &(matriz_B.row));/*libera a memoria alocada anteriormente*/
	}
      else
	flag = FALSE;
    }
  preenche_matriz(&matriz_A);/*preenche as entradas da matriz com valores via teclado*/
  preenche_matriz(&matriz_B);/*preenche as entradas da matriz com valores via teclado*/
  matriz_Mult.row = matriz_A.row;
  matriz_Mult.col = matriz_B.col;
  matriz_Mult.address = aloca_matriz(&(matriz_Mult.row),&(matriz_Mult.col));/*aloca memoria para a matriz_Mult*/
  inicializa_matriz(&matriz_Mult);
  for(i = 0; i < matriz_Mult.row; i++)
    for(j = 0; j < matriz_Mult.col; j++)
      for(k = 0; k < matriz_A.col; k++)/*k < matriz_B->row tambem esta correto*/
	*(*(matriz_Mult.address + i) + j) += (*(*(matriz_A.address + i) + k)) * (*(*(matriz_B.address + k) + j));
  imprime_matriz(&matriz_A);
  imprime_matriz(&matriz_B);
  imprime_matriz(&matriz_Mult);
  libera_matriz(matriz_A.address,&(matriz_A.row));
  libera_matriz(matriz_B.address,&(matriz_B.row));
  libera_matriz(matriz_Mult.address,&(matriz_Mult.row));
}
/*Ler as linhas e colunas uma Matriz via teclado e aloca memoria para a mesma*/
void ler_matriz(Matriz *matriz)
{
   uchar flag = TRUE;
   while(flag)
   {
      printf("Entre com os valores da linha e coluna da Matriz.: ");
      scanf("%hu %hu",&(matriz->row),&(matriz->col));
      if( (matriz->row < 1) || (matriz->col < 1) )
	 printf("Erro as linhas e colunas de uma Matriz sao numeros naturais\n");
      else
	 flag = FALSE;
   }
   matriz->address = aloca_matriz(&(matriz->row),&(matriz->col));/*aloca memoria para a Matriz*/
}
/*preenche as entradas da matriz com valores via teclado*/
void preenche_matriz(Matriz *matriz)
{
   ushort i,j;
   for(i = 0; i < matriz->row; i++)
      for(j = 0; j < matriz->col; j++)
      {
				printf("Entre com um valor inteiro para M[%hu,%hu] = ",(ushort) (i + 1),(ushort) (j + 1));
				scanf("%i",*(matriz->address + i) + j);
      }
   printf("\n");
}
/*aloca memoria para uma Matriz*/
int **aloca_matriz(const ushort *row, const ushort *col)
{
   ushort i;
   int **address;
   if( (address = (int **) malloc((*row) * sizeof(int *))) == NULL )
   {
      printf("\nErro de alocaccao de memoria\n\n");
      exit(1);
   }
   for(i = 0; i < (*row); i++)
      if( (*(address + i) = (int *) malloc((*col) * sizeof(int))) == NULL )
      {
	 libera_matriz(address,row);
	 printf("\nErro de alocaccao de memoria");
	 exit(1);
      }
   return(address);
}
/*inicializa com 0 todas as entradas da Matriz*/
void inicializa_matriz(Matriz *matriz)
{
   ushort i,j;
   for(i = 0; i < matriz->row; i++)
      for(j = 0; j < matriz->col; j++)
	 *(*(matriz->address + i) + j) = 0;
}
/*imprime uma matriz na forma tabular*/
void imprime_matriz(const Matriz *matriz)
{
   ushort i,j;
   printf("\n");
   for(i = 0; i < matriz->row; i++)
   {
      for(j = 0; j < matriz->col; j++)
	 printf("%i ",*(*(matriz->address + i) + j));
      printf("\n");
   }
   printf("\n");
}
/*libera a memoria alocada para as linhas e colunas de uma matriz*/
void libera_matriz(int **address, const ushort *row)
{
   ushort i;
   for(i  = 0; i < (*row); i++)
      free(*(address + i));
   free(address);
}
