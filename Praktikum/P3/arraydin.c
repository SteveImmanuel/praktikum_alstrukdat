/*	NIM					: 13517039
	Nama				: Steve Andreas I
	Tanggal				: 13 September 2018
	Topik praktikum		: Array
	Deskripsi			: MBody arraydin.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

void MakeEmpty(TabInt *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
{
	TI(*T) = (int*) malloc ((maxel+1) *sizeof(int));
	MaxEl(*T)=maxel;
  Neff(*T)=0;
}

void Dealokasi(TabInt *T)
/* I.S. T terdefinisi;
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
	MaxEl(*T)=0;
	Neff(*T)=0;
	free(TI(*T));
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
	return Neff(T);
}
/* *** Daya tampung container *** */
int MaxElement(TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	return MaxEl(T);
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
	return IdxMin;
}

IdxType GetLastIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
	return IdxMin+Neff(T)-1;
}
/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	return ((i>=GetFirstIdx(T)) && (i<=MaxEl(T)));
}
boolean IsIdxEff(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	return ((i>=GetFirstIdx(T)) && (i<=GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
	return (NbElmt(T)==0);
}
boolean IsFull(TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	return (NbElmt(T)==MaxEl(T));
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T)
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
  IdxType i;
  do{
    scanf("%d",&Neff(*T));
  }while(!((Neff(*T)>=0)&&(Neff(*T)<=MaxElement(*T))));
  if (Neff(*T)>0){
    for (i=IdxMin;i<=Neff(*T);i++){
      scanf("%d",&Elmt(*T,i));
    }
  }
}
void TulisIsiTab(TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
  IdxType i;
  if (IsEmpty(T)){
    printf("[]");
  }else{
    printf("[");
    for(i=GetFirstIdx(T);i<GetLastIdx(T);i++){
      printf("%d,",Elmt(T,i));
    }
    printf("%d]",Elmt(T,GetLastIdx(T)));
  }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
  IdxType i;
  TabInt temp;
  MakeEmpty(&temp,MaxEl(T1));
  for(i=GetFirstIdx(T1);i<=GetLastIdx(T1);i++){
    if (plus){
		Elmt(temp,i)=Elmt(T1,i)+Elmt(T2,i);
    }else{
		Elmt(temp,i)=Elmt(T1,i)-Elmt(T2,i);
    }
    Neff(temp)++;
  }
  return temp;
}





/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
  boolean equal=true;
  IdxType i;
  if(NbElmt(T1)!=NbElmt(T2)){
    equal=false;
  }else{
    i=GetFirstIdx(T1);
    while((i<=GetLastIdx(T1))&&(equal)){
      if(Elmt(T1,i)!=Elmt(T2,i)){
        equal=false;
      }else{
        i++;
      }
    }
  }
  return equal;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
  IdxType i=GetFirstIdx(T);
  if (IsEmpty(T)){
    return IdxUndef;
  }else{
    while((Elmt(T,i)!=X)&&(i<GetLastIdx(T))){
      i++;
    }
    if (Elmt(T,i)==X){
      return i;
    }else{
      return IdxUndef;
    }
  }
}

boolean SearchB(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
  IdxType i=GetFirstIdx(T);
  boolean found=false;
  if (IsEmpty(T)){
    return false;
  }else{
    while((i<=GetLastIdx(T))&&(!found)){
      if(Elmt(T,i)==X){
        found=true;
      }else{
        i++;
      }
    }
  }
  return found;
}

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
  IdxType i;
  *Max=Elmt(T,GetFirstIdx(T));
  *Min=Elmt(T,GetFirstIdx(T));
  for (i=GetFirstIdx(T)+1;i<=GetLastIdx(T);i++){
    if (Elmt(T,i)<*Min){
      *Min=Elmt(T,i);
    }
    if (Elmt(T,i)>*Max){
      *Max=Elmt(T,i);
    }
  }
}


/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
  IdxType i;
  MakeEmpty(Tout,MaxEl(Tin));
  if (!IsEmpty(Tin)){
    for(i=GetFirstIdx(Tin);i<=GetLastIdx(Tin);i++){
      Elmt(*Tout,i)=Elmt(Tin,i);
      Neff(*Tout)++;
    }
  }
}
ElType SumTab(TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
	ElType sum;
	IdxType i;
	sum=0;
	for (i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
		sum+=Elmt(T,i);
	}
	return sum;
}
int CountX(TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
	int banyak=0;
	while(Search1(T,X)!=IdxUndef){
		banyak++;
		Elmt(T,Search1(T,X))=IdxUndef;
	}
	return banyak;
}
boolean IsAllGenap(TabInt T)
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
{
	boolean genap=true;
	IdxType i;
	if (IsEmpty(T)){
		return false;
	}else{
		i=GetFirstIdx(T);
		while((i<=GetLastIdx(T))&&(genap)){
			if (Elmt(T,i)%2!=0){
				genap=false;
			}else{
				i++;
			}
		}
		return genap;
	}
}
/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
  IdxType i,pass,iex;
  ElType temp;
  if(NbElmt(*T)>1){
    for(pass=GetFirstIdx(*T);pass<GetLastIdx(*T);pass++){
      iex=pass;
      for(i=pass+1;i<=GetLastIdx(*T);i++){
        if (asc){
			if (Elmt(*T,iex)>Elmt(*T,i)){
				iex=i;
			}
		}else{
			if (Elmt(*T,iex)<Elmt(*T,i)){
				iex=i;
			}
		}
      }
      temp=Elmt(*T,iex);
      Elmt(*T,iex)=Elmt(*T,pass);
      Elmt(*T,pass)=temp;
    }
  }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
	Neff(*T)++;
	Elmt(*T,GetLastIdx(*T)) = X;
}
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
	*X=Elmt(*T,GetLastIdx(*T));
	Neff(*T)--;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num)
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
{
	MaxEl(*T)+=num;
	//TI(*T)=(ElType *) malloc ((MaxEl(*T)+1)* sizeof(ElType));
}


void ShrinkTab(TabInt *T, int num)
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
{
	MaxEl(*T)-=num;
	//TI(*T)=(ElType *) malloc ((MaxEl(*T)+1)* sizeof(ElType));
}

void CompactTab(TabInt *T)
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
{
	MaxEl(*T)=Neff(*T);
	//TI(*T)=(ElType *) malloc ((MaxEl(*T)+1)* sizeof(ElType));
}
