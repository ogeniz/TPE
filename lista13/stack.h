#ifndef PILHA_H
#define PILHA_H

#define FALSE 0
#define TRUE 1
#define MAXSTACK 2

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
void print_stack(Stack *);

#endif
