//nama: Ari Bambang Kurniawan
//NIM: 14115062
#include"stackt.h"
#include<stdio.h>

int main(){
	Stack S;
	int N;
	int j=0;
	infotype i;
	
	CreateEmpty(&S);
	
	scanf("%d",&N);
	for(i=1; i<=N; i++){
		if(i%2==0){
		}
		else{
			Push(&S,i);
		}
	}
	
	while(!IsEmpty(S)){
		printf("%d\n",InfoTop(S));
		Pop(&S,&i);
		j++;
		
	}
	printf("Empty stack\n");
	printf("%d",j);
	printf("\n");
	return 0;
	
}
