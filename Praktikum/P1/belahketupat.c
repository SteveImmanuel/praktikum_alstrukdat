/* NIM/Nama		: 13517039/Steve Andreas I
   Nama file	: belahketupat.c
   Tanggal		: 30-08-2018
   Deskripsi	: Menggambar belahketupat*/

#include <stdio.h>
#include <stdbool.h>
void GambarBelahKetupat(int *n);//menggambar belah ketupat
bool IsValid(int n);//memvalidasi

int main(){
	int n;
scanf("%d",&n);

if ((!IsValid(n))||n<0){
	printf("Masukan tidak valid\n");
}else{
	GambarBelahKetupat(&n);
}
return 0;
}

void GambarBelahKetupat(int *n){
	int i,j;
	for (i=1;i<=*n;i+=2){
		for(j=1;j<=((*n-i)/2);j++){
			printf(" ");
		}
		for(j=1;j<=(i);j++){
			printf("*");
		}
		printf("\n");
	}
	for (i-=4;i>=0;i-=2){
		for(j=1;j<=((*n-i)/2);j++){
			printf(" ");
		}
		for(j=1;j<=(i);j++){
			printf("*");
		}
		printf("\n");
	}
}
bool IsValid(int n){
		return (n%2==1)&&(n>=1);
}
