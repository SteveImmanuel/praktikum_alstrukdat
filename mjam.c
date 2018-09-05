/* File : mjam.c */

/*NIM				: 13517039
Nama				: Steve Andreas I
Tanggal				: 3 September 2018
Topik praktikum		: ADT
Deskripsi			: Driver ADT Jam*/

#include <stdio.h>
#include "jam.h"

int main(){
	JAM J1,J2,J3,J4;
	int i,dtk,drs;
	printf("Masukkan J1\n"); //test baca,tulis,konversi
	BacaJAM(&J1);
	printf("Jam terbaca : ");TulisJAM(J1);
	printf("Konversi jam menjadi detik : %d\n",JAMToDetik(J1));	
	printf("Masukkan detik : ");scanf("%d",&dtk);
	printf("Detik dalam jam : ");TulisJAM(DetikToJAM(dtk));
	printf("Masukkan J2\n");
	BacaJAM(&J2);
	printf("Masukkan J3\n");
	BacaJAM(&J3);
	if (JEQ(J2,J3)){ //test jeq,jneq,jlt,jgt
		printf("Jam sama\n");
	}else if (JNEQ(J2,J3)){
		if (JLT(J2,J3)){
			printf("Jam kedua lebih kecil dari jam ketiga\n");
		}else if (JGT(J2,J3)){
			printf("Jam ketiga lebih kecil dari jam kedua\n");
		}else{
			printf("error_function JLT,JGT\n");
		}
	}else{
		printf("error_function JEQ,JNEQ\n");
	}
	drs=Durasi(J2,J3);
	printf("Durasi dari J2 dengan J3 : %d\n",drs); //test prevdetik dan next detik
	for (i=1;i<=500;i++){
		J2=NextNDetik(J2,13);
		TulisJAM(J2);
	}
	for (i=1;i<=500;i++){
		J3=PrevNDetik(J3,29);
		TulisJAM(J3);
	}


	return 0;
}

