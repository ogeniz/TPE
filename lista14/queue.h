#ifndef QUEUE_H
#define QUEUE_H

#define FALSE 0
#define TRUE 1
#define MAXQUEUE 16 /*0-15 itens na fila*/

struct queue
{
  int value;
  struct queue *next;
};
typedef struct queue Fila;

Fila *new_empty_queue(void);/**/
void enqueue(Fila **,unsigned char);/* (**fila, valor,número da fila) */
void dequeue(Fila **,unsigned char);
void empty_queue(Fila **,unsigned char);
void print_queue(Fila **,unsigned char);
void pr14(void);
unsigned char queue_size(Fila *);
unsigned char is_queue_empty(Fila *);
unsigned char is_queue_full(Fila *);
unsigned char aleatorio(void);
#endif
