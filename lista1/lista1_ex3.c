/* Construir um algoritmo que, tendo como dados de entrada dois pontos
   quaisquer no plano, P(x1,y1)  e P(x2,y2), escreva a distância entre
   eles. A fórmula que  efetua tal calculo é d = ((x2  - x1)^2 + (y2 -
   y1)^2)^1/2 */

#include <stdio.h>
#include <math.h>

int main(void)
{
  float x1 = 0.0, x2 = 0.0, y1 = 0.0, y2= 0.0, dist = 0.0, xd = 0.0, yd = 0.0;
  printf("\nEntre com as coordenadas dos pontos A e B na forma x1 y1 x2 y2: ");
  scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
  xd = x2 - x1; /*Calcula a coordenada X do vetor distancia entre os pontos*/
  yd = y2 - y1; /*Calcula a coordenada Y do vetor distancia entre os pontos*/
  dist = sqrt(xd*xd + yd*yd); /*Encontra o modulo do vetor distancia, efetivamente a distancia entre os pontos*/
  printf("\nA distancia entre os pontos (%.5f,%.5f) e (%.5f,%.5f) e igual a %.5f\n\n",x1,y1,x2,y2,dist);
  return 0;
}
