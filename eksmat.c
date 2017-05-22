#include "bintree.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "string.h"


void BuildTreeFromString (BinTree *P, char *st, int *idx){
	(*idx)++;
	if (*st[*idx]==')'){
		(*P)==Nil;
	}
	else{
		AlokNode(&P,*st[*idx]);
		(*idx)++;
		BuildBalanceTree(&Left(*P),*st,*idx);
		BuildBalanceTree(&Right(*P),*st,*idx);
		}
	(*idx)++;
	}

printf("\n");
int main(){
	BinTree P;
	MakeTree(1,Nil,Nil,&P);	
}
