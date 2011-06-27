/* Criar uma struct chamada Ponto, contendo apenas as posições x e y (inteiros) do ponto. Declarar dois pontos, ler as posições das coordenadas
   x e y de cada um e calcule a distância entre os dois pontos entre estes através de uma função. Apresentar no final a distância entre os dois
   pontos . */

#include <stdio.h>
#include <math.h>

typedef struct /* Definição da estrutura Ponto */
{
   int x;
   int y;
}Ponto;

float distancia(const Ponto *, const Ponto *);

int main(void)
{
   Ponto p1 = {0,0}, p2 = {0,0}; /* Declaração de dois pontos e inicialiazados com (0,0) */
   printf("Entre com as coordenadas dos pontos P1 e P2, ");
   printf("na forma x1 y1 x2 y2.\nCom x1, y1, x2 e y2 valores inteiros ");
   scanf("%d %d %d %d",&p1.x,&p1.y,&p2.x,&p2.y);
   printf("A distancia entre (%d,%d) e (%d,%d) eh ",p1.x,p1.y,p2.x,p2.y);
   printf("%.2f\n\n",distancia(&p1,&p2));
   return 0;
}

float distancia(const Ponto *p1, const Ponto *p2)
{
   float dist = sqrt((p2->x - p1->x)*(p2->x - p1->x) + (p2->y - p1->y)*(p2->y - p1->y));
   return dist;
}
