#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calc_PI(double);

int main(int argc, char *argv[])
{
  if(argc != 2)
    {
      printf("Uso do programa %s erro\n", argv[0]);
      exit(0);
    }
  if(strtod(argv[1],(char **) NULL) <= 0)
    {
      printf("Nao eh permitido o uso de caracteres alfabeticos, pontuacao e numeros negativos\n");
      exit(0);
    }

  calc_PI(strtod(argv[1],(char **) NULL));

  return 0;
}

void calc_PI(double erro)
{
  
  double aux = 0.0;
  double const pi = acos(-1);
  int i = 1;
   
  printf("\n**************************************************\n\n");

   for(;;i++)
    {
      aux += pow(-1.0,i)/(2.0*i + 1.0);
      if( fabs(pi - (4.0 * (1.0 + aux))) < erro )
      	{
      	  printf("Apos %d iteracoes.\n", i);
      	  printf("Valor de Pi dado por arccos(-1) %.8lf.\n",pi);
      	  printf("Valor de Pi calculado pela serie 4(1 + (-1)^p/2p + 1) = %.8lf ",4.0 * (1.0 + aux));
      	  printf("com erro de %.8lf\n",erro);
      	  break;
      	}      
    }

   printf("\n\n**************************************************\n");
}
