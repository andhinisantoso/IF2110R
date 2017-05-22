//Ari Bambang Kurniawan
//14115062
#include "pohonbiner.h"
int main()
{
	/*kamus*/
	BinTree P;
	int X,i;
	/*algoritma*/
	MakeTree(1,Nil,Nil,&P);
	for (i=1;i<5;i++)
		AddDaun(&P,i,i+1,true);
		
	PrintPreorder(P);
		
	printf("Masukkan nilai dari daun yang dicari : ");
	int a;
	scanf("%d", &a);
	SearchPB(P,a);
	if(SearchPB(P,a)==true){
		
		printf("---> %d ada dalam pohon dan mempunyai keturunan berikut: \n",a);
		PrintDescendants(P,a);
	}
	else if(SearchPB(P,a)==true) {
			printf("%d tidak punya keturunan",a);
			}
		
	else{
		printf("%d tidak ada dalam pohon\n",a);
		}

	return 0;
}
