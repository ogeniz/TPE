#include <stdio.h>
#include "stack.h"

int main(void)
{
  Stack *pilha = create_stack();
  float sum = 0.0, div = 0.0;

  pilha = push(pilha,10);
  pilha = push(pilha,20);
  printf("\n");
  print_stack(pilha);

  sum = pilha->value + pilha->next->value;

  pilha = empty_stack(pilha);

  pilha = push(pilha,sum);
  pilha = push(pilha,25.0);
  printf("\n");
  print_stack(pilha);

  div = pilha->next->value / pilha->value;

  pilha = empty_stack(pilha);

  pilha = push(pilha,div);
  printf("\n");
  print_stack(pilha);

  pilha = pop(pilha);

  return 0;
}
