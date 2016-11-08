//nama: Ari Bambang Kurniawan
//NIM: 14115062
#include "stacklist.h"
#include <stdio.h>
#include <stdlib.h>

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

/*	---- Operasi Lain ----- 
void PrintStack (Stack S) {
	/* Kamus Lokal 
	address P;

	/* Algoritma 
	P = TOP(S);
	if (P == Nil) {
		printf("Stack kosong\n");
	} else {
		printf("[%d",Info(P));
		P = Next(P);
		while (P != Nil) {
			printf(", %d",Info(P));
			P = Next(P);
		}
		printf("]\n");
	}
}

int NbElmt (Stack S) {
	/* Kamus Lokal 
	address P;
	int N;

	/* Algoritma 
	P = TOP(S);
	N = 0;
	while (P != Nil) {
		N = N + 1;
		P = Next(P);
	}
	return N;
}

void PopAll (Stack * S) {
	/* Kamus Lokal 
	infotype X;

	/* Algoritma 
	while (!IsEmpty(*S)) {
		Pop(S,&X);
	}
}

void InversStack (Stack * S) {
	/* Kamus Lokal 
	Stack S1;
	infotype X;

	/* Algoritma 
	while (!IsEmpty(*S)) {
		Pop(S,&X);
		Push(&S1,X);
	}
	TOP(*S) = TOP(S1);
}
*/
