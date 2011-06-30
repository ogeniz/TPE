#include <stdio.h>
#include <math.h>
#include "point.h"

void readpoint(POINT *point)
{ 
   float a = 0.0, b = 0.0;
   printf("\nEntre com os valores das coordenas das do ponto: ");
   scanf("%f %f", &a, &b);
   point->x = a;
   point->y = b;
}

float distpoint(const POINT *x1, const POINT *x2)
{
   float dist = 0.0;
   dist = sqrt((x2->x - x1->x)*(x2->x - x1->x) + (x2->y - x1->y) - (x2->y - x1->y));
   return dist;
}

float modpoint(const POINT *x1)
{
   float modulo = 0.0;
   modulo = sqrt((x1->x * x1->x) + (x1->y * x1->y));
   return modulo;
}
