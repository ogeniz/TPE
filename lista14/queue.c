#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "queue.h"

Fila *new_empty_queue(void)
{
  return NULL;
}

void enqueue(Fila **fila,unsigned char n_fila)/* (**fila, valor,número da fila) */
{
   if(!is_queue_full(*(fila + n_fila)))
   {
      Fila *new_node = (Fila *) malloc(sizeof(Fila));/*aloca novo node para a fila*/
      static unsigned info = 10;
      new_node->value = ++info;
      new_node->next = *(fila + n_fila);/*insere no inicio da fila*/
      printf("\nEnfileirando cliente %d na fila %d\n",new_node->value,n_fila + 1);
      *(fila + n_fila) = new_node;
   }
   else
      printf("\nFila %d cheia\n",n_fila + 1);
}

void dequeue(Fila **fila, unsigned char n_fila)
{
   if(is_queue_empty(*(fila + n_fila)))
      printf("\nFila %d vazia\n",n_fila + 1);
   else
   {
      Fila *end = *(fila + n_fila), *aux = *(fila + n_fila);
      if(aux->next == NULL)
      {
         printf("\nO Cliente %d atendido na fila %d\n",aux->value,n_fila + 1);/*imprime o item eliminado da fila*/
         free(aux);/*elimina o node da lista*/
         *(fila + n_fila) = new_empty_queue();
      }
      else
      {
         while(aux->next != NULL)/*o mesmo que begin != NULL*/ /*precorre a fila*/
            aux = aux->next;
         while(end->next != aux)
            end = end->next;
         end->next = NULL;
         printf("\nO Cliente %d atendido na fila %d\n",aux->value,n_fila + 1);/*imprime o item eliminado da fila*/
         free(aux);/*elimina o node da lista*/
      }
   }
}

void empty_queue(Fila ** fila,unsigned char n_fila)
{
   unsigned char j = 0, k = 0;
   k = queue_size(*(fila + n_fila));
   for(j = 0; j < k; j++)
      dequeue(fila,n_fila);
}

unsigned char is_queue_empty(Fila *fila)
{
   if(fila == NULL)/*mesmo que begin == NULL*/ /*fila vazia*/
      return TRUE;
   else
      return FALSE;/*fila com elementos a serem retirados*/
}

unsigned char is_queue_full(Fila *fila)
{
   unsigned char size = queue_size(fila);
   if(size < MAXQUEUE)/*verifica se a fila está cheia*/
      return FALSE;/*se for possivel acrescentar valores na fila*/
   else
      return TRUE;/*se a fila estiver cheia*/
}

unsigned char queue_size(Fila *fila)
{
   Fila *begin = NULL;/*node aponta para o inicio da fila*/
   unsigned char count = 0;/*variavel de contagem*/
   for(begin = fila; begin != NULL; begin = begin->next)/*percorre a fila*/
      count++;/*acumula a quantidade de nodes na fila*/
   return count;/*retorna o numero de elementos na fila*/
}

void print_queue(Fila **fila,unsigned char n_fila)
{
   if(is_queue_empty(*(fila + n_fila)))
      printf("\nFila %d vazia\n",n_fila + 1);
   else
   {
     Fila *begin = *(fila + n_fila);
     printf("\n");
      while(begin)/*mesmo que begin != NULL*/
      {
         printf("%d -> ",begin->value);
         begin = begin->next;
      }
      printf("CAIXA são %hu elementos na lista %d\n",queue_size(*(fila + n_fila)),n_fila + 1);
   }
}

unsigned char aleatorio_fila(void)
{
  struct timeval tempo;/*estrutura que armazena a hora*/
  gettimeofday(&tempo, 0);/*pega a hora atual*/
  srand(tempo.tv_usec);/*hora atual convertida em milisegundos */
  return(rand() % 5);/* retorna um numero entre 0 e 4 */
}


void pr14(void)
{
   Fila *fila[5] = {new_empty_queue(),new_empty_queue(),new_empty_queue(),new_empty_queue(),new_empty_queue()};
   unsigned char i = 0, j = 0;
   while(i < 50)
   {
      enqueue(fila,aleatorio_fila());
      dequeue(fila,aleatorio_fila());
      for(j = 0; j < 5; j++)
        print_queue(fila,j);
      i++;
   }
   for(i = 0; i < 5; i++)
      print_queue(fila,i);
   for(i = 0; i < 5; i++)
      empty_queue(fila,i);
   for(i = 0; i < 5; i++)
     print_queue(fila,i);
}
