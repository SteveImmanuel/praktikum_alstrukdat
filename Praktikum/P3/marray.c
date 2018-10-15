/*	NIM					: 13517039
	Nama				: Steve Andreas I
	Tanggal				: 13 September 2018
	Topik praktikum		: Array
	Deskripsi			: Memberi keterangan dari array input
*/
#include <stdio.h>
#include "array.h"

int main(){
	TabInt T,temp;
	int x,muncul,banyak;
	ElType temp_el;
	BacaIsi(&T);
	scanf("%d",&x);
	TulisIsiTab(T);
	printf("\n");
	muncul=Search1(T,x);
	if (muncul==IdxUndef){
		printf("0\n");
		printf("%d tidak ada\n",x);	
	}else{
		CopyTab(T,&temp);
		banyak=0;
		while(Search1(temp,x)!=IdxUndef){
			banyak++;
			DelEli(&temp,Search1(temp,x),&temp_el);
		}
		printf("%d",banyak);printf("\n");
		printf("%d",muncul);printf("\n");
		InsSortAsc(&T);
		if (ValMax(T)==x){
			printf("maksimum\n");
		}
		if (ValMin(T)==x){
			printf("minimum\n");
		}
		if (NbElmt(T)%2==1){
			if(Elmt(T,(NbElmt(T)/2)+1)==x){
				printf("median\n");
			}
		}else{
			if(Elmt(T,NbElmt(T)/2)==x){
				printf("median\n");
			}
		}
	}
	return 0;
}
