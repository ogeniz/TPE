#ifndef POINT_H
#define POINT_H

typedef struct {
   float x;
   float y;
}POINT;

void  readpoint(POINT *);
float distpoint(const POINT *, const POINT *);
float modpoint(const POINT *);

#endif
