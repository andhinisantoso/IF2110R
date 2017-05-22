#include "stdio.h"
#include "point.h"

int
main ()
{/* KAMUS */
  POINT P, Q;
//  MakePOINT(1,2);
  SetX(&Q,1);
  SetY(&Q,2);
  BacaPOINT(&P);
  printf("%d\n", GetX(P));
  printf("%d\n", GetY(P));
  TulisPOINT(Q);
  if (POINTEQ(P,Q)==true)
    printf("sama");
  else printf("Tidak sama");
return 0;
}﻿
