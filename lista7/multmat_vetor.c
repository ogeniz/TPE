/* Fazer um programa que multiplique duas matrizes, de tal forma que: o usuário entre com
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   /**************************declaraccao de variaveis***************************************/
   unsigned short la = 0, ca = 0, lb = 0, cb = 0;/*variaveis de linhas e colunas das matrizes*/
   unsigned char i,j,k;/*variaveis para controle de contagem*/
   float **matrizA, **matrizB, **matrizC;
   /**************************fim da declaraccao de variaveis***************************************/
   

   printf("\nEntre com os valores das linha e colunas das matrizes ");
   printf("no formato la ca lb cb.: ");
   scanf("%hd %hd %hd %hd",&la,&ca,&lb,&cb);
   
   if(la < 1 || ca < 1 || lb < 1 || cb < 1)
   {
      puts("Erro!!!! As linha e colunas de uma matriz devem ser numeros naturais");
      exit(1);
   }

   printf("\nA[%hdX%hd], B[%hdX%hd]\n\n",la,ca,lb,cb);

   return 0;
}    
