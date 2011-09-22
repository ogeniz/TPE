#ifndef PR12_H
#define PR12_H

struct List
{
  int value;
  struct List *next;
};
typedef struct List Lista;

Lista *criar_lista_vazia(void);
Lista *inserir_elemento_lista(Lista *,int);
Lista *retirar_elemento_lista(Lista *,int);
char busca_elemento_lista(Lista *,int);
void esvazia_lista(Lista *);
void imprime_lista(Lista *);

#endif
