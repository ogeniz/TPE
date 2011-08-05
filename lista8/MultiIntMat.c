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
void readInfo(IntMat *m)
{
	 printf("Entre com os valores da linha e coluna da Matriz.: ");
	 scanf("%i %i",&(m->l),&(m->c));
}
int testDim(IntMat *m1, IntMat *m2, IntMat *m3)
{
	 if(m1->c != m2->l)
			return 0;
	 else
	 {
			m3->l = m1->l;
			m3->c = m2->c;
			return 1;
	 }
}
int allocMat(IntMat *m)
{
	 int i;
	 if( (m->ptr = (int **) malloc((m->l)*sizeof(int *))) == NULL )
			return 0;
	 else
			for(i = 0; i < (m->l); i++)
				 if( (*(m->ptr + i) = (int *) malloc((m->c) * sizeof(int))) == NULL )
				 {
						freeMat(m);
						return 0;
				 }
	 return 1;
}
void freeMat(IntMat *m)
{
	 int i;
	 for(i  = 0; i < (m->l); i++)
      free(*(m->ptr + i));
   free(m->ptr);
}
