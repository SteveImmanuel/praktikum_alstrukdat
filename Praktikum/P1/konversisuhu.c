/* NIM/Nama		: 13517039/Steve Andreas I
   Nama file	: konversisuhu.c
   Tanggal		: 30-08-2018
   Deskripsi	: Mengonversi suhu*/

#include <stdio.h>
int main(){
	float t,x;
	char k;
	scanf("%f\n",&t);
	scanf("%c",&k);
	if (k=='R'){
		x=((float)4/(float)5)*t;
	}else if(k=='F'){
		
		x=(((float)9/(float)5)*t)+32;
	}else if(k=='K'){
		x=t+273.15;
		
	}
	printf("%.2f\n",x);
	return 0;
}
