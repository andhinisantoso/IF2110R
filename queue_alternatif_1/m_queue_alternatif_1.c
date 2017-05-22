#include "queue_alternatif_1.h"
int main()
{
	/*kamus*/
	Queue Q;
	int n,n2,i;
	int t = 0; // waktu masukan
	int pret = 0; // waktu sebelum t. cek pret<=t
	int tclose; // waktu tutup
	int visitor = 0;
	float srvtime = 0; // total waktu pelayanan
	float que = 0; // total antrian*waktu
	char input[6];
	boolean close;
	
	/*algoritma*/
	printf("Ukuran antrian : ");
	scanf("%d",&n);
	CreateEmpty(&Q,n);
	close = false;
	do {
		printf("Masukkan perintah: ");
		scanf("%d%s",&t,input);
		if(t<pret) printf("Waktu yang dimasukkan tidak valid, seharusnya >= %d\n",pret);
		else {
			switch(input[0]) {
				case 'tambah' : 
							if(IsFull(Q)) printf("antrian penuh, tidak bisa menerima pengunjung baru\n");
							else {	
								que+=NBElmt(Q)*(t-pret);
								Add(&Q,t);
								printf("Q = ");
								Print(Q);
							}
							break;
				case 'tampil' : 
							if(IsFull(Q)) printf("antrian penuh, tidak bisa menerima pengunjung baru\n");
							else {	
								printf("Q = ");
								Print(Q);
							}
							break;
				case 'tutup' :
							close = true;
							tclose = t;
							if (IsEmpty(Q)) 
								printf("Bank tutup, tidak ada pengunjung tersisa\n");
							else printf("Bank tutup, masih ada %d pengunjung tersisa\n",NBElmt(Q));
							break;
				case 'hapus' : 
							if(IsEmpty(Q))
								printf("Queue kosong, tidak ada pengunjung yang akan dilayani\n");
							else {
								visitor++;
								Del(&Q,&n);
								if(!close) que+=NBElmt(Q)*(t-pret);
								printf("waktu kedatangan = %d, waktu tunggu = %d, Q = ",n,t-n);
								Print(Q);
								srvtime += t-n;
							}
			}
			pret=t;
		}
	}while(!close || !IsEmpty(Q));

	printf("\nBank tutup pada t = %d, layanan selesai pada t = %d\n",tclose,t);
	if(visitor) {
		printf("Jumlah pengunjung dilayani: %d orang\n",visitor);
		printf("Waktu tunggu rata-rata: %.0f satuan waktu\n",srvtime/visitor);
		printf("Panjang antrian rata-rata: %.3f orang\n",que/tclose);
	} else printf("Tidak ada pengunjung yang dilayani\n");
	
	return 0;	
}
