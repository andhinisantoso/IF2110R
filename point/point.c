/* File : point.c */
/* nama : Ari Bambang NIM : 14115062*/

#include <stdio.h>
#include "point.h"

/* DEFINISI PROTOTIP PRIMITIF      */
/** Konstruktor membentuk POINT **/
POINT MakePOINT (int X, int Y){
	POINT P; 
	SetX(&P, X);
	SetY(&P, Y);
	return P;
}
/* Membentuk sebuah POINT dari komponen-komponennya */

/** Destruktor/Dealokator: tidak perlu **/

/* Assignment Point */
POINT AssignPOINT (POINT P){
	return MakePOINT(GetX(P), GetY(P));
}
/* menghasilkan salinan Point P) */

/*** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  ***/                                               
void BacaPOINT (POINT* P){
	int X, Y;
	scanf("%d %d", &X, &Y);
	(*P) = MakePOINT(X, Y);
}
/* Makepoint(x,y,P) membentuk P dari x dan y yang dibaca  */           
void TulisPOINT(POINT P){
	printf("(%d,%d)", GetX(P), GetY(P));
}
/* Nilai P ditulis ke layar dg format â€œ(X,Y)"  */             

/** Kelompok operasi aritmatika terhadap POINT */
POINT PlusPOINT(POINT P1,POINT P2){
	return MakePOINT(GetX(P1) + GetX(P2), GetY(P1) + GetY(P2));
}
/*Mengirimkan true jika P1 = P2: absis dan ordinatnya sama */

/** Kelompok operasi relasional terhadap POINT */
boolean POINTEQ(POINT P1, POINT P2){
	return GetX(P1) == GetX(P2) && GetY(P1) == GetY(P2);
}
/*Mengirimkan true jika P1 = P2: absis dan ordinatnya sama */

/* ** Kelompok menentukan di mana P berada*/
boolean IsOrigin (POINT P) {
	return GetX(P) == 0 && GetY(P) == 0;
}
/* Menghasilkan true jika P adalah titik origin */
int Kuadran(POINT P){
	int k;
	if(GetX(P) > 0 && GetY(P) > 0){
		k = 1;
	} else if(GetX(P) < 0 && GetY(P) > 0){
		k = 2;
	} else if(GetX(P) < 0 && GetY(P) < 0){
		k = 3;
	} else if(GetX(P) > 0 && GetY(P) < 0){
		k = 3;
	} else {
		k = 0;
	}
	return k;
}
/* Menghasilkan kuadran dari P: 1,2,3, atau 4*/
/* Precondition : P bukan Titik Origin, dan P tidak terletak di salah satu sumbu*/

/* ** KELOMPOK OPERASI LAIN TERHADAP TYPE */                         
POINT MidPOINT (POINT P1,POINT P2){
	return MakePOINT((GetX(P1) + GetX(P2))/2, (GetY(P1) + GetY(P2))/2);
}
/* Menghitung  titik tengah antara P1 dan P2, dibulatkan ke bawah, jadi pakailah pembagian int */

void CopyPOINT (POINT* P1, POINT P2){
	(*P1) = MakePOINT(GetX(P2), GetY(P2));
}
/* menyalin P1 ke P2, assignment P1<-- P2 */

void Move (POINT *P, int DeltaX, int DeltaY);
/*I.S. P terdefinisi*/
/*F.S. P digeser sebesar DeltaX dan ordinatnya sebesar Delta Y*/

int GetX (POINT P){
	return P.X;
}
/*mengirimkan Absis X dari P*/

int GetY (POINT P){
	return P.Y;
}
/*mengirimkan Ordinat Y dari P*/

void SetX (POINT *P, int newX){
	(*P).X = newX;
}
/*Mengubah nilai komponen X dari P*/

void SetY (POINT *P, int newY){
	(*P).Y = newY;
}
/*Mengubah nilai komponen Y dari P*/﻿
