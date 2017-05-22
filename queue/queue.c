//nama: Ari Bambang Kurniawan
//NIM: 14115062
/* File : queuelist.c */
/* File : queue.h */
/* deklarasi Queue yang diimplementasi dengan tabel kontigu */
/* HEAD dan TAIL adalah alamat elemen pertama dan terakhir  */
/* Queue mampu menampung MaxEl buah elemen */
#include <stdlib.h>
#include<stdio.h>
#include "queue.h"
/* Prototype */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
  return ((Head(Q)==Nil) && (Tail(Q)==Nil));
}
boolean IsFull(Queue Q)
/*Mengirim true jika tabel penampung elemen Q sudah penuh */
{
	return (MaxEl(Q)== NBElmt(Q));
}

/* yaitu mengandung MaxEl elemen */
int NBElmt(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
	if(Tail(Q) > Head(Q))
	{
		return (Tail(Q)-Head(Q));
	}
	else if( Tail(Q)<Head(Q) )
	{
		return (MaxEl(Q)-Head(Q)+1);
	}
	else // Head(Q)=Tail(Q)
	{
		return 1;
	}
}
/**** Kreator ***/
void CreateEmpty(Queue *Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg Maksimum elemen=0 */
/* Proses : Melakukan alokasi,Membuat sebuah Q kosong */
{
	if(Max>0){
		(*Q).T = (infotype *) malloc (Max * sizeof(infotype));
		if((*Q).T != NULL){
			MaxEl(*Q) = Max;  
		}else{
			(*Q).T = NULL;
		    	MaxEl(*Q) = 0;
		}
	}else{
		(*Q).T = NULL;
	    	MaxEl(*Q) = 0;
	}
	Head(*Q)=Nil;
	Tail(*Q)=Nil;
}
/**** Destruktor ***/
void DeAlokasi(Queue *Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi dan tidak NULL */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
	free(Q);
}
/**** Primitif Add/Delete ****/
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan  X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" . Suksesor dari (MaxEl-1) adalah 0*/
/* Jika Tail(Q)=MaxEl-1 maka suksesornya adalah Head(Q)=0 */
{
	if(IsEmpty(*Q)){
		Head(*Q) = 0;
		Tail(*Q) = 0;
	}
	else if(Tail(*Q) == (MaxEl(*Q)-1))
	{
		Tail(*Q) = 0;				
	}
	else
	{
		Tail(*Q) = Tail(*Q)+1;
	}
	InfoTail(*Q) = X;
}
void Del (Queue * Q, infotype* X)
/* Proses: Menghapus  X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S.,HEAD "maju";Q mungkin kosong */
/* jangan lupa menyesuaikan nilai HEAD dan TAIL jika Queue menjadi kosong */
{
	*X = InfoHead(*Q);
	if (Head(*Q) == Tail(*Q))
	{
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	}
	else if(Head(*Q) == (MaxEl(*Q)-1))
	{
		Head(*Q) = 0;
	}
	else
	{
		Head(*Q) = Head(*Q)+1;
	}
}
