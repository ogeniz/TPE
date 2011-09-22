#include <stdio.h>
#include "pr12.h"

int main(void)
{
  Lista *lista = criar_lista_vazia();

  lista = inserir_elemento_lista(lista,10);
  lista = inserir_elemento_lista(lista,20);
  lista = inserir_elemento_lista(lista,30);
  
  imprime_lista(lista);
  
  lista = retirar_elemento_lista(lista,10);
  
  imprime_lista(lista);

  lista = retirar_elemento_lista(lista,20);

  imprime_lista(lista);

  esvazia_lista(lista);


  return 0;
}
