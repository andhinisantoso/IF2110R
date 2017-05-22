
#include <stdio.h>
#include <stdlib.h>

#ifndef _BOOLEAN_h
#define _BOOLEAN_h

#define boolean unsigned char
#define true 1
#define false 0

#endif

/*	----- Prototype Manajemen Memori ----- */
void Alokasi (address * P, infotype X) {
	/* Kamus Lokal */

	/* Algoritma */
	(*P) = (address) malloc (sizeof (ElmtStack));
	if ((*P) != Nil) {
		Info(*P) = X;
		Next(*P) = Nil;
	}
}

void Dealokasi (address P) {
	/* Kamus Lokal */

	/* Algoritma */
	Next(P)=Nil;
}

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty (Stack S) {
	/* Kamus Lokal */

	/* Algoritma */
	return (Top(S) == Nil);
}
void CreateEmpty (Stack * S) {
	/* Kamus Lokal */

	/* Algoritma */
	Top(*S) = Nil;
}
/*	----- Operator Dasar Stack ----- */
void Push (Stack * S, infotype X) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	Alokasi(&P,X);
	if (P != Nil) {
		Next(P) = Top(*S);
		Top(*S) = P;
	}
}

void Pop (Stack * S, infotype * X) {
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	P = Top(*S);
	*X= Info(P);
	if (!IsEmpty(*S)) {
		Top(*S)=Next(P);
		Dealokasi(P);
	}
}

void main(){
		
	
	}
