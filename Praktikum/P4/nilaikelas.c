/*  NIM					: 13517039
    Nama				: Steve Andreas I
    Tanggal				: 20 September 2018
    Topik praktikum		: Matriks
    Deskripsi
*/

#include <stdio.h>
#include "matriks.h"

void TulisNilaiX (MATRIKS M, indeks j, ElType X)
/*{ Menuliskan nomor urut mahasiswa yang mendapatkan nilai X pada mata kuliah dengan nomor urut j. }
{ Pada dasarnya: Menuliskan semua indeks baris pada kolom j dengan nilai elemen = X. }
{ Nomor urut mahasiswa dituliskan dalam 1 baris, masing-masing dipisahkan koma, diawali [, diakhiri ], tanpa tambahan karakter apa pun (termasuk spasi dan enter) di awal maupun akhir }
{ I.S. M terdefinisi, j adalah indeks kolom efektif M, X terdefinisi }
{ F.S. Menuliskan semua indeks baris pada kolom j dengan nilai = X.
Jika tidak ada elemen dengan nilai = X, menuliskan [] */
/*{ Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
1 3 3
2 5 6
7 3 9
maka jika j = 2 dan X = 3, akan tercetak: [1,3]
}*/
{
	indeks k=GetFirstIdxBrs(M);
	int countx=CountXKol(M,j,X);
	if(countx==0){
		printf("[]");
	}else if (countx==1){
		while((k<GetLastIdxBrs(M))&&((Elmt(M,k,j)!=X))){
			k++;
		}
		printf("[%d]",k);
	}else{
		int i=1;
		printf("[");
		while(k<=GetLastIdxBrs(M)){
			if((Elmt(M,k,j)==X)&&(i<countx)){
				printf("%d,",k);
				i++;
			}else if((Elmt(M,k,j)==X)&&(i==countx)){
				printf("%d]",k);
			}
			k++;
		}
	}
}

void TulisStatistikMhs (MATRIKS M, indeks i)
/*{ Menuliskan statistik untuk mahasiswa dengan nomor urut i. }
{ Statistik yang dituliskan adalah: nilai rata-rata, nilai mata kuliah tertinggi, nilai mata kuliah terendah. }
{ Pada dasarnya: menuliskan statistik untuk data pada baris ke-i }
{ I.S. M terdefinisi, i adalah indeks baris efektif M }
{ F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
[i] <rata-rata> <nilai max> <nilai min> }
{ Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
100 83 83
72 55 60
77 93 90
maka jika i = 2 akan tercetak:
[2] 62.33 72 55
}*/
{
	ElType max,min;
	MaxMinBrs(M,i,&max,&min);
	printf("[%d] %.2f %d %d",i,RataBrs(M,i),max,min);
}

void TulisStatistikMK (MATRIKS M, indeks j)
/*{ Menuliskan statistik untuk mata kuliah dengan nomor urut j. }
{ Statistik yang dituliskan adalah: nilai rata-rata, nilai tertinggi (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya), nilai mata kuliah terendah (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya). }
{ Pada dasarnya: menuliskan statistik untuk data pada kolom ke-j }
{ I.S. M terdefinisi, j adalah indeks kolom efektif M }
{ F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4
[j] <rata-rata> [max <nilai max> <#max> [<daftar max>]] [min <nilai min> <#min> [<daftar min>]] }
{ Contoh: Jika M adalah matriks 3x3 dan isinya adalah:
100 83 83
72 55 60
77 93 90
maka jika j = 2 akan tercetak:
[2] 77.00 [93 1 [3]] [55 1 [2]]
}*/
{
	ElType max,min;
	indeks temp=j;
	MaxMinKol(M,j,&max,&min);
	printf("[%d] %.2f [%d %d ",j,RataKol(M,j),max,CountXKol(M,j,max));
	TulisNilaiX(M,temp,max);
	printf("] [%d %d ",min,CountXKol(M,j,min));
	TulisNilaiX(M,temp,min);
	printf("]");
}

int main(){
	int m,n;
	MATRIKS M;
	indeks k;
	scanf("%d",&m);
	scanf("%d",&n);
	MakeMATRIKS(m,n,&M);
	BacaMATRIKS(&M,m,n);
	printf("STATISTIK PER MAHASISWA\n");
	for(k=GetFirstIdxBrs(M);k<=GetLastIdxBrs(M);k++){
		TulisStatistikMhs(M,k);printf("\n");
	}
	printf("STATISTIK PER MATA KULIAH\n");
	k=GetFirstIdxKol(M);
	for(k=GetFirstIdxKol(M);k<=GetLastIdxKol(M);k++){
		TulisStatistikMK(M,k);printf("\n");
	}
	return 0;
}
/*
3

4[4] 66.67 [74 2 [1,2]] [52 1 [3]]
 [4] 66.67 [74 2 [1,2]] [52 1 [3]]


99 88 100 74

78 85 85 74

41 52 75 52*/
