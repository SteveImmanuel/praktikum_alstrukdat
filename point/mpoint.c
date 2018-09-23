/* File : mjam.c */

/*NIM				    : 13517039
Nama				    : Steve Andreas I
Tanggal			        : 3 September 2018
Topik praktikum	        : ADT
Deskripsi		        : Driver ADT point*/

#include <stdio.h>
#include "point.h"

int main(){
	POINT P1,P2;float sudut,deltax,deltay;
	printf("Masukkan P1\n"); //test baca,tulis
	BacaPOINT(&P1);
	TulisPOINT(P1);
	printf("Masukkan P2\n");
	BacaPOINT(&P2);
	TulisPOINT(P2); //test eq,neq
	if (EQ(P1,P2)){
		printf("P1=P2\n");
	}else if(NEQ(P1,P2)){
		printf("P1!=P2\n");
	}else{
		printf("error_function EQ,NEQ");
	}
	if (IsOnSbX(P1)) printf("P1 di sumbu X\n");else printf("P1 tidak di sumbu X\n"); //test isonsbx,isonsby
	if (IsOnSbY(P2)) printf("P2 di sumbu Y\n");else printf("P2 tidak di sumbu Y\n");
	printf("Kuadran P1 dan P2 adalah %d dan %d\n",Kuadran(P1),Kuadran(P2)); //test kuadran
	printf("P1 geser 1 kanan geser 1 atas menjadi ");TulisPOINT(NextX(NextY(P1))); //test nextx,nexty
	printf("Masukkan deltax dan deltay : ");scanf("%f %f",&deltax,&deltay); //test geser
	Geser(&P2,deltax,deltay);
	printf("P2 geser deltax dan deltay ");TulisPOINT(P2);
	printf("Jarak0 dari P1 adalah %f\n",Jarak0(P1)); //test jarak0
	printf("Jarak P1 dan P2 adalah %f\n",Panjang(P1,P2)); //test panjang
	printf("P1 digeser ke origin\n"); //test geserkesbx,geserkesby,isorigin
	GeserKeSbX(&P1);
	GeserKeSbY(&P1);
	if (IsOrigin(P1)) printf("P1 berhasil digeser ke origin\n");else printf("error_function IsOrigin,GeserKeSbY,GeserKeSbX\n");
	printf("P2 dimirror terhadap sumbu X lalu sumbu Y\n");
	Mirror(&P2,true);TulisPOINT(P2); //test mirror
	Mirror(&P2,false);TulisPOINT(P2);
	printf("Masukkan Sudut (Derajat) : ");scanf("%f",&sudut); //test putar
	printf("P2 diputar");
	Putar(&P2,sudut);
	TulisPOINT(P2);
	return 0;
}