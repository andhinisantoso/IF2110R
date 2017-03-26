/* File : listlinier.c */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include "llsingle.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsListEmpty(List L){ 
	return (First(L) == Nil);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList (List *L){ 
	First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){ 
	address P;
	P = (address) malloc (sizeof(ElmtList));
	if(P != Nil)
	{
		Info(P) = X;
		Next(P) = Nil;
		return P;
	}
	else
	{
		return Nil;
	}
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P){ 
	free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){ 
	address P;
	boolean Found;
	Found = false;
	
	P = First(L);
	while ((P != Nil) && !Found)
	{
		if(X == Info(P))
		{
			Found = true; 
		}
		else
		{
			P = Next(P);
		}
	}
	
	return P;
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
	address P; 
	P = Alokasi(X);
	if(P != Nil)
	{
		InsertFirst(&(*L), P);
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){ 
	address P;
	
	P = Alokasi(X);
	if(P != Nil)
	{
		InsertLast(&(*L), P);
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){ 
	address P;
	P = First(*L);
	First(*L) = Next(First(*L));
	Next(P) = Nil;
	(*X) = Info(P);
	Dealokasi(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){ 
	address P, Last, PrecLast;
	Last = First(*L);
	PrecLast = Nil;
	while(Next(Last) != Nil)
	{
		PrecLast = Last;
		Last = Next(Last);
	}		
	P = Last;
	if(PrecLast == Nil)
	{
		First(*L) = Nil;
	}
	else
	{
		Next(PrecLast) = Nil;
	}
	(*X) = Info(P);
	Dealokasi(&P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
	Next(P) = First(*L);
	First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec){ 
	Next(P) = Next(Prec);
	Next(Prec) = P; 
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P){ 
	address Last;
	if(IsListEmpty(*L))
	{
		InsertFirst(&(*L),P);
	}
	else
	{
		Last  = First(*L);
		while(Next(Last) != Nil)
		{
			Last = Next(Last);
		}
		InsertAfter(&(*L),P,Last);
	}
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){ 
	*P = First(*L);
	First(*L) = Next(First(*L));
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotype X){
	address P, Prec;
	P = Search (*L,X);
	if(P == First(*L))
	{
		DelFirst(&(*L),&P);
	}
	else
	{
		Prec = First(*L);
		while (Next(Prec) != P)
		{
			Prec = Next(Prec);
			break;
		}
		DelVLast (&(*L),&X);
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P){ 
	address Last, PrecLast;
	Last = First(*L);
	PrecLast = Nil;
	while (Next(Last) != Nil)
	{
		PrecLast = Last;
		Last = Next(Last);
	}
	*P = Last;
	if(PrecLast == Nil)
	{
		First(*L) = Nil;
	}
	else
	{
		Next(PrecLast) = Nil;
	}
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){ 
	*Pdel = Next(Prec);
	Next(Prec) = Next(Next(Prec));
	Next(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){ 
	address P;
	P = First (L);
	if(P == Nil)
	{
		printf("[]");
	}
	else
	{
		printf("[%d",Info(P));
		P = Next(P);
		while(P != Nil)
		{
			printf(",%d",Info(P));
			P = Next(P);
		}
		printf("]\n");
	}
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
