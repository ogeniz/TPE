/* Ler  o   comprimento dos  três  lados  de  um triângulo   (a,b,c) e
   determinar o tipo de triângulo, com base nos seguintes casos:

   a) Se A > = B + C, nenhum triângulo é formado.
   b) Se A^2 = B^2 + C^2, é formado um triângulo retângulo.
   c) Se A^2 > B^2 + C^2, é formado um triângulo obtusângulo.
   d) Se A^2 < B^2 + C^2, é formado um triângulo acutângulo.
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
      printf("\nNenhum triangulo é formado\n\n");
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
