/* File : point.h */

#ifndef _POINT_H
#define _POINT_H
#include "boolean.h"


/*Definisi ABSTRACT DATA TYPE POINT */
typedef struct { int X;  /* absis  */
                int Y;  /* ordinat*/ } POINT;
       
/* DEFINISI PROTOTIP PRIMITIF      */
/** Konstruktor membentuk POINT **/
POINT MakePOINT (int X, int Y);
/* Membentuk sebuah POINT dari komponen-komponennya */

/** Destruktor/Dealokator: tidak perlu **/

/* Assignment Point */
POINT AssignPOINT (POINT P);
/* menghasilkan salinan Point P) */

/*** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  ***/                                               
void BacaPOINT (POINT* P);
/* Makepoint(x,y,P) membentuk P dari x dan y yang dibaca  */           
void TulisPOINT(POINT P);
/* Nilai P ditulis ke layar dg format â€œ(X,Y)"  */             

/** Kelompok operasi aritmatika terhadap POINT */
POINT PlusPOINT(POINT P1,POINT P2);
/*Mengirimkan true jika P1 = P2: absis dan ordinatnya sama */

/** Kelompok operasi relasional terhadap POINT */
boolean POINTEQ(POINT P1, POINT P2);
/*Mengirimkan true jika P1 = P2: absis dan ordinatnya sama */

/* ** Kelompok menentukan di mana P berada*/
boolean IsOrigin (POINT P) ;
/* Menghasilkan true jika P adalah titik origin */
int Kuadran(POINT P);
/* Menghasilkan kuadran dari P: 1,2,3, atau 4*/
/* Precondition : P bukan Titik Origin, dan P tidak terletak di salah satu sumbu*/

/* ** KELOMPOK OPERASI LAIN TERHADAP TYPE */                         
POINT MidPOINT (POINT P1,POINT P2);
/* Menghitung  titik tengah antara P1 dan P2, dibulatkan ke bawah, jadi pakailah pembagian int */

void CopyPOINT (POINT* P1, POINT P2);
/* menyalin P1 ke P2, assignment P1<-- P2 */

void Move (POINT *P, int DeltaX, int DeltaY);
/*I.S. P terdefinisi*/
/*F.S. P digeser sebesar DeltaX dan ordinatnya sebesar Delta Y*/

int GetX (POINT P);
/*mengirimkan Absis X dari P*/

int GetY (POINT P);
/*mengirimkan Ordinat Y dari P*/

void SetX (POINT *P, int newX);
/*Mengubah nilai komponen X dari P*/

void SetY (POINT *P, int newY);
/*Mengubah nilai komponen Y dari P*/

#endif ﻿
