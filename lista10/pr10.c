#include <stdio.h>
#include <stdlib.h>
#include "pr10.h"

void cmatest(int narg,const char *arg)
{
  if(narg != 2)
    {
      printf("\n<%s> records.dat\n\n",arg);
      exit(0);
    }
}
void grava_arquivo_resultado(FILE *ftxt,const Record *registros)
{
  short i,male = 0,female = 0,maior = 0;
  float sp = 0.0;
  if((ftxt = fopen("records.txt","w")) == NULL)
    {
      printf("\nErro de escrita no arquivo <%s>, imprimindo na tela\n\n","records.txt");
      for(i = 0;i < 3;i++)
        printf(" id.: %i\n age.: %hi\n height.: %.3f\n weight.: %.3f\n gender.: %c\n\n",(registros + i)->id,(registros + i)->age,(registros + i)->height,
               (registros + i)->weight,(registros + i)->gender);
    }
  else
    {
      printf("\nImprimindo os registros no arquivo <%s>\n\n","records.txt");
      for(i = 0;i < 3;i++)
        fprintf(ftxt," id.: %i\n age.: %hi\n height.: %.3f\n weight.: %.3f\n gender.: %c\n\n",(registros + i)->id,(registros + i)->age,
                (registros + i)->height,(registros + i)->weight,(registros + i)->gender);
      fclose(ftxt);
    }

  if((ftxt = fopen("records.txt","a")) == NULL)
    {
      printf("\nErro de escrita no arquivo <%s>, imprimindo na tela\n\n","records.txt");
      for(i = 0;i < 3;i++)
        sp += (registros + i)->weight;
      printf("\nA soma dos pesos eh %.3f\n",sp);
    }
  else
    {
      printf("\nImprimindo os registros no arquivo <%s>\n\n","records.txt");
      for(i = 0;i < 3;i++)
        sp += (registros + i)->weight;
      fprintf(ftxt,"\nA soma dos pesos eh %.3fkg\n",sp);               
      fclose(ftxt);
    }

  if((ftxt = fopen("records.txt","a")) == NULL)
    {
      printf("\nErro de escrita no arquivo <%s>, imprimindo na tela\n\n","records.txt");
      maior = registros->age;
      for(i = 1;i < 3;i++)
        if(maior < (registros + i)->age)
          maior = (registros + i)->age;      
      printf("\nA maior idade registrada eh %hi\n",maior);
    }
  else
    {
      printf("\nImprimindo os registros no arquivo <%s>\n\n","records.txt");
      maior = registros->age;
      for(i = 1;i < 3;i++)
        if(maior < (registros + i)->age)
          maior = (registros + i)->age;      
      fprintf(ftxt,"\nA maior idade registrada eh %hi\n",maior);               
      fclose(ftxt);
    }

  if((ftxt = fopen("records.txt","a")) == NULL)
    {
      printf("\nErro de escrita no arquivo <%s>, imprimindo na tela\n\n","records.txt");
      for(i = 0;i < 3;i++)
        {
          if((registros + i)->gender == 0x46)
            female++;
          else
            male++;
        }
      printf("\nEstao registrados %hi homens e %hi mulheres\n",male,female);
    }
  else
    {
      printf("\nImprimindo os registros no arquivo <%s>\n\n","records.txt");
      for(i = 0;i < 3;i++)
        {
          if((registros + i)->gender == 0x46)
            female++;
          else
            male++;
        }
      fprintf(ftxt,"\nEstao registrados %hi homen(s) e %hi mulhere(s)\n",male,female);               
      fclose(ftxt);
    }
}
