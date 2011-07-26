/*Ler um número inteiro, calcular e escrever quantos divisores ele possui.*/

#include <stdio.h>

int main(void)
{
	int indice,num,div=0;
	printf("\nEntre com um número inteiro qualquer.: ");
	scanf("%i",&num);
	if(!num)
		printf("0 eh divisivel por todo o conjunto dos inteiros\n\n");
	else
		{
			if(num > 0)
				for(indice = num; indice > 0; indice--)
					{
						if(!(num%indice))
							{
								div++;
								printf("%i e %i ",(-1)*indice,indice);
							}
					}
			else
				for(indice = num; indice < 0; indice++)
					if(!(num%indice))
						{
							div++;
							printf("%i e %i ",indice,(-1)*indice);
						}
		}
	printf("\nO %i possui %i divisores\n\n",num,2*div);
	return 0;
}
