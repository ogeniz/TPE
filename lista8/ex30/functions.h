#include <stdio.h>
#include <stdlib.h>

#ifndef FUNCCOES_H
#define FUNCCOES_H

#define FALSE 0
#define TRUE 1

typedef unsigned short ushort;
typedef unsigned char uchar;

typedef struct
{
   int **address;
   ushort row;
   ushort col;
}Matriz;


void ler_matriz(Matriz *);
void preenche_matriz(Matriz *);
void inicializa_matriz(Matriz *);
int **aloca_matriz(const ushort *, const ushort *);
void multiplica_matrizes(void);
void imprime_matriz(const Matriz *);
void libera_matriz(int **, const ushort *);

#endif
