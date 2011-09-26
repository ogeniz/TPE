#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

Stack *create_stack(void)/*cria pilha vazia*/
{
   return NULL;
}

Stack *push(Stack *pilha, float info)/*empilha novo node*/
{
   Stack *new_topo = NULL;
   unsigned char size_stack = stack_size(pilha);
   
   if( !(size_stack == MAXSTACK) )
   {
      if( (new_topo = create_stack_node()) == NULL )
      {
         perror("\nErro de Alocaccao de Memoria\n\n");  
         return pilha;
      }
      printf("\n");
      new_topo->value = info;/*atribui ao campo value o valor passado a funcao*/
      new_topo->next = pilha;/*empilha new_node na pilha*/
      printf("Empilhando %.2f\n",new_topo->value);
      return new_topo;
   }
   perror("\nStack Overflow\n\n");
   return pilha;
}

Stack *empty_stack(Stack *pilha)
{
   Stack *topo = pilha;
   if(is_stack_empty(topo))
      return topo;
   while(topo != NULL)
      topo = pop(topo);
   return topo;
}

Stack *pop(Stack *pilha)/*desempilha o topo da pilha*/
{
   Stack *topo = pilha, *aux = pilha;
   if(is_stack_empty(pilha))/*verifica se a pilha esta vazia*/
   {
      perror("\nEmpty Stack\n\n");/*pilha vazia*/
      return pilha;
   }
   topo = aux->next;/*faz com que o topo aponte para o proximo elemento da pilha*/
   printf("\nliberando %.2f\n",aux->value);/*imprime valor eliminado no topo da pilha*/
   free(aux);/*libera a memoria do topo anterior*/
   return topo;/*atualiza o topo da pilha*/
   
}

Stack *create_stack_node(void)/*cria node para ser empilhado*/
{
   Stack *topo = NULL;
   if( (topo = (Stack *) malloc(sizeof(Stack))) == NULL )
      return NULL;/*retorna NULL se ocorrer erro na alocaccao*/
   return topo;/*retorna o enderecco do bloco de memoria alocado para o new_node*/
}

unsigned char is_stack_empty(Stack *pilha)/*verifica se a pilha esta vazia*/
{
   Stack *topo = pilha;
   if(topo == NULL)/*pilha vazia*/
      return 1;
   else /*pilha com pelo menos 1(um) elemento*/
      return 0;
}

unsigned char is_stack_full(Stack *pilha)
{
   unsigned char size = stack_size(pilha);/*avalia o tamanho da pilha*/
   if(size < 16)/*verifica se a pilha está cheia*/
      return 0;/*se for possivel acrescentar valores na pilha*/
   else
      return 1;/*se a pilha estiver cheia*/
}

unsigned char stack_size(Stack *pilha)
{
   Stack *topo = NULL;/*node aponta para o topo da pilha*/
   unsigned char count = 0;/*variavel de contagem*/
   for(topo = pilha; topo != NULL; topo = topo->next)/*percorre a pilha*/
      count++;/*acumula a quantidade de nodes na pilha*/
   return count;/*retorna o numero de elementos na pilha*/
}

void print_stack(Stack *pilha)
{
   Stack *topo = pilha;
   if(is_stack_empty(topo))
      printf("\nEmpty Stack\n\n");
   else
   {
      printf("\n");
      while(topo != NULL)
      {
         printf("%.2f -> ",topo->value);
         topo = topo->next;
      }
      printf("NULL são %u elementos na pilha\n",stack_size(pilha));
   }
}

void pr13(void)
{
   Stack *pilha = create_stack();
   float sum = 0, sub = 0, mult = 0, frac = 0.0;
   char line[MAXSTACK], *substring;
   unsigned char i = 0, j = sizeof(line), flag = TRUE;

   while(flag)
   {
      i = 0;
      while(i < j)
      {
         *(line + i) = fgetc(stdin);
         if(*(line + i) == 0xa)
            break;
         i++;
      }
      *(line + i) = '\0';
      
      if(!strcmp(line,"quit")) /*finaliza o lacco principal*/
      {
         flag = FALSE;
         continue;
      }
      if(!strcmp(line,"print")) /*exibe o status da pilha*/
         print_stack(pilha);
         
      substring = strtok(line," ");/*a funccao strtok divide a string em substrings com o " " como separado*/
      while(substring != NULL)
      {
         if(*(substring) == 0x5f)/* _ */
            pilha = push(pilha,-atof(substring + 1));
         
         if(isdigit(*substring))
            pilha = push(pilha,atof(substring));
         
         if(*(substring) == 0x2b)/* + */
         {
            if(stack_size(pilha) < 2)
            {
               printf("\nQuantidade insuficiente de valores na pilha para fazer qualquer operaccao\n");
               break;
            }
            else
            {
               sum = pilha->value + pilha->next->value;
               printf("\n\n%.2f + %.2f = %.2f\n\n",pilha->value,pilha->next->value,sum);
               i = 0;
               while(i < 2)
               {
                  pilha = pop(pilha);
                  i++;
               }
               pilha = push(pilha,sum);
            }
            print_stack(pilha);
         }
         if(*(substring) == 0x2d)/* - */
         {
            if(stack_size(pilha) < 2)
            {
               printf("\nQuantidade insuficiente de valores na pilha para fazer qualquer operaccao\n");
               break;
            }
            else
            {
               sub = pilha->value - pilha->next->value;
               printf("\n\n%.2f - %.2f = %.2f\n\n",pilha->value,pilha->next->value,sub);
               i = 0;
               while(i < 2)
               {
                  pilha = pop(pilha);
                  i++;
               }
               pilha = push(pilha,sub);
            }
            print_stack(pilha);
         }
         if(*(substring) == 0x2a)/* * */
         {
            if(stack_size(pilha) < 2)
            {
               printf("\nQuantidade insuficiente de valores na pilha para fazer qualquer operaccao\n");
               break;
            }
            else
            {
               mult = pilha->value * pilha->next->value;
               printf("\n\n%.2f * %.2f = %.2f\n\n",pilha->value,pilha->next->value,mult);
               i = 0;
               while(i < 2)
               {
                  pilha = pop(pilha);
                  i++;
               }
               pilha = push(pilha,mult);
            }
            print_stack(pilha);
         }
         if(*(substring) == 0x2f)/* / */
         {
            if(stack_size(pilha) < 2)
            {
               printf("\nQuantidade insuficiente de valores na pilha para fazer qualquer operaccao\n");
               break;
            }
            else
            {
               frac = pilha->value / pilha->next->value;
               printf("\n\n%d / %d = %f\n\n",(int) pilha->value,(int) pilha->next->value,frac);
               i = 0;
               while(i < 2)
               {
                  pilha = pop(pilha);
                  i++;
               }
               pilha = push(pilha,frac);
            }
            print_stack(pilha);
         }
         substring = strtok(NULL," ");/*instrui a funccao a contiuar a partir da chamada anterior*/
      }
      if(is_stack_full(pilha))
         pilha = empty_stack(pilha);
   }
   pilha = empty_stack(pilha);
}
