#include "array.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt *T){
    int i;
    for (i=0; i < NMax- IdxMin+1;i++){
        (*T).TI[i]=0;
    }
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
    int i;
    for (i=0; i < NMax- IdxMin+1;i++){
            if((T).TI[i]==0){
                return true;
            } else return false;
    }
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T){
    int i;
    for (i=0; i < NMax- IdxMin+1;i++){
            if((T).TI[i]!=0){
                return true;
            } else return false;
    }
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= NMax */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= NMax; Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    int i;
    for (i=0; i < NMax- IdxMin+1;i++){
        scanf("%d\n",&(*T).TI[i]);
    }
}

void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
{
    int i;
    for (i=0; i < NMax- IdxMin+1;i++){
        printf("[%d]%d\n",i,(T).TI[i]);
    }
}
void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    int i;
    for (i=0; i < NMax- IdxMin+1;i++){
        printf("[%d,]",(T).TI[i]);
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
{
    int i;
    if((T1).TI[NMax]==(T2).TI[NMax]){
    for (i=0; i < NMax- IdxMin+1;i++){
        printf("%d\n",(T1).TI[i]+(T2).TI[i]);
        }
    }
}
TabInt MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    int i;
    if((T1).TI[NMax]==(T2).TI[NMax]){
    for (i=0; i < NMax- IdxMin+1;i++){
        printf("%d\n",(T1).TI[i]-(T2).TI[i]);
        }
    }
}

TabInt KaliTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
{
    int i;
    if((T1).TI[NMax]==(T2).TI[NMax]){
    for (i=0; i < NMax- IdxMin+1;i++){
        printf("%d\n",(T1).TI[i]*(T2).TI[i]);
        }
    }
}

TabInt KaliKons (TabInt Tin, ElType c)
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
{
    int i;
    for (i=0; i < NMax- IdxMin+1;i++){
        printf("%d",(Tin).TI[i]*c);
        }
    }

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
        int i;

    if((T1).TI[NMax]==(T2).TI[NMax]){

    for (i=0; i < NMax- IdxMin+1;i++){
        if ((T1).TI[i]==(T2).TI[i])
        {
         return true;
        }else return false;
        }
    }
}

boolean IsLess (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */

{
        int i;

    if((T1).TI[NMax]==(T2).TI[NMax]){

    for (i=0; i < NMax- IdxMin+1;i++){
        if ((T1).TI[i]<(T2).TI[i]){
            return true;
        }
        else return false;
        }
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
        int i, mark;
        for(i=0, mark = 200; i<NMax-IdxMin+1;i++){
        if ((T).TI[i] == X){
                if (i< mark){
                    i =  mark;
                }
            }
        }
        if (mark == 200){return IdxUndef;}
        else return mark;
}

IdxType Search2 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
        int i;
        boolean Found;
        for(i=0; i<NMax-IdxMin+1;i++){
            if ((T).TI[i] == X){
                return Found;
            }else return IdxUndef;
        }
}

boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
{
        int i;
        for(i=0; i<NMax-IdxMin+1;i++){
            if ((T).TI[i] == X){
                return true;
            }else return false;
        }
}
//boolean SearchSentinel ()

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
    int i, maks;
    for(i=0, maks =(T).TI[1]; i<NMax-IdxMin+1;i++){
            if ((T).TI[i]> maks ){
                (T).TI[i] =  maks;
            }
    }
    return maks;
}

ElType ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
{
    int i, mins;
    for(i=0, mins = (T).TI[1]; i<NMax-IdxMin+1;i++){
            if ((T).TI[i]< mins){
                (T).TI[i] = mins;
            }
    }
    return mins;
}


IdxType IdxMaxTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
{
        int i, mark,n,a=1;
        n=(T).TI[1];
        for(i=2; i<NMax-IdxMin+1;i++){
           if (n > (T).TI[i]){
                    n=(T).TI[i];
                    a=i;
                    break;
            }
        }

    return a;
}

IdxType IdxMinTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
{
        int i,n,a=1;
        n=(T).TI[1];
        for(i=2; i<NMax-IdxMin+1;i++){
           if (n < (T).TI[i]){
                    n=(T).TI[i];
                    a=i;
                    break;
            }
        }
    return a;
}

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
    int i;

    for (i=0; i < NMax- IdxMin+1;i++){
        (Tin).TI[i]=(Tout).TI[i];
       }

}

TabInt InverseTab (TabInt T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
    int i,a;

    for (i=0; i < NMax- IdxMin+1;i++){
        for (a=NMax; a > 1 ;a--){

        (T).TI[i]==(T).TI[a];
       }
    }

}

boolean IsSimetris (TabInt T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
    int i,a;

    for (i=0; i < NMax- IdxMin+1;i++){
        for (a=NMax; a > 1 ;a--){
            if((T).TI[i]==(T).TI[a]){
                return true;
            } else return false;
       }
    }
}

/* ********** SORTING ********** */
void MaxSortDesc (TabInt *T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
{
    int i=0,a,b;
    for (a=0 ; a < NMax- IdxMin+1; a++){
        for ( b= 0; b < NMax-a-1; b++){
            if ((*T).TI[b] > (*T).TI[b+1]){
            i       = (*T).TI[b];
            (*T).TI[b]   = (*T).TI[b+1];
            (*T).TI[b+1] = i;
            }
        }

    }
}

void InsSortAsc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */
{
    int a,b,i=0;
    for (a=NMax- IdxMin+1 ; a > 0; a--){
        for ( b= NMax-a-1; b > 0; b--){
            if ((*T).TI[b] > (*T).TI[b-1]){
            i       = (*T).TI[b];
            (*T).TI[b]   = (*T).TI[b-1];
            (*T).TI[b-1] = i;
            }
        }

    }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    (*T).TI[NMax-1] = X;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    int i;
    for (i=0; i < NMax- IdxMin+1;i++){
        if ((*T).TI[i]== *X){
            (*T).TI[i] = 0;
        }
       }
}

void DelEli (TabInt * T, IdxType i, ElType * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{

}

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X)
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T,
        jika belum ada elemen yang bernilai X.
		Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S.
		dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{

}

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X)
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
{
    int i=0,a,b,c,n;
    for (a=0 ; a < NMax- IdxMin+1; a++){
        for ( b= 0; b < NMax-a-1; b++){
            if ((T).TI[b] > (T).TI[b+1]){
            i       = (T).TI[b];
            (T).TI[b]   = (T).TI[b+1];
            (T).TI[b+1] = i;
            }
        }

    }
    for (a=0 ; a < NMax- IdxMin+1; a++){
        if (n < (T).TI[i]){
                    n=(T).TI[i];
                    c=i;
                    return c;
                    break;
        }
    }return IdxUndef;
}
ElType MaxUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
{
    int i=0,a,b;
    for (a=0 ; a < NMax- IdxMin+1; a++){
        for ( b= 0; b < NMax-a-1; b++){
            if ((T).TI[b] > (T).TI[b+1]){
            i       = (T).TI[b];
            (T).TI[b]   = (T).TI[b+1];
            (T).TI[b+1] = i;
            }
        }

    }
}

ElType MinUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
{
    int a,b,i=0;
    for (a=NMax- IdxMin+1 ; a > 0; a--){
        for ( b= NMax-a-1; b > 0; b--){
            if ((T).TI[b] > (T).TI[b-1]){
            i       = (T).TI[b];
            (T).TI[b]   = (T).TI[b-1];
            (T).TI[b-1] = i;
            }
        }

    }
}

void MaxMinUrut (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{

}
