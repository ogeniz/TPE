#include <stdio.h>
#include <stdlib.h>
#include "pr10.h"


int main(int argc, char **argv)
{
  FILE *filebin = NULL,*filetxt = NULL;
  unsigned short i,nregistros = 0;
  Record *registros = NULL;
  
  cmatest(argc,*(argv));
  
  if((filebin = fopen(argv[1],"rb")) == NULL)
    {
      printf("\nFilebin nao encontrado\n\n");
      exit(0);
    }
  if(fread((void *) &nregistros,sizeof(int),1,filebin) != 1)
    {
      printf("\nErro de leitura no arquivo <%s>\n\n",argv[1]);
      fclose(filebin);
      exit(0);
    }
  else
    printf("\nNo filebin %s existem %i registros\n\n",argv[1],nregistros);  
  
  if( (registros = (Record *) malloc(sizeof(Record)*nregistros)) == NULL )
    {
      printf("\nProblemas de alocacao de memoria\n\n");
      fclose(filebin);
      exit(0);
    }
  if(fread((void *) registros,sizeof(Record),nregistros,filebin) != nregistros)
    {
      printf("\nErro de leitura no arquivo <%s>\n\n",argv[1]);
      free(registros);
      fclose(filebin);   
      exit(0);
    }
  grava_arquivo_resultado(filetxt,registros);
  free(registros);
  fclose(filebin);
  return 0;
}
