#include <stdio.h>
#include <stdlib.h>
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
      printf("Empilhando %.2f",new_topo->value);
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
      printf("NULL são %hu elementos na pilha\n",stack_size(pilha));
   }
}
