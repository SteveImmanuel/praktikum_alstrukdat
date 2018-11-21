// Nama/NIM		: Steve Andreas I / 13517039
// Tanggal		: 8 Nov 2018
// Topik		: List
// Deskripsi 	: Menggunakan List

#include <stdio.h>
#include "listrek.h"

void bagigangen(List L,List* L1,List* L2,int posisi);
//L1 indeks ganjil,L2 indeks genap

List SplitOddIndex(List L);
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada indeks
ganjil pada list L, sesuai dengan urutannya. Elemen HEAD merupakan indeks 1.
Jika tidak ada elemen yang bisa diambil, kembalikan Nil */

List SplitEvenIndex(List L);
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada indeks
genap pada list L, sesuai dengan urutannya. Elemen HEAD merupakan indeks 1.
Jika tidak ada elemen yang bisa diambil, kembalikan Nil */

List SplitBeforeX(List L, infotype X);
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen di depan elemen
dengan nilai X pada list L, sesuai dengan urutannya. Jika X tidak ada pada list, maka
kembalikan list L.
Jika tidak ada elemen yang bisa diambil, kembalikan Nil */

List ReverseList(List L);
/* Mengembalikan sebuah list baru yang urutannya merupakan kebalikan dari list L.
Jika L kosong, kembalikan list kosong. */

int main(){
	List L=Nil;
	infotype el;
	boolean operasi=false;
	char input[1];
	do{
		scanf("%s",input);
		if(input[0]=='F'){
			scanf("%d",&el);
			L=Konso(el,L);
			operasi=true;
		}else if(input[0]=='B'){
			scanf("%d",&el);
			L=KonsB(L,el);
			operasi=true;
		}else if(input[0]=='O'){
			L=SplitOddIndex(L);
			operasi=true;
		}else if(input[0]=='E'){
			L=SplitEvenIndex(L);
			operasi=true;
		}else if(input[0]=='R'){
			L=ReverseList(L);
			operasi=true;
		}else if(input[0]=='P'){
			scanf("%d",&el);
			L=SplitBeforeX(L,el);
			operasi=true;
		}
	}while(input[0]!='X');
	if (!IsEmpty(L)&&operasi){
		PrintList(L);
	}else{
		printf("Semua gugur\n");
	}
	return 0;
}

List SplitOddIndex(List L)
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada indeks
ganjil pada list L, sesuai dengan urutannya. Elemen HEAD merupakan indeks 1.
Jika tidak ada elemen yang bisa diambil, kembalikan Nil */
{
	List L1=Nil,L2=Nil;
	bagigangen(L,&L1,&L2,1);
	return L1;
}

List SplitEvenIndex(List L)
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada indeks
genap pada list L, sesuai dengan urutannya. Elemen HEAD merupakan indeks 1.
Jika tidak ada elemen yang bisa diambil, kembalikan Nil */
{
	List L1=Nil,L2=Nil;
	bagigangen(L,&L1,&L2,1);
	return L2;
}

List SplitBeforeX(List L, infotype X)
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen di depan elemen
dengan nilai X pada list L, sesuai dengan urutannya. Jika X tidak ada pada list, maka
kembalikan list L.
Jika tidak ada elemen yang bisa diambil, kembalikan Nil */
{
	if(Search(L,X)){
		if(FirstElmt(L)==X){
			return Nil;
		}else{
			if(Tail(L)!=Nil){
				if(FirstElmt(Tail(L))==X){
					List temp=Nil;
					temp=Konso(FirstElmt(L),temp);
					return temp;
				}else{
					return Konso(FirstElmt(L),SplitBeforeX(Tail(L),X));
				}
			}
		}
	}else{
		return L;
	}
}

List ReverseList(List L)
/* Mengembalikan sebuah list baru yang urutannya merupakan kebalikan dari list L.
Jika L kosong, kembalikan list kosong. */
{
	if(IsEmpty(L)){
		return L;
	}else{
		return KonsB(ReverseList(Tail(L)),FirstElmt(L));
	}	
}


void bagigangen(List L,List* L1,List* L2,int posisi)
//L1 indeks ganjil,L2 indeks genap, posisi 1 jika ganjil, 2 jika genap
{
	if(IsEmpty(L)){
		//nothing
	}else{
		if(posisi==1){
			*L1=KonsB(*L1,FirstElmt(L));
			bagigangen(Tail(L),L1,L2,2);
		}else if(posisi==2){
			*L2=KonsB(*L2,FirstElmt(L));
			bagigangen(Tail(L),L1,L2,1);
		}
	}
}

