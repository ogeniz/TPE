/* Fazer um programa em C  que preencha um vetor com letras minusculas
 e,  atraves  de  um  vetor   de  ponteiros,  altere  as  letras  para
 maiúsculas. Para  alterar as letras  do vetor de  caracteres, deve-se
 utilizar o vetor de ponteiros.*/

#include <stdio.h>
#include <string.h>

int main(void)
{
   char nome[] = "abcdefghijklmnopqrstuvwxyz"; /*declaraccao e inicializaccao do vetor de caracteres*/
   unsigned char i = 0; /*variavel de contagem*/
   const unsigned char aux = strlen(nome) - 1; /*comprimento da string*/
   char *vetor[aux]; /*vetor de ponteiros*/
   
   printf("\n"); /*novalinha*/
   
   for(; i <= aux; i++) /*percorre todo o vetor de caracteres*/
      vetor[i] = (nome + i); /*cada elem. do vetor de ponteiros aponta para um caracter*/
   
   for(i = 0; i <= aux; i++) /*imprime a string nome atraves do vetor de ponteiros*/
      printf("*(vetor[%i]) = %c \t 0x%X %i \t vetor[%i] -> %p\n",i,*vetor[i],*vetor[i],*vetor[i],i,vetor[i]);
   
   printf("\n"); /*nova linha*/
   
   for(i = 0; i <= aux; i++) /*percorre todo o vetor de ponteiros*/
      *vetor[i] = *vetor[i] & 0xdf;/*torna os caractere minusculos em maiusculos*/
   
   for(i = 0; i <= aux; i++) /*percorre todo o vetor de ponteiros*/
      printf("*(vetor[%i]) = %c \t 0x%X %i \t vetor[%i] -> %p\n",i,*vetor[i],*vetor[i],*vetor[i],i,vetor[i]);
   /*imprime a string nome atraves do vetor de ponteiros*/
   
   printf("\n"); /*novalinha*/
   
   for(i = 0; i <= aux; i++) /*percorre todo o vetor de ponteiros*/
      printf("&(vetor[%i]) = %p\n",i,(void *) &vetor[i]); /*imprime o endereco de cada elemento do vetor de ponteiros*/
   
   printf("\n"); /*novalinha*/
   
   return 0;
}
