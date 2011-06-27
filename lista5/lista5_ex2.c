/*Crie  uma estrutura  chamada retângulo,  que possua  duas estruturas
Ponto – do  exercício anterior - (o ponto superior  esquerdo e o ponto
inferior  direito).  Faça um  programa  que  receba  (via teclado)  as
informações acerca de um retângulo (as coordenadas dos dois pontos), e
informe  dados  interessantes  sobre  o  retângulo,  como  a  área,  o
comprimento da diagonal e o comprimento de cada aresta.*/

#include <stdio.h>
#include <math.h>

typedef struct /* Definição da estrutura Ponto */
{
   int x; /* Coordenada X */
   int y; /* Coordenada Y */
}Ponto;

typedef struct /* Definição da estrutura Retangulo*/
{
   Ponto pse; /* Ponto superior esquerdo */
   Ponto pie; /* Ponto inferior esquerdo (r1.pse.x,r1.pid.y) */
   Ponto psd; /* Ponto superior direito (r1.pid.x,r1.pse.y) */
   Ponto pid; /* Ponto inferior direito */
}Retangulo;

float distancia(const Ponto *,const Ponto *); /* Calcula e retorna a distancia entre dois pontos dados */
void retangulocompleto(const Ponto *, const Ponto *, Retangulo *); /* Completa o restante das coordenadas usando os dados do usuário*/
void printretangulo(const Retangulo *); /* Imprime na tela as coordenadas dos pontos que definem o retangulo */


int main(void)
{
   Retangulo r1 = { {0,0},{0,0},{0,0},{0,0} };
   printf("Entre com as coordenadas do canto superior esquerdo e inferior esquerdo do retangulo.: ");
   scanf("%d %d %d %d",&r1.pse.x,&r1.pse.y,&r1.pid.x,&r1.pid.y);

   retangulocompleto(&(r1.pse),&(r1.pid),&r1);
   printretangulo(&r1);   

   printf("\n\n");
   return 0;
}

void retangulocompleto(const Ponto *p1, const Ponto *p2, Retangulo *r) /* Completa o restante das coordenadas usando os dados do usuário*/
{
   r->pie.x = r->pse.x; r->pie.y = r->pid.y; /* Preenche as coordenadas x e y do Ponto Inferior Esquerdo */
   r->psd.x = r->pid.x; r->psd.y = r->pse.y; /* Preenche as coordenadas x e y do Ponto Superior Direito */
}

float distancia(const Ponto *p1, const Ponto *p2) /* Calcula e retorna a distancia entre dois pontos dados */
{
   float dist = sqrt((p2->x - p1->x)*(p2->x - p1->x) + (p2->y - p1->y)*(p2->y - p1->y));
   return dist;
}

void printretangulo(const Retangulo *r)
{
   float compdiag = distancia(&(r->pse),&(r->pid));
   float aresta_superior = distancia(&(r->pse),&(r->psd));
   float aresta_lateral = distancia(&(r->psd),&(r->pid));
   float area = aresta_superior * aresta_lateral;

   printf("O retangulo eh formado pelos pontos\n");
   printf("Ponto superior esquerdo (%d,%d)\n",r->pse.x,r->pse.y);
   printf("Ponto inferior esquerdo (%d,%d)\n",r->pie.x,r->pie.y);
   printf("Ponto superior direito (%d,%d)\n",r->psd.x,r->psd.y);
   printf("Ponto inferior direito (%d,%d)\n",r->pid.x,r->pid.y);
   printf("O comprimento da aresta superior(=inferior) %.2f e lateral direita(=esquerda) %.2f\n",aresta_superior,aresta_lateral);
   printf("De area e diagonal iguais a %.2f e %.2f\n",area,compdiag);
}
