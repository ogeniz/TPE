#include <stdio.h>
#include <stdlib.h>
#include "pr12.h"

#define FALSE 0
#define TRUE 1

Lista *criar_lista_vazia(void)
{
   return NULL;
}

Lista *inserir_elemento_lista(Lista *lista,int info)
{
   Lista *new_node = (Lista *) malloc(sizeof(Lista));/*aloca novo no para a lista*/
   new_node->value = info;/*atribui ao campo value o valor passado a funcao*/
   new_node->next = lista;/*faz new_node->next receber o enderecco do primeiro elemento da lista*/
   return new_node;/*retorna o endereco do novo node a ser inserido no inicio da lista*/
}
Lista *retirar_elemento_lista(Lista *lista,int info)
{
   Lista *current = busca_elemento_lista(lista,info), *prev = lista;   
   if(current != NULL)/*chegou ao final da lista e nao encontrou o elemento com o valor procurado*/
      return prev; /*retorna lista original*/
   while(prev->next != current)
      prev = prev->next;/*procura o node anterior ao node a ser eliminado da lista*/
   prev->next = current->next;
   free(current);
   return lista;
}
char busca_elemento_lista(Lista *lista,int info)
{
   Lista *current = NULL ;
   
   for(current = lista; current != NULL; current = current->next)
      if(current->value == info)
         return current; /*retorna o enderecco do 1o node com o valor procurado*/
   return NULL;/*retorna NULL se valor nao foi encontrado*/   
}
void imprime_lista(Lista *lista)
{
   Lista *current = NULL;
   if(lista == NULL)
      printf("\nLista Vazia\n\n");
   else
   {
      printf("\n");
      for(current = lista; current != NULL; current = current->next)
         printf("%d -> ",current->value);
      printf("\n");
   }
}
void esvazia_lista(Lista *lista)
{
   Lista *current = lista, *prev = NULL;
   while(current != NULL)
   {
      prev = current;
      current = current->next;
      lista = current;
      free(prev);
   }
}


/*
while( (current != NULL) && (prev->value != info) )
      {
         prev = current;
         current = current->next; 
      }
   
      if(current == NULL) verifica se chegou ao final da lista
         return lista; valor nao encontrado, retorna lista original
   
      if(prev == NULL) retira elemento do inicio da lista
         lista = current->next;
      else retira elemento no meio da lista
         prev->next = current->next;
      free(current);
      return lista; retorna lista atualizada com valor retirado
*/
