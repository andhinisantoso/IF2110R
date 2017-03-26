#include "array.h"
#include "array.c"
#include <stdio.h>

int main ()
{
    TabInt  T, T1, T2, Tin, Tout;
    int i,X;
    scanf("%d", &i);
    scanf("%d", &X);

          BacaIsi (&T);
    void TulisIsi (T);
    boolean NbElmt (T);
    boolean IsIdxValid (T,i);
    boolean IsIdxEff (T,i);
    boolean IsEmpty (T);
    boolean IsFull (T);

    void TulisIsiTab (T);
      PlusTab (T1,  T2);
      MinusTab ( T1,  T2);
      KaliTab (T1,T2);
      KaliKons (Tin,i);
      IsEQ (T1, T2);
      IsLess ( T1,  T2);
    IdxType Search1 (T,  X);
    IdxType Search2 ( T,  X);
    boolean SearchB ( T,  X);
    ElType ValMax (T);
    ElType ValMin ( T);
    IdxType IdxMaxTab ( T);
    IdxType IdxMinTab ( T);
    void CopyTab(Tin,Tout);
    TabInt InverseTab (T);
    boolean IsSimetris ( T);
}
