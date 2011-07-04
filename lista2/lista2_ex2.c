/* Ler um número X e calcular Y da seguinte maneira:
   a) Y = X se X < 0,
   b) Y = 1 / 1 - X^2 se 0 <= X <= 1,
   c) Y = 3*ln(X) + X^2 se x > 1.
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
  float x,y;
  printf("Entre com um valor qualquer para X = ");
  scanf("%f",&x);
  
  if(x < 0.0)
    y = x;
  if(x >= 0 && x <= 1.0)
    y = 1/(1 - (x*x));
  if(x > 1.0)
    y = (3.0*log(x)) + (x*x);

  printf("\nPara X = %.2f temos Y = %.2f\n\n",x,y);
  
  return 0;
}
