#include <stdio.h>
#include "point.h"

int main(int argc, char *argv[])
{
   POINT a = {0.0,0.0}, b = {0.0,0.0};
   readpoint(&a);
   readpoint(&b);
   printf("X1 = (%.2f,%.2f) e X2 = (%.2f,%.2f).\n",a.x,a.y,b.x,b.y);
   printf("A distancia entre os pontos eh de %.2f ",distpoint(&a,&b));
   printf("(%.2f,%.2f) e (%.2f,%.2f) %.2f e %.2f\n\n",a.x,a.y,b.x,b.y,modpoint(&a),modpoint(&b));
   return 0;
}
