/* File : mjam.c */
/* Program Utama mpoint */
#include <stdio.h>
#include "point.h"

int main(){
	POINT P;float sudut;
	BacaPOINT(&P);
	TulisPOINT(P);
	printf("Masukkan Sudut (Derajat) : ");scanf("%f",&sudut);
	Putar(&P,sudut);
	TulisPOINT(P);
	return 0;
}