/*O Índice de  Massa Corporal (IMC) é uma medida  do grau de obesidade
  uma pessoa.  Através do  cálculo do IMC  é possível saber  se alguém
  está  acima  ou  abaixo  dos  parâmetros ideais  de  peso  para  sua
  estatura. Calcular IMC requer a aplicação de uma fórmula que leva em
  conta seu  peso e altura.   IMC = peso /(altura*altura)  */

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct
{
   double peso;
   double altura;
   double imc;
}Register;

int main(void)
{
   unsigned dimensao = 0;/*numero de elementos do vetor de Register*/
   unsigned i;/*indice de contagem*/
   unsigned char flag = TRUE;/*flag de controle da repeticcao da entrada de dados*/
   Register *vetor = NULL;

   while(flag)
   {
      scanf("%u",&dimensao);/*entrada do numero de elementos do vetor*/
      if(dimensao)
      {
	 if((vetor = (Register *) malloc(dimensao*sizeof(Register))) == NULL )/*aloca memoria e testa o sucesso para um vetor de Register*/
	 {
	    printf("\nErro de alocaccao de memoria\n\n");
	    exit(1);
	 }
	 for(i = 0; i < dimensao; i++)/*insere dados no vetor de Register*/
	 {
	    scanf("%lf %lf",&(vetor + i)->peso,&(vetor + i)->altura);
	    (vetor + i)->imc = (vetor + i)->peso / ( (vetor + i)->altura * (vetor + i)->altura );/*calcula o imc e atribui ao campo imc 
												   da estrutura de cada elemento do vetor de Register*/
	 }
	 
	 printf("\n");
	 for(i = 0; i < dimensao; i++)/*imprime os valores armazenados em cada elemento do vetor de Register*/
	 {
	    if( (vetor + i)->imc < 18.5 )
	       printf("%.2lf %.2lf %.2lf %s\n",(vetor + i)->peso,(vetor + i)->altura,(vetor + i)->imc,"Abaixo do Peso");
	    if( (vetor + i)->imc >= 18.5 && (vetor + i)->imc < 25.0)
	       printf("%.2lf %.2lf %.2lf %s\n",(vetor + i)->peso,(vetor + i)->altura,(vetor + i)->imc,"Peso Normal");
	    if( (vetor + i)->imc >= 25.0 && (vetor + i)->imc < 30.0)
	       printf("%.2lf %.2lf %.2lf %s\n",(vetor + i)->peso,(vetor + i)->altura,(vetor + i)->imc,"Acima do Peso");
	    if( (vetor + i)->imc >= 30.0 && (vetor + i)->imc < 35.0)
	       printf("%.2lf %.2lf %.2lf %s\n",(vetor + i)->peso,(vetor + i)->altura,(vetor + i)->imc,"Obesidade Grau I");
	    if( (vetor + i)->imc >= 35.0 && (vetor + i)->imc < 40.0)
	       printf("%.2lf %.2lf %.2lf %s\n",(vetor + i)->peso,(vetor + i)->altura,(vetor + i)->imc,"Obesidade Grau II");
	    if( (vetor + i)->imc >= 40.0 )
	       printf("%.2lf %.2lf %.2lf %s\n",(vetor + i)->peso,(vetor + i)->altura,(vetor + i)->imc,"Obesidade Grau III");
	 }
	 free(vetor);/*libera memoria alocada para o vetor de Register*/
	 printf("\n");
      }
      else
	 flag = FALSE;
   }
   return 0;
}
