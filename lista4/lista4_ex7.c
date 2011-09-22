#include <stdio.h>
#include <string.h>

int main(void)
{
   unsigned char i = 0,j = 0,k = 0, l = 0, aux = 0;
   char url[256],protocolo[5] = "http",arquivo[30] = "index.html";
   char dominio[50],diretorio[50] = "default";
   printf("Entre com a URL.: ");
   scanf("%s",url);
   aux = strrchr(url,0x2f) - url;
   if(strchr(url,0x3a))
   {
      while(url[i]!= 0x3a)
      {
	 protocolo[i] = url[i];
	 i++;
      }
      protocolo[i] = '\0';
      printf("\nProtocolo.: %s\n",protocolo);
      i+=3;
      while(url[i] && url[i] != 0x2f)
      {
	 dominio[j] = url[i];
	 i++;
	 j++;
      }
      dominio[j] = '\0';
      printf("Dominio.: %s\n",dominio);
      if(url[i])
	 i++;
      while(i < aux && url[i])
      {
	 diretorio[k] = url[i];
	 k++;
	 i++;
      }
      diretorio[k] = '\0';
      printf("Diretorio.: %s\n",diretorio);
      if(url[i])
	 i++;
      if(i < aux && url[i])
	 i++;
      while(url[i])
      {
	 arquivo[l] = url[i];
	 l++;
	 i++;
	 arquivo[l] = '\0';
      }
      printf("Arquivo.: %s\n",arquivo);
   }
   else
   {
      printf("\nProtocolo.: %s\n",protocolo);
      while(url[i] && url[i] !=0x2f)
      {
	 dominio[j] = url[i];
	 j++;
	 i++;
      }
      dominio[j] = '\0';
      printf("Dominio.: %s\n",dominio);
      if(url[i])
	 i++;
      while(i < aux && url[i])
      {
	 diretorio[k] = url[i];
	 k++;
	 i++;
      }
      diretorio[k] = '\0';
      printf("Diretorio.: %s\n",diretorio);
      if(url[i])
	 i++;
      while(url[i])
      {
	 arquivo[l] = url[i];
	 l++;
	 i++;
	 arquivo[l] = '\0';
      }
      printf("Arquivo.: %s\n",arquivo);
   }
   printf("\n");
   return 0;
}
