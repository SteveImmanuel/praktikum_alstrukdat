/* File : array.h */

/*NIM            : 13517039
Nama             : Steve Andreas I
Tanggal          : 3 September 2018
Topik praktikum  : ADT
Deskripsi        : Driver ADT array*/

#include <stdio.h>
#include "array.h"


int main(){
	TabInt T1,T2,temp; //input output biasa;
	ElType X,max,min;
	IdxType i;
	MakeEmpty(&T1);
	BacaIsi(&T1);
	TulisIsi(T1);
	scanf("%d",&X);
	//MakeEmpty(&T2);
	//BacaIsi(&T2);
	//TulisIsi(T2);
	//scanf("%d",&i);
	/*printf("%d\n",NbElmt(T1));
	
	printf("%d\n",NbElmt(T2));
	TulisIsi(PlusTab(T1,T2));
	printf("\n");
	TulisIsi(MinusTab(T1,T2));
	printf("\n");
	TulisIsi(KaliTab(T1,T2));
	printf("\n");
	TulisIsi(KaliKons(T1,5));
	printf("\n");
	printf("%d\n",IsEQ(T1,T2));
	printf("%d\n",IsLess(T1,T2));

	printf("%d\n",ValMax(T1));
	printf("%d\n",ValMin(T1));
	printf("%d\n",IdxMaxTab(T1));
	printf("%d\n",IdxMinTab(T1));
	CopyTab(T1,&T2);
	TulisIsiTab(T2);
	TulisIsi(InverseTab(T2));
	printf("%d\n",IsSimetris(T1));
	InsSortAsc(&T1);
	TulisIsi(T1);
	AddEli(&T1,X,i);
	TulisIsi(T1);
	DelEli(&T1,i,&X);
	TulisIsi(T1);
	printf("%d",X);
	AddElUnik(&T1,X);
	TulisIsiTab(T1);
	printf("%d\n",SearchUrut(T1,X));
	printf("%d\n",MaxUrut(T1));
	printf("%d\n",MinUrut(T1));
	MaxMinUrut(T1,&max,&min);
	printf("%d %d\n",max,min);
	Add1Urut(&T1,X);
	TulisIsi(T1);
	Del1Urut(&T1,X);
	TulisIsi(T1);
	printf("%d\n",Search1(T1,X));
	printf("%d\n",Search2(T1,X));
	printf("%d\n",SearchB(T1,X));
	printf("%d\n",SearchSentinel(T1,X));*/
	AddElUnik(&T1,X);
	TulisIsi(T1);
	return 0;
}