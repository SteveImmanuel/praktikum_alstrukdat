//NIM		: 13517039
//Nama 		: Steve Andreas I
//Tanggal	: 4 Oktober 2018
//Topik		: queue
//Deskripsi	: 

/* File : prioqueue.h */
/* Definisi ADT Priority Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut mengecil berdasarkan elemen prio */

#include "prioqueue.h"
#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
		return (Head(Q)==Nil&&Tail(Q)==Nil);
}
boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
		return (NBElmt(Q)==MaxEl(Q));
}
int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
		if(IsEmpty(Q)){
			return 0;
		}else{
			if(Head(Q)<=Tail(Q)){
				return Tail(Q)-Head(Q)+1;
			}else{
				return MaxEl(Q)-Head(Q)+1+Tail(Q);
			}
		}
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	(*Q).T = (infotype*) malloc((Max + 1) * sizeof(infotype));
	if((*Q).T!=NULL){
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
		MaxEl(*Q) = Max;
	}else{
		MaxEl(*Q) = 0;
	}
	
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
	MaxEl(*Q) = 0;
	free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
{
		if(IsEmpty(*Q)){
			Head(*Q)=1;
			Tail(*Q)=1;
			InfoHead(*Q)=X;
		}else{
			/*infotype temp[MaxEl(*Q)+2];
			int i,j=1,indeks;
			for(i=Head(*Q);i!=Tail(*Q);i++){
				temp[j]=(*Q).T[i];
				i=(i+1)%MaxEl(*Q);
				j++;
			}
			j--;
			infotype temp2=X;
			
			while(Prio(temp2)>Prio(temp[j])&&j>1){
				temp[j+1]=temp[j];
				j--;
			}
			if(Prio(temp2)<=Prio(temp[j]){
				indeks=j+1;
			}else{
				indeks=1;
			}*/
			/*address i=Tail(*Q);
			printf("i:%d\n",i);
			if(Tail(*Q)==MaxEl(*Q)){
				Tail(*Q)=1;
			}else{
				if(Tail(*Q)<Head(*Q)){
					i+=MaxEl(*Q);
				}
				Tail(*Q)++;
			}
			infotype temp=X;
			printf("prio temp:%d\n",Prio(temp));
			printf("prio elmt ke-%d:%d\n",i,Elmt(*Q,i%MaxEl(*Q)));
			printf("Prio(temp)>Prio(Elmt(*Q,i%MaxEl(*Q)):%d\n",Prio(temp)>Prio(Elmt(*Q,i%MaxEl(*Q))));
			printf("i>Head(*Q):%d\n",i>Head(*Q));
			
			while(Prio(temp)>Prio(Elmt(*Q,(i-1)%MaxEl(*Q)+1))&&(i>Head(*Q))){
				Elmt(*Q,i%MaxEl(*Q)+1)=Elmt(*Q,(i)%MaxEl(*Q));
				i--;
				printf("masuk while\n");
			}
			if(Prio(temp)<=Prio(Elmt(*Q,i%MaxEl(*Q)))){
				Elmt(*Q,i%MaxEl(*Q)+1)=temp;
				printf("masuk if1\n");
			}else{
				Elmt(*Q,(i)%MaxEl(*Q)+1)=Elmt(*Q,(i)%MaxEl(*Q));
				Elmt(*Q,(i)%MaxEl(*Q))=temp;
				printf("masuk if2\n");
			}*/
			infotype temp;
			Tail(*Q)=Tail(*Q)%MaxEl(*Q)+1;
			InfoTail(*Q)=X;
			address i=Tail(*Q);
			boolean swap=true;
			while(i!=Head(*Q)&&swap){
				int before;
				if(i-1==0){
					before=MaxEl(*Q);
				}else{
					before=i-1;
				}
				if(Prio(Elmt(*Q,i))>Prio(Elmt(*Q,before))){
					temp=Elmt(*Q,i);
					Elmt(*Q,i)=Elmt(*Q,before);
					Elmt(*Q,before)=temp;
				}else{
					swap=false;
				}
				i=before;

			}
			
		}
}
void Del (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{
		*X=InfoHead(*Q);
		if(NBElmt(*Q)==1){
			Head(*Q)=Nil;
			Tail(*Q)=Nil;
		}else{
			if(Head(*Q)!=MaxEl(*Q)){
				Head(*Q)++;
			}else{
				Head(*Q)=1;
			}
		}
}

/* Operasi Tambahan */
void PrintQueue (Queue Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
		infotype x;
		while(!IsEmpty(Q)){
			Del(&Q,&x);
			printf("%d %d\n",Prio(x),Info(x));
		}
		printf("#\n");
}

