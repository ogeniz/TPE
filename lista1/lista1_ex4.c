/* Fazer  um algoritmo que  leia as  3 notas de  um aluno e  calcule a
  média final deste aluno. Considerar que  a média é ponderada e que o
  peso das notas é : 2, 3 e 5 respectivamente.  */

#include <stdio.h>

#define PESO1 2
#define PESO2 3
#define PESO3 5

int main(void)
{
  float nota1 = 0.0, nota2 = 0.0, nota3 = 0.0, media_final = 0.0;
  printf("\nEntre com as 3 notas na forma nota1 nota2 nota 3 : ");
  scanf("%f %f %f", &nota1, &nota2, &nota3);  
  media_final = (nota1*PESO1 + nota2*PESO2 + nota3*PESO3)/(PESO1 + PESO2 + PESO3);
  printf("A media final das notas dado por (%.3f*%d + %.3f*%d  + %.3f*%d)/", nota1, PESO1, nota2, PESO2, nota3, PESO3);
  printf("(%d + %d + %d) = ", PESO1, PESO2, PESO3);
  printf("%.5f\n\n",media_final);
  return 0;
}
