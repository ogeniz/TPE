/*Escreva um  programa que leia  um vetor de  inteiros pelo teclado  e o apresente  na  tela. Crie  uma  função
(void  LeVetor(int  *vet,  int dimensao))  para  fazer  a  leitura  do  vetor, e uma função
(void MostraVetor(int *vet, int dimensao)) para fazer a exibição do vetor.*/

#include <stdio.h>
#include <stdlib.h>

void LerVetor(int *, const unsigned);
void MostraVetor(const int *, const unsigned);

int main(void)
{
	int *vet = NULL;
	unsigned  dimensao = 0;
	printf("Entre com a dimensao do vetor de inteiros.:		");
	scanf("%u",&dimensao);	
	vet = (int *) malloc(dimensao*sizeof(int));
	LerVetor(vet,dimensao);
	MostraVetor(vet,dimensao);
	free(vet);		
	return 0;
}

void LerVetor(int *vet, const unsigned dimensao)
{
	unsigned int indice = 0;
	do
	{
		printf("Entre com o valor para vet[%u] = ", indice + 1);
		scanf("%i",(vet + indice));
		indice++;
	}while(indice <  dimensao);
}

void MostraVetor(const int *vet, const unsigned dimensao)
{
	unsigned int indice = 0;
	do
	{
		printf("vet[%u] = %i\n",indice + 1,*(vet + indice));
		indice++;
	}while(indice < dimensao);
}
