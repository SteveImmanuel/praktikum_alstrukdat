/*  NIM					: 13517039
    Nama				: Steve Andreas Immanuel
    Tanggal				: 25 Oktober 2018
    Topik praktikum		: List linier
    Deskripsi			: menggunakan listlinier
*/

#include <stdio.h>
#include "listlinier.h"

/*
infotype Min (List L)
// Mengirimkan nilai Info(P) yang minimum 
{
	address P=First(L);
	infotype min=Info(P);
	P=Next(P);
	while(P!=Nil){
		if(Info(P)<min){
			min=Info(P);
		}
		P=Next(P);
	}
	return min;
}
*/
/*
float Average (List L)
// Mengirimkan rata2 dari nilai list 
{
	address P=First(L);
	infotype sum=Info(P);
	int i=1;
	P=Next(P);
	while(P!=Nil){
		sum+=Info(P);
		i++;
		P=Next(P);
	}
	return (float)sum/(float)i;
}
*/
List sortAscend(List L)
//elemen list setidaknya ada satu
{
	List sorted;
	address P=First(L);
	int nbelmt=NbElmt(L);
	
	CreateEmpty(&sorted);
	if(nbelmt>0){
		while(P!=Nil){
				infotype min=Min(L);
				InsVLast(&sorted,min);
				DelP(&L,min);
				if(IsEmpty(L)){
					P=Nil;
				}else{
				P=First(L);		
				}	
		}
	}
	return sorted;
}

void inversList(List *L)
{
		address P=First(*L);
		address prec=Nil;
		address precprec=Nil;
		while(P!=Nil){
			if(prec!=Nil){
				Next(prec)=precprec;
			}
			precprec=prec;
			prec=P;
			P=Next(P);
		}
		if(prec!=Nil){
			Next(prec)=precprec;
		}
		First(*L)=prec;
}



int main(){
	List L;
	infotype x;
	address p;
	CreateEmpty(&L);
	do{
		scanf("%d",&x);
		if(x>=0&&x<=100){
			p=Alokasi(x);
			InsertLast(&L,p);
		}
	}while(x>=0&&x<=100);
	if(IsEmpty(L)){
		printf("Daftar nilai kosong\n");
	}else{
		int nbelmt=NbElmt(L);
		infotype max=Max(L);
		infotype min=Min(L);
		float average=Average(L);
		List sorted=sortAscend(L);
		printf("%d\n",nbelmt);
		printf("%d\n",max);
		printf("%d\n",min);
		printf("%.2f\n",average);
		PrintInfo(sorted);
		printf("\n");
		inversList(&sorted);
		PrintInfo(sorted);
		printf("\n");
	}
	
	
	
	
	
	
	
	
	
	return 0;
}
