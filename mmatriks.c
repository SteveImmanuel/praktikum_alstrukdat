#include <stdio.h>
#include "matriks.h"

int main(){
	MATRIKS M1,M2;
	indeks nb,nk;
	scanf("%d",&nb);
	scanf("%d",&nk);
	BacaMATRIKS(&M1,nb,nk);
	printf("baris=%d kolom=%d\n",NBrsEff(M1),NKolEff(M1));
	TulisMATRIKS(M1);
	//BacaMATRIKS(&M2,nb,nk);
	//printf("baris=%d kolom=%d\n",NBrsEff(M2),NKolEff(M2));
	//TulisMATRIKS(M2);
	//PKaliKons(&M1,6);
	//Transpose(&M1);
	//Transpose(&M1);
	//TulisMATRIKS(M1);printf("\n");
	printf("%d\n",IsSimetri(M1));
	//printf("%d\n",EQ(M1,M2));
	return 0;
}
