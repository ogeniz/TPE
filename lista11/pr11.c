#include <stdio.h>
#include <stdlib.h>
#include "pr11.h"

void pr11(void)
{
  Record *pRecord = NULL;
  FILE *filetxt_in;
  FILE *filetxt_out_m;
  FILE *filetxt_out_f;
  int count = 0;
  unsigned short nlines = 0,i;
  if((filetxt_in = fopen("records_in.txt","r")) == NULL)
    {
      printf("\nErro na leitura do arquivo <%s>\n\n","records_in.txt");
      exit(0);
    }
  else
    do
      {
	count = fgetc(filetxt_in);
	if(count == '\n')
	  nlines++;
      }while(count != EOF);
  printf("\nO arquivo <%s> tem %hd linhas\n\n","records_in.txt",nlines);
  fclose(filetxt_in);
  
  /*aloca memória para um vetor de registros a serem preenchidos com os dados do arquivo de dados*/
  if( (pRecord = (Record *) malloc(nlines*sizeof(Record))) == NULL )
    {
      printf("\nProblemas de alocacao de memoria\n\n");/*Problemas na aloccacao de memória*/
      exit(0);
    }

  if((filetxt_in = fopen("records_in.txt","r")) == NULL)
    {
      printf("\nErro na leitura do arquivo <%s>\n\n","records_in.txt");
      exit(0);
    }
  for(i = 0; i < nlines; i++)    
    if((fscanf(filetxt_in,"%s,%c,%s,%f,%s",(pRecord + i)->nome,&(pRecord + i)->sexo,(pRecord + i)->corDosOlhos,
	       &(pRecord + i)->peso,(pRecord + i)->dataDeNascimento) != 9))
      {
	perror("\nErro na leitura dos dados\n\n");
	fclose(filetxt_in);
	exit(0);
      }

  if((filetxt_out_m = fopen("out_m.txt","w")) == NULL)
    {
      printf("\nErro na criaccao ou escrita do arquivo <%s>\n\n","out_m.txt");
      exit(0);
    }
  if((filetxt_out_f = fopen("out_f.txt","w")) == NULL)
    {
      printf("\nErro na criaccao ou escrita do arquivo <%s>\n\n","out_f.txt");
      exit(0);
    }
  for(i = 0; i < nlines; i++)
    {
      if((pRecord + i)->sexo == 1)
	fprintf(filetxt_out_m,"%s,%s,%.2f,%s",(pRecord + i)->nome,(pRecord + i)->corDosOlhos,
		(pRecord + i)->peso,(pRecord + i)->dataDeNascimento);
      else
	fprintf(filetxt_out_f,"%s,%s,%.2f,%s",(pRecord + i)->nome,(pRecord + i)->corDosOlhos,
		(pRecord + i)->peso,(pRecord + i)->dataDeNascimento);
    }
  fclose(filetxt_out_m);
  fclose(filetxt_out_f);
  free(pRecord);
}
/*unsigned short contalinhas()
{
  FILE *filetxt;  
  int count = 0,n_lines = 0;
  if((filetxt = fopen("records_in.txt","r")) == NULL)
    {
      printf("\nErro na leitura do arquivo <%s>\n\n","records_in.txt");
      exit(0);
    }
  do
    {
      count = fgetc(filetxt);
      if(count == '\n')
        n_lines++;
    }while(count != EOF);
  printf("\nO arquivo <%s> tem %hd linhas\n\n",arg,n_lines);
  fclose(filetxt);
  return((unsigned short) n_lines);
}*/
