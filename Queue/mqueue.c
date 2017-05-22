//nama: Ari Bambang Kurniawan
//NIM: 14115062
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

float AvgElmt (Queue Q){
	int i;
	int jmlh=0;
	if(Head(Q)==Tail(Q)){
		jmlh = InfoHead(Q);	
	}else{
		for ( i = Head(Q); i < Tail(Q); i++)
		{
			jmlh = jmlh + (Q).T[i];
		}
	jmlh = jmlh + InfoTail(Q);
}
	//Avg = jmlh/NBElmt(Q);
	return jmlh/(float)NBElmt(Q);
}

int main(){
	Queue Q;
	int NMax,X,p;
	float N=0,n=0;
	scanf("%d",&NMax);
	CreateEmpty(&Q,NMax);
	do{ 
		scanf("%d",&p);
	switch(p){

		case 1 : scanf("%d",&X);
		Add (&Q, X);
		break;

		case 2 : 
		Del (&Q,&X);
		break;

	}
}while(p!=0);
printf("%d\n",NBElmt(Q));
if (IsEmpty(Q))
{
	printf("Tidak bisa dihitung\n");
}else{
printf("%.2f\n",AvgElmt(Q));
}

}
