//nama: Ari Bambang Kurniawan
//NIM: 14115062
#include "queuelist.h"
#include <stdio.h>

float AvgElmt (Queue Q)
{
	/*Kamus Lokal*/
	double i=0;
	address bacaData = Head(Q);
	infotype baca=0;
	/*Algoritma*/
	while(bacaData!= Nil)
	{
		i++;
		baca+=Info(bacaData);
		bacaData = Next(bacaData);
	}
	
	return ((float)baca / (float)i);
}
/* Menghasilkan rata-rata elemen dalam queue Q
   yang tidak kosong */
int main()
{
	/*Kamus Lokal*/
	Queue list;
	infotype data;
	address baca;
	int n;
	/*Algoritma*/
	CreateEmpty(&list);
	scanf("%d",&n);
	while(n!=0)
	{
		if(n==1)
		{
			scanf("%d",&data);
			Add(&list,data);
		}else {
			if(n==2){
				if(IsEmpty(list))
				{
					printf("Queue kosong\n");
				}else{
					Del(&list,&data);
				}
			}
		}
		scanf("%d",&n);
	}
	printf("%d\n",NbElmt(list));
	if(NbElmt(list) == 0)
	{
		printf("Tidak bisa dihitung\n");
	}else{
		printf("%0.2f\n",AvgElmt(list));
		}
		
	return 0;
}
