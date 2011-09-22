#include <stdio.h>
#include <stdlib.h>
#include "ap3.h"

void ap()
{
   FILE *fp_1 = NULL, *fp_2 = NULL;
   char flag1 = TRUE, flag2 = FALSE;
   Produto *item = NULL;
   if((fp_1 = fopen("CM_ALIM.CAD","w")) == NULL)
   {
      printf("\nNão foi possível abrir o %s para gravacao\n\n","CM_ALIM.CAD");
      exit(0);
   }
   if((fp_2 = fopen("CM_ELD.CAD","w")) == NULL)
   {
      printf("\nNão foi possível abrir o %s para gravacao\n\n","CM_ELD.CAD");
      fclose(fp_1);
      exit(0);
   }
   item = (Produto *) malloc(sizeof(Produto));
   while(flag1)
   {
      printf("\nEntre com o codigo do produto.: ");
      scanf("%d",&(item->codigo));
      if(item->codigo == 9999)
      {
	 flag1 = FALSE;
	 continue;
      }
      else
      {
	 printf("Entre com a descricao do produto.: ");
	 scanf("%s",item->descricao);
	 flag2 = TRUE;
	 while(flag2)
	 {
	    printf("Entre com o setor de venda do produto.: ");
	    scanf("%d",&item->setor_de_venda);
	    if(item->setor_de_venda < 1 || item->setor_de_venda > 2)
	       continue;
	    flag2 = FALSE;
	 }
	 printf("Entre com o valor unitario.: ");
	 scanf("%f",&item->valor_unitario);
      }
      if(item->setor_de_venda == 1)
	 fprintf(fp_1,"%d,%s,%d,%.2f\n",item->codigo,item->descricao,item->setor_de_venda,item->valor_unitario);
      else
	 fprintf(fp_2,"%d,%s,%d,%.2f\n",item->codigo,item->descricao,item->setor_de_venda,item->valor_unitario);
   }
   free(item);
   fclose(fp_1);
   fclose(fp_2);
}

