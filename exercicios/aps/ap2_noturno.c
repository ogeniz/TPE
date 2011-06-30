/*  Utilizando a  estrutura abaixo  definida, alocar  dinamicamente um
	vetor cuja  quantidade de elementos  será lida via teclado.  Leia os
	elementos  do vetor  via  teclado.  Aloque um  segundo  vetor com  a
	dimensão igual ao dobro do  vetor lido. Preencha o segundo vetor com
	os elementos do primeiro repetindo cada lemento.  */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uchar;
typedef unsigned uint;

typedef struct
{
	int *ptr;
	int dim;
}Vector;


int main(void)
{
	 Vector vector1,vector2;
	 uchar i,j;
	 
	 printf("Entre com a dimensão do vetor.: ");
	 scanf("%d",&(vector1.dim));
	 vector2.dim = (vector1.dim) << 1;

	 vector1.ptr = (int *) malloc((vector1.dim) * sizeof(int));
	 vector2.ptr = (int *) malloc((vector2.dim) * sizeof(int));
	 
	 for(i = 0; i < (vector1.dim); i++)
	 {
			printf("Entre com um valor inteiro para vector[%d].: ",i + 1);
			scanf("%i",(vector1.ptr + i));
	 }
	 for(i = 0, j = 0; i < (vector1.dim); i++, j+=2)
	 {
			*(vector2.ptr + j) = *(vector1.ptr + i);
			*(vector2.ptr + (j + 1)) = *(vector1.ptr + i);
	 }
	 printf("\n");

	 for(i = 0; i < (vector1.dim); i++)
			printf("vector1[%d] = %i\n",i + 1,*(vector1.ptr + i));
	 for(i = 0; i < (vector2.dim); i++)
			printf("vector1[%d] = %i\n",i + 1,*(vector2.ptr + i));
	 printf("\n");
			
	 free(vector1.ptr);
	 free(vector2.ptr);
	 return 0;
}
