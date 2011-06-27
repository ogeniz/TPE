/* O custo ao consumidor de um carro novo é a soma do custo de fábrica
   com  a percentagem  do distribuidor  e dos  impostos  (aplicados ao
   custo de  fábrica). Supondo que a percentagem  do distribuidor seja
   de 28% e  dos impostos 45%, escrever um algoritmo  que leia o custo
   de fábrica de um carro e escreve o custo ao consumidor */

#include <stdio.h>

#define CUSTO_DISTRIBUIDOR 0.28
#define CUSTO_IMPOSTOS 0.45

int main(void)
{
   float custo_fabrica = 0.0, custo_consumidor = 0.0;
   printf("\n\nEntre com o custo total da fabrica : ");   
   scanf("%f", &custo_fabrica);
   
   printf("Custo de Distribuicao (%.0f%% do Custo de Fabrica) R$ %f ",CUSTO_DISTRIBUIDOR*100, custo_fabrica*CUSTO_DISTRIBUIDOR);
   
   printf("e Custo dos Impostos (%.0f%% do Custo de Fabrica) R$ %f \n", CUSTO_IMPOSTOS*100, custo_fabrica*CUSTO_IMPOSTOS);
   
   custo_consumidor = custo_fabrica*(1.0 + CUSTO_DISTRIBUIDOR + CUSTO_IMPOSTOS);
   printf("O Custo total para o consumidor dado os custos da ");
   printf("distribuicao e impostos R$ %.5f\n\n", custo_consumidor);
   return 0;
}
