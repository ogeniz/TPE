/* Escrever um algoritmo que le  o numero de identifiacao e as 3 notas
 obtidas por  um aluno [0,0 e 10,0]  nas 3 verificacoes e  a media dos
 exercicios  [0,0 e  10,0] que  fazem parte  da avalicacao.  Para cada
 aluno, calcular a media de aproveitamento, usando a formula: MA = (N1
 + N2*2 + N3*3 + ME)/7. Atribuicao de conceitos obece a tabela : MA >=
 9,0 A; 9,0 > MA >= 7,5 B; MA 7,5  > MA >= 6,0 C; MA = 6,0 > MA >= 4,0
 D e  4,0 > MA E.  O algoritmo deve  escrever o número do  aluno, suas
 notas, a media dos exercicios, a media de aproveitamento , o conceito
 correspondente e  a mensagem APROVADO  se o conceito  for A,B ou  C e
 REPROVADO se o conceito for D ou E*/

#include <stdio.h>

int main(void)
{
   float ma = 0.0, n1 = 0.0, n2 = 0.0, n3 = 0.0, me = 0.0;
   unsigned short id_estudante = 0;
   char conceito = 0x0;
   printf("Entre com o numero de identificacao do aluno seguido das suas tres notas ");
   printf("na forma id n1 n2 n3 (0.0-10.0).: ");
   scanf("%hu %f %f %f",&id_estudante,&n1,&n2,&n3);
   if( n1 < 0.0 || n2 < 0.0 || n3 < 0.0 )
   {
      printf("\n!!!Erro verifique e insira as notas corretamente\n\n");
      return 0;
   }
   me = (n1 + n2 + n3)/3;
   ma = (me + n1 + n2*2 + n3*3)/7;
   if( (ma <= 10.0) && (ma >= 9.0))
      conceito = 0x41;
   else
   {
      if((ma < 9.0) && (ma >= 7.5))
	 conceito = 0x42;
      else if((ma < 7.5) && (ma >= 6.0))
	 conceito = 0x43;
      else if((ma < 6.0) && (ma >= 4.0))
	 conceito = 0x44;
      else if(ma < 4.0)
	 conceito = 0x45;
      else
      {
	 printf("\n!!!Erro verifique e insira as notas corretamente\n\n");
	 return 0;
      }
   }
   printf("\n\nO aluno %hu obteve %.2f, %.2f e %.2f com media de %.2f nos  exercicios.\n" ,id_estudante,n1,n2,n3,me);
   printf("Sua media de aproveitamento foi %.3f finalizando com conceito %c ",ma,conceito);
   if(ma < 6.0)
      printf("Reprovado\n\n");
   else
      printf("Aprovado\n\n");
   return 0;
}
