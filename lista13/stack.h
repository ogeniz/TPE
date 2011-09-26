#ifndef PILHA_H
#define PILHA_H

#define FALSE 0
#define TRUE 1
#define MAXSTACK 16 /*0-15 itens na pilha*/

struct stack
{
  float value;
  struct stack *next;
};
typedef struct stack Stack;

Stack *create_stack(void);
Stack *create_stack_node(void);
Stack *push(Stack *,float);
Stack *pop(Stack *);
Stack *empty_stack(Stack *);
unsigned char is_stack_empty(Stack *);
unsigned char stack_size(Stack *);
unsigned char is_stack_full(Stack *);
void print_stack(Stack *);
void pr13(void);
#endif
