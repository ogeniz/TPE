#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int **ptr;
  int l;
  int c;
} IntMat;

void readInfo(IntMat *m);
int testDim(IntMat *m1, IntMat *m2, IntMat *m3);
int allocMat(IntMat *m);
void readMat(IntMat *m);
int multiMat(IntMat *m1, IntMat *m2, IntMat *m3);
void showMat(IntMat *m);
void freeMat(IntMat *m);

int main() {
  IntMat a, b, c;

  /* Ler as dimensões das matrizes a e b */
  readInfo(&a);
  readInfo(&b);
  /* Testar se as matrizes podem ser multiplicadas */
  /* Se não for possível, a função retorna FALSO e o porgrama acaba */
  /* Se for possível, a função calcula as dimensões da matriz c, e retorna VERDADEIRO */
  if(!testDim(&a, &b, &c)) {
    printf("As matrizes não podem ser multiplicadas.\n");
    exit(1);
  }
  /* Se VERDADEIRO, alocar matrizes a, b e c */
  /* Se não for possível alocar qualquer uma das matrizes o programa acaba */
  if(!allocMat(&a)) {
    printf("Erro na alocação de memória.\n");
    exit(1);
  }
  if(!allocMat(&b)) {
    printf("Erro na alocação de memória.\n");
    exit(1);
  }
  if(!allocMat(&c)) {
    printf("Erro na alocação de memória.\n");
    exit(1);
  }
  /* Ler os elementos das matrizes a e b */
  readMat(&a);
  readMat(&b);
  /* Multiplicar as matrizes a e b */
  multiMat(&a, &b, &c);
  /* Mostrar as três matrizes em forma tabular */
  showMat(&a);
  showMat(&b);
  showMat(&c);
  /* Liberar a mamória a locada */
  freeMat(&a);
  freeMat(&b);
  freeMat(&c);

  return 0;
}
