#ifndef AP3_H
#define AP3_H

#define FALSE 0
#define TRUE 1

typedef struct
{
  int codigo;
  char descricao[25];
  int setor_de_venda;
  float valor_unitario;
}Produto;

void ap(void);
#endif
