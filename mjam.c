/* File : mjam.c */
/* Program Utama mjam */

#include <stdio.h>
#include "jam.h"

int main(){
	JAM J1,J2,J3;
	int a,b,c;
	BacaJAM(&J1);
	printf("Jam sekarang: ");TulisJAM(J1);printf("\n");
	printf("Konversi jam menjadi detik : %d\n",JAMToDetik(J1));	
	J2=DetikToJAM(5000);
	TulisJAM(J2);printf(" sama dengan 5000 detik\n");
	scanf("%d %d %d",&a,&b,&c);printf("\n");
	return 0;
}

