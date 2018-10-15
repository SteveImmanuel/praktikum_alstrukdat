/* File : mtanggal.c */
/* Program Utama mtanggal */

#include <stdio.h>
#include "tanggal.c"

int main(){
	TANGGAL T;
	int i;
	BacaTANGGAL(&T);
	TulisTANGGAL(T);
	for (i=1;i<=365;i++){
		T=PrevDay(T);
		TulisTANGGAL(T);
		printf("\n");
	}printf("\n");
	printf("%d",HariKe(T));
	return 0;
}