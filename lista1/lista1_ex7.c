/* Um Sistema de equações lineares do tipo ax  + by = c e dx + ey = f,
   pode ser  resolvido segundo x  = (ce -  bf)/(ae - bd)  e y =  (af -
   cd)/(ae  -  bd).  Escrever  um  algoritmo que  lê  os  coeficientes
   a,b,c,d,e,f. Calcule os valores de x e y.  */


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   float a = 0.0, b = 0.0, c = 0.0, d = 0.0, e = 0.0, f = 0.0, x = 0.0, y = 0.0;
   printf("\n\nDada o sistema equacoes ax  + by = c e dx + ey = f ");
   printf("entre com os valores dos coeficientes nessa dada ordem a b c d e f\n");
   scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &e, &f);
   if(!(a*e - b*d))
   {
      printf("O dado sistema %.3fx + %.3fy = %.3f e %.3fx + %.3fy = %.3f ", a, b, c, d, e, f);
      printf("nao possui solucao\n\n");
      return 0;
   }  
   x = ( c*e - b*f )/( a*e - b*d );
   y = ( a*f - c*d )/( a*e - b*d );
   if(!(c*e - b*f))
      x = abs(x);
   if(!(a*f - c*d))
      y = abs(y);
   printf("O par ordenado (%.3f,%.3f) e a solucao do sistema ", x, y);
   printf("%.3fx + %.3fy = %.3f e %.3fx + %.3fy = %.3f\n\n", a, b, c, d, e, f);
   return 0;
}
