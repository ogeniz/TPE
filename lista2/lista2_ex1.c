/* Ler  o   comprimento dos  tr�s  lados  de  um tri�ngulo   (a,b,c) e
   determinar o tipo de tri�ngulo, com base nos seguintes casos:

   a) Se A > = B + C, nenhum tri�ngulo � formado.
   b) Se A^2 = B^2 + C^2, � formado um tri�ngulo ret�ngulo.
   c) Se A^2 > B^2 + C^2, � formado um tri�ngulo obtus�ngulo.
   d) Se A^2 < B^2 + C^2, � formado um tri�ngulo acut�ngulo.
 */

#include <stdio.h>

int main(void)
{
   unsigned short la,lb,lc;
   short tt;
   printf("Entre com as medidas inteiras dos lados A, B e C de um triangulo ");
   scanf("%hu %hu %hu",&la,&lb,&lc);
   tt = (la*la) - (lb*lb + lc*lc);
   if(la >= (lb + lc))
   {
      printf("\nNenhum triangulo � formado\n\n");
      return(0);
   }
   if(tt)
   {
      if(tt > 0)
	 printf("\nTriangulo Obtusangulo\n\n");
      else
	 printf("\nTriangulo Acutangulo\n\n");
   }
   else
      printf("\nTriangulo Retangulo\n\n");
   return 0;
}
