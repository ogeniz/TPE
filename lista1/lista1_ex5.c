/* Fazer um algoritmo que leia o  tempo de duracao de um evento em uma
   fabrica expressa em segundos. E mostre-o expresso em horas, minutos
   e segundos.  */

#include <stdio.h>

int main(void)
{
  unsigned int seconds = 0, horas = 0, minutos, segundos = 0;
  printf("\n\nEntre com o tempo de duracao do evento em segundos : ");
  scanf("%u", &seconds);
  /*1o. Metodo*/
  horas = seconds / 3600; /*Transforma o valor total de segundos em horas*/
  minutos = ( seconds - (horas*3600) ) / 60; /*Converte o resto da divisão anterior em minutos*/
  segundos = seconds - 60*(horas*60 + minutos); /*O resto da divisão anterior será o valor dos segundos*/
  printf("%u segundos convertido para %uh %um %us\n\n",seconds, horas, minutos, segundos);
  /*2o. Metodo*/
  horas = seconds / 3600; /*Transforma o valor total de segundos em horas*/
  minutos = (seconds % 3600) / 60; /*Converte o resto da divisão anterior em minutos*/
  segundos = (seconds % 3600) % 60; /*O resto da divisão anterior será o valor dos segundos*/
  printf("%u segundos convertido para %uh %um %us\n\n",seconds, horas, minutos, segundos);
  return 0;
}
