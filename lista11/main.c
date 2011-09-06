#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pr11.h"

int main(void)
{
  Record *pRecord = NULL;
  FILE *file_in;
  FILE *file_out_m;
  FILE *file_out_f;
  unsigned short nlines = 0,i = 0,j = 0;
  char line[128];
  char *substring;
  int eof = 0;
  
  if((file_in = fopen("records_in.txt","r")) == NULL)
    {
      printf("\nErro na leitura do arquivo <%s>\n\n","records_in.txt");
      exit(0);
    }
  else
    do
      {
	eof = fgetc(file_in);
	if(eof == '\n')
	    nlines ++;
      }while(eof != EOF);
  printf("\nO arquivo <%s> tem %hd linhas\n\n","records_in.txt",nlines);
  fclose(file_in);
  
  /*aloca memória para um vetor de registros a serem preenchidos com os dados do arquivo de dados*/
  if( (pRecord = (Record *) malloc(nlines*sizeof(Record))) == NULL )
    {
      perror("\nProblemas de alocacao de memoria\n\n");/*Problemas na aloccacao de memória*/
      exit(0);
    }    
  
  if((file_in = fopen("records_in.txt","r")) == NULL)
    {
      printf("\nErro na abertura do arquivo <%s>\n\n","records_in.txt");
      exit(0);
    }  
  while(fgets(line,sizeof(line),file_in))
    {
      substring = strtok(line,",");
      j = 0;
      while(substring != NULL)
	{
	  if(j == 0)
	    strcpy((pRecord + i)->nome,substring);
	  if(j == 1)
	    (pRecord + i)->sexo = (*substring);
	  if(j == 2)
	    strcpy((pRecord + i)->corDosOlhos,substring);
	  if(j == 3)
	    (pRecord + i)->peso = (float) strtod(substring,NULL);
	  if(j == 4)
	    strcpy((pRecord + i)->dataDeNascimento,substring);
	  substring = strtok(NULL, ",");
	  j++;
	}
      i++;
    }
  fclose(file_in);
  printf("\nAbertura e fechamento do arquivo com sucesso, i = %hi j = %d\n\n",i,j);
  
  if((file_out_m = fopen("records_out_m.txt","w")) == NULL)
    {
      printf("\nErro na abertura do arquivo <%s>\n\n","records_out_m.txt");
      free(pRecord);
      exit(0);
    }
  if((file_out_f = fopen("records_out_f.txt","w")) == NULL)
    {
      printf("\nErro na abertura do arquivo <%s>\n\n","records_out_f.txt");
      free(pRecord);
      exit(0);
    }
  for(i = 0; i < nlines; i++)
    {
      if(((pRecord + i)->sexo) == '1')
	fprintf(file_out_m,"%s,%c,%s,%.2f,%s",(pRecord + i)->nome,(pRecord + i)->sexo,(pRecord + i)->corDosOlhos,
	       (pRecord + i)->peso,(pRecord + i)->dataDeNascimento);
      else
	fprintf(file_out_f,"%s,%c,%s,%.2f,%s",(pRecord + i)->nome,(pRecord + i)->sexo,(pRecord + i)->corDosOlhos,
	       (pRecord + i)->peso,(pRecord + i)->dataDeNascimento);
    }
  fclose(file_out_m);
  fclose(file_out_f);
  free(pRecord);  
  return 0;
}
