//NIM		: 13517039
//Nama 		: Steve Andreas I
//Tanggal	: 4 Oktober 2018
//Topik		: queue
//Deskripsi	: membuat sistem antrian

#include <stdio.h>
#include "queue.h"

int main(){
	int n,kode,x,temp,i,sum,banyak;
	Queue q;
	scanf("%d",&n);
	CreateEmpty(&q,n);
	do{
		scanf("%d",&kode);
		if(kode==1){
			scanf("%d",&x);
			if(IsFull(q)){
				printf("Antrian penuh\n");
			}else{
				Add(&q,x);
			}
		}else if(kode==2){
			if(IsEmpty(q)){
				printf("Antrian kosong\n");
			}else{
				Del(&q,&temp);
			}
		}
	}while(kode!=0);
	banyak=NBElmt(q);
	sum=0;
	if(IsEmpty(q)){
		printf("%d\n",banyak);
		printf("Tidak bisa dihitung\n");
	}else{
		while(!IsEmpty(q)){
			Del(&q,&temp);
			sum+=temp;
		}
		printf("%d\n%.2f\n",banyak,(float)sum/(float)banyak);
	}
	
	
	
	return 0;
}
