/*
NIM					: 13517039
Nama				: Steve Andreas I
Tanggal				: 6 September 2018
Topik praktikum		: 
Deskripsi			: 
*/

#include <stdio.h>
#include "jam.h"

int main(){
	int n,i;
	JAM j1,j2,jmin,jmax;
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		printf("[%d]\n",i);
		BacaJAM(&j1);
		BacaJAM(&j2);
		
		if (JLT(j1,j2)){
			printf("%ld\n",Durasi(j1,j2));
			if (i==1){
				jmin=j1;jmax=j2;
			}
			if (JLT(j1,jmin)){
				jmin=j1;
			}
			if (JGT(j2,jmax)){
				jmax=j2;
			}
		}else{
			printf("%ld\n",Durasi(j2,j1));
			if (i==1){
				jmin=j2;jmax=j1;
			}
			if (JLT(j2,jmin)){
				jmin=j2;
			}
			if (JGT(j1,jmax)){
				jmax=j1;
			}
		}
	}
	TulisJAM(jmin);printf("\n");
	TulisJAM(jmax);printf("\n");

	return 0;
}
