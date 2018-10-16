/*
NIM					: 13517039
Nama				: Steve Andreas I
Tanggal				: 6 September 2018
Topik praktikum		: 
Deskripsi			:
*/

#include <stdio.h>
#include <math.h>
#include "garis.h"
#include "boolean.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* *** Konstruktor membentuk GARIS *** */
void MakeGARIS(POINT P1, POINT P2, GARIS *L)
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */
{
	Absis(PAwal(*L))=Absis(P1);
	Ordinat(PAwal(*L))=Ordinat(P1);
	Absis(PAkhir(*L))=Absis(P2);
	Ordinat(PAkhir(*L))=Ordinat(P2);	
}

/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
void BacaGARIS(GARIS *L)
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai GARIS yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat 
   membentuk GARIS yang valid 
   GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan garis tidak valid, diberikan pesan kesalahan: 
   "Garis tidak valid" */
/* Contoh:
   2 3
   2 3
   Garis tidak valid
   2 3
   3 3 
   --> terbentuk garis L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */
{
	POINT p1,p2;
	do{
		BacaPOINT(&p1);
		BacaPOINT(&p2);
		if (EQ(p1,p2)) printf("Garis tidak valid\n");
	}while(EQ(p1,p2));
	MakeGARIS(p1,p2,L);
	
}
void TulisGARIS(GARIS L)
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */
{
	printf("((%.2f,%.2f),(%.2f,%.2f))",PAwal(L).X,PAwal(L).Y,PAkhir(L).X,PAkhir(L).Y);
}

/* *** Kelompok operasi garis *** */
float PanjangGARIS(GARIS L)
/* Menghitung panjang garis L : (((y2-y1) ^ 2) + ((x2-x1) ^ 2)) ^ 0.5 */
{
	return Panjang(PAwal(L),PAkhir(L));
}
float Gradien(GARIS L)
/* Mengembalikan Gradien (m) dari L */
/* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */
{
	float x1,x2,y1,y2;
	x1=PAwal(L).X;y1=PAwal(L).Y;
	x2=PAkhir(L).X;y2=PAkhir(L).Y;
	return ((y2-y1)/(x2-x1));
}
void GeserGARIS(GARIS *L, float deltaX, float deltaY)
/* I.S. L terdefinisi */
/* F.S. L digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu Y */
/* Proses : PAw dan PAkh digeser. */
{
	PAwal(*L)=PlusDelta(PAwal(*L), deltaX, deltaY);
	PAkhir(*L)=PlusDelta(PAkhir(*L), deltaX, deltaY);
}
/* *** Kelompok predikat *** */
boolean IsTegakLurus(GARIS L1, GARIS L2)
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */
{
	float m1=Gradien(L1);
	float m2=Gradien(L2);
	return m1*m2==-1;
}
boolean IsSejajar(GARIS L1, GARIS L2)
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */
{
	float m1=Gradien(L1);
	float m2=Gradien(L2);
	return m1==m2;
}


