/* NIM/Nama		: 13517039
   Nama			: Steve Andreas I
   Nama file	: listlinier.c
   Tanggal		: 18-10-2018
   Deskripsi	: Body listlinier.h*/

#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
	return First(L)==Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	First(*L)=Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	address pt;
	pt=(address)malloc(sizeof(ElmtList));
	if(pt!=Nil){
		Info(pt)=X;
		Next(pt)=Nil;
	}
	return pt;
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	if (IsEmpty(L)){
		return Nil;
	}else{
		address P=First(L);
		while((Info(P)!=X)&&(Next(P)!=Nil)){
			P=Next(P);
		}
		if(Info(P)==X){
			return P;
		}else{
			return Nil;
		}
	}
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address P=Alokasi(X);
	if(P!=Nil){
		InsertFirst(L,P);
	}
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	address P=Alokasi(X);
	if(P!=Nil){
		InsertLast(L,P);
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	address P;
	DelFirst(L,&P);
	*X=Info(P);
	Dealokasi(&P);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address last;
	DelLast(L,&last);
	*X=Info(last);
	Dealokasi(&last);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	Next(P)=First(*L);
	First(*L)=P;
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	Next(P)=Next(Prec);
	Next(Prec)=P;
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if(IsEmpty(*L)){
		InsertFirst(L,P);
	}else{
		address pt=First(*L);
		while(Next(pt)!=Nil){
			pt=Next(pt);
		}
		Next(pt)=P;
		Next(P)=Nil;	
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P=First(*L);
	First(*L)=Next(*P);
	Next(*P)=Nil;
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	address P,Prec;
	P=First(*L);
	Prec=Nil;
	while((Info(P)!=X)&&(Next(P)!=Nil)){
		Prec=P;
		P=Next(P);
	}
	if(Info(P)==X){
		if(Prec==Nil){
			DelFirst(L,&P);
		}else{
			Next(Prec)=Next(P);
			Next(P)=Nil;
		}
		Dealokasi(&P);
	}
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
	address last,prec;
	last=First(*L);
	prec=Nil;
	while(Next(last)!=Nil){
		prec=last;
		last=Next(last);
	}
	if(prec==Nil){
		DelFirst(L,P);
	}else{
		*P=last;
		Next(prec)=Nil;
	}
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel=Next(Prec);
	Next(Prec)=Next(*Pdel);
	Next(*Pdel)=Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	address P=First(L);
	printf("[");
	while(P!=Nil){
		printf("%d",Info(P));
		if(Next(P)!=Nil){
			printf(",");
		}
		P=Next(P);
	}
	printf("]");
}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list mengirimkan 0 jika list kosong */
{
	int count=0;
	address P=First(L);
	while(P!=Nil){
		count++;
		P=Next(P);
	}
	return count;
}
/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
	address P=First(L);
	infotype max=Info(P);
	P=Next(P);
	while(P!=Nil){
		if(Info(P)>max){
			max=Info(P);
		}
		P=Next(P);
	}
	return max;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
	CreateEmpty(L3);
	address P,temp;
	if(!IsEmpty(*L1)){
		P=First(*L1);
		while(P!=Nil){
			DelFirst(L1,&temp);
			InsertLast(L3,temp);
			P=First(*L1);
		}
	}
	if(!IsEmpty(*L2)){
		P=First(*L2);
		while(P!=Nil){
			DelFirst(L2,&temp);
			InsertLast(L3,temp);
			P=First(*L2);
		}
	}
}

void inversList(List *L)
{
	address P=First(*L);
	address Prec=Nil;
	address PrecPrec=Nil;
	while(P!=Nil){
		/*printf("%d\n",P);
		temp=Next(P);
		if(temp!=Nil){
			Next(P)=Prec;
			Prec=P;
			P=temp;
			printf("masuk if1\n");
		}else{
			Next(P)=Prec;
			First(*L)=P;
			P=Nil;
			printf("masuk if2\n");
		}*/
		if(Prec!=Nil){
			Next(Prec)=PrecPrec;
		}
		PrecPrec=Prec;
		Prec=P;
		P=Next(P);
	}
	if(Prec!=Nil){
		Next(Prec)=PrecPrec;
	}
	First(*L)=Prec;
}

void PecahList (List *L1, List *L2, List L) 
{
	CreateEmpty(L1);
	CreateEmpty(L2);
	int half=NbElmt(L)/2;
	int i=0;
	address P=First(L);
	address Pt=First(*L1);
	while(P!=Nil){
		i++;
		while(i<=half){
			address aloc=Alokasi(Info(P));
			if(Pt==Nil){
				Pt=aloc;
				First(*L1)=Pt;
			}else{
				Next(Pt)=aloc;
				Pt=aloc;
			}
			P=Next(P);
			i++;
		}
		Pt=First(*L2);
		while(i<=NbElmt(L)){
			address aloc=Alokasi(Info(P));
			if(Pt==Nil){
				Pt=aloc;
				First(*L2)=Pt;
			}else{
				Next(Pt)=aloc;
				Pt=aloc;
			}
			P=Next(P);
			i++;
		}


	}
}








/*
 * Konkat
 * I.S. L1 dan L2 sembarang
 * F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2
 * Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi
 * Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi
 * harus di-dealokasi dan L3=Nil
 * Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru"
 * Elemen L3 adalah hasil alokasi elemen yang "baru".
 * Jika ada alokasi yang gagal, maka L3 harus bernilai Nil
 * dan semua elemen yang pernah dialokasi didealokasi
*/
void Konkat2 (List L1, List L2, List * L3) 
{
	CreateEmpty(L3);
	address Pt=First(L1);
	boolean berhasil=true;
	address P=First(*L3);
	int alokasi1=1;
	if(Pt==Nil&&alokasi1==1){
		Pt=First(L2);
		alokasi1++;
	}
	while((Pt!=Nil)&&berhasil){
		address aloc=Alokasi(Info(Pt));
		if(aloc!=Nil){
			berhasil=true;
		}else{
			berhasil=false;
		}
		if(berhasil){
			if(P==Nil){
				P=aloc;
				First(*L3)=P;
			}else{
				Next(P)=aloc;
				P=aloc;
			}
		}
		Pt=Next(Pt);
		if(Pt==Nil&&alokasi1==1){
			Pt=First(L2);
			alokasi1++;
		}
	}
	if(!berhasil){
		//dealokasi L3
	}


}