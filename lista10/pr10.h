#ifndef PR10_H
#define PR10_H

#pragma pack(1)/*Alinhamento dos campos de Record com o menor tipo de campo 8-bits(char) */
typedef struct {
  int id;
  short age;
  float height;
  float weight;
  char gender;
}Record;
#pragma pack()/*Restaura ao alinhamento original*/

void cmatest(int ,const char *);
void grava_arquivo_resultado(FILE *,const Record *);

#endif
