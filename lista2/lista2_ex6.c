/*Escrever um algoritmo que l� o instante do in�cio e do t�rmino do jogo, ambos subdivididos em
  2 valores distintos, a saber: horas e minutos. Calcular e escrever a dura��o do jogo, tamb�m
  em horas e minutos, considerando que o tempo m�ximo de dura��o de um jogo � de 24 horas
  e que o jogo pode iniciar em um dia e terminar no dia seguinte.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   short hora,minuto,inicio,fim,duracao;

   printf("Entre com o horario de inicio de um jogo, ");
   printf("no formato hh:mm\n");
   scanf("%hi:%hi",&hora,&minuto);
   inicio = (hora*60) + minuto;

   printf("Entre com o horario do fim de um jogo, ");
   printf("no formato hh:mm\n");
   scanf("%hi:%hi",&hora,&minuto);

   fim = (hora*60) + minuto;

   duracao = fim - inicio;

   if(!duracao)
   {
      printf("\nA duracao do jogo foi de 24:00\n\n");
      return 0;
   }

   if(duracao < 0)
      duracao = (1440 + fim) - inicio;
   
   printf("\n A duracao do jogo foi de %hi:%hi\n\n",duracao/60,duracao%60);
   
   return 0;
}
