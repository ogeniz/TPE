/* Print some values of ascii table*/

#include <stdio.h>

int main(void)
{
   unsigned char i = 28;
   do
   {
      printf("%c ",i);
      if(!(i % 20))
	 printf("\n");
      i++;
   }while(i < 127);

   printf("\n\n");
   return 0;   
}
