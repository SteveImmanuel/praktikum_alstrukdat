/* File : array.c */

/*NIM            : 13517039
Nama             : Steve Andreas I
Tanggal          : 3 September 2018
Topik praktikum  : ADT
Deskripsi        : Body ADT array*/

/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit, 
   memori tabel statik */

#include <stdio.h>
#include <array.h>

/*  Kamus Umum */
#define IdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999 
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef int ElType;   /* type elemen tabel */
typedef struct { 
  ElType TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
  int Neff; /* >=0, banyaknya elemen efektif */
} TabInt;
/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses: 
   T.Neff  untuk mengetahui banyaknya elemen 
   T.TI    untuk mengakses seluruh nilai elemen tabel 
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi : 
  Tabel kosong: T.Neff = 0
  Definisi elemen pertama : T.TI[i] dengan i=1 
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */
  
/* ********** SELEKTOR ********** */
#define Neff(T)   (T).Neff
#define TI(T)     (T).TI
#define Elmt(T,i) (T).TI[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
  Neff(*T)=0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
  return Neff(T);
}
int MaxNbEl (TabInt T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
  return IdxMax;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
  int i=1;boolean found=false;
  while((i<=IdxMax)&&(!found)){
    if (Elmt(T,i)!=""){
      found=true;
    }else{
      i++;
    }
  }
  return i;
}
IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
  return GetFirstIdx(T)+Neff(T)-1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return ((i>=IdxMin) && (i<=IdxMax));
}
boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
  return ((i>=GetFirstIdx(T)) && (i<=GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
  return (Neff(T)==0);
}
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
  return (Neff(T)==MaxNbEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
  IdxType i;
  do{
    scanf("%d",&Neff(*T));
  }while(!((N>=0)&&(N<=MaxNbEl(*T))));
  if (Neff(*T)>0){
    for (i=IdxMin;i<=Neff(*T);i++){
      scanf("%d",&Elmt(*T,i));
    }
  }
}
void BacaIsiTab (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
  IdxType i=IdxMin;
  ElType x;
  do{
    scanf("%d",&x);
    if(x!=-9999){
      Elmt(*T,i)=x;
      i++;
    }
  }while((i<=IdxMax)&&(x!=-9999));
  Neff(*T)=i-1;

}
void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
{
  IdxType i;
  if (IsEmpty(T)){
    printf("Tabel kosong");
  }else{
    for (i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
      printf("[%d]%d\n",i,Elmt(T,i));
    }
  }
}
void TulisIsiTab (TabInt T)
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
TabInt PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
{
  IdxType i;
  TabInt temp;
  MakeEmpty(&temp);
  for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
    Elmt(temp,i)=Elmt(T1,i)+Elmt(T2,i);
    Neff(temp)++;
  }
  return temp;
}
TabInt MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
  IdxType i;
  TabInt temp;
  MakeEmpty(&temp);
  for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
    Elmt(temp,i)=Elmt(T1,i)-Elmt(T2,i);
    Neff(temp)++;
  }
  return temp;
}
TabInt KaliTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
{
  IdxType i;
  TabInt temp;
  MakeEmpty(&temp);
  for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
    Elmt(temp,i)=Elmt(T1,i)*Elmt(T2,i);
    Neff(temp)++;
  }
  return temp;
}
TabInt KaliKons (TabInt Tin, ElType c)
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
{
  IdxType i;
  TabInt temp;
  MakeEmpty(&temp);
  for(i=GetFirstIdx(Tin);i<=GetLastIdx(Tin);i++){
    Elmt(temp,i)=Elmt(Tin,i)*c;
    Neff(temp)++;
  }
  return temp;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
  boolean equal=true;
  IdxType i;
  if(NbElmt(T1)!=NbElmt(T2)){
    equal=false;
  }else{
    if(GetFirstIdx(T1)!=GetFirstIdx(T2)){
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
  }
  return equal;
}
boolean IsLess (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
{
  IdxType i;
  boolean less=true;
  if (NbElmt(T1)!=NbElmt(T2)){
    less=false;
  }else{
    if(GetFirstIdx(T1)!=GetFirstIdx(T2)){
      less=false;
    }else{
      i=GetFirstIdx(T1);
      while((i<=GetLastIdx(T1)&&(less)){
        if(Elmt(T1,i)>=Elmt(T2,i)){
          less=false;
        }else{
          i++;
        }
      }
    }
  }
  return less;
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
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
IdxType Search2 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
  IdxType i=GetFirstIdx(T);
  boolean found=false;
  if (IsEmpty(T)){
    return IdxUndef;
  }else{
    while(i<=GetLastIdx(T))&&(!found){
      if(Elmt(T,i)==X){
        found=true;
      }else{
        i++;
      }
    }
  }
  if (found){
    return i;
  }else{
    return IdxUndef;
  }
}
boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
{
  IdxType i=GetFirstIdx(T);
  boolean found=false;
  if (IsEmpty(T)){
    return false;
  }else{
    while(i<=GetLastIdx(T))&&(!found){
      if(Elmt(T,i)==X){
        found=true;
      }else{
        i++;
      }
    }
  }
  return found;
}
boolean SearchSentinel (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C 
   yang tidak dipakai dalam definisi tabel */
{
  IdxType i=GetLastIdx(T);
  if (IsEmpty(T)){
    return false;
  }else{
    Elmt(T,0)=X;
    while(Elmt(T,i)!=X){
      i--;
    }
    if (i==0){
      return false;
    }else{
      return true;
    }
  }
}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
  IdxType i;
  Eltype x;
  x=Elmt(T,GetFirstIdx(T));
  for (i=GetFirstIdx(T)+1;i<=GetLastIdx(i);i++){
    if (Elmt(T,i)>x){
      x=Elmt(T,i);
    }
  }
  return x;
}
ElType ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
{
  IdxType i;
  Eltype x;
  x=Elmt(T,GetFirstIdx(T));
  for (i=GetFirstIdx(T)+1;i<=GetLastIdx(i);i++){
    if (Elmt(T,i)<x){
      x=Elmt(T,i);
    }
  }
  return x;
}
IdxType IdxMaxTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
{
  IdxType i,idxex=GetFirstIdx(T);
  for (i=GetFirstIdx(T)+1;i<=GetLastIdx(i);i++){
    if (Elmt(T,i)>Emlt(T,idxex)){
      idxex=i;
    }
  }
  return i;
}
IdxType IdxMinTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
{
  IdxType i,idxex=GetFirstIdx(T);
  for (i=GetFirstIdx(T)+1;i<=GetLastIdx(i);i++){
    if (Elmt(T,i)<Elmt(T,idxex)){
      idxex=i;
    }
  }
  return i;
}
/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
  IdxType i;
  MakeEmpty(Tout);
  if (!IsEmpty(Tin)){
    for(i=GetFirstIdx(Tin);i<=GetLastIdx(Tin);i++){
      Elmt(*Tout,i)=Elmt(Tin,i);
      Neff(Tout)++;
    }
  }
}
TabInt InverseTab (TabInt T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
  IdxType i;
  TabInt temp;
  MakeEmpty(temp);
  if (!IsEmpty(T)){
    for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
      Elmt(temp,i)=Elmt(T,GetLastIdx(T)-i+1);
      Neff(T)++;
    }
  }
  return temp;
}
boolean IsSimetris (TabInt T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
  return (IsEQ(T,InverseTab(T)));
}

/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
{
  IdxType i,pass,imax;
  ElType temp;
  if(Neff(*T)>1){
    for(pass=GetFirstIdx(*T);pass<GetLastIdx(*T);pass++){
      imax=pass;
      for(i=pass+1;i<=GetLastIdx(*T);i++){
        if (Elmt(*T,imax)<Elmt(*T,i)){
          imax=i;
        }
      }
      temp=Emlt(*T,imax);
      Elmt(*T,imax)=Elmt(*T,pass);
      Elmt(*T,pass)=temp;
    }
  }
}
void InsSortAsc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */
{
  IdxType i,pass;
  ElType temp;
  if(Neff(*T)>1){
    for(pass=GetFirstIdx(*T)+1;pass<=GetLastIdx(*T);pass++){
      temp=Elmt(*T,pass);
      i=pass-1;
      while((Elmt(*T,i)>temp)&&(i>GetFirstIdx(*T))){
        Elmt(*T,i+1)=Elmt(*T,i);
        i--;
      }
      if(temp>=Elmt(*T,i)){
        Elmt(*T,i+1)=temp;
      }else{
        Elmt(*T,i+1)=Elmt(*T,i);
        Elmt(*T,i)=temp;
      }
    }
  }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
  if(IsEmpty(*T)){
    Neff(*T)++;
    Elmt(*T,IdxMin)=X;
  }else if(!IsFull(*T)){
    Neff(*T)++;
    Elmt(*T,GetLastIdx(*T))=X;
  }
}
void AddEli (TabInt * T, ElType X, IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
  IdxType j=GetLastIdx(*T);
  if(!IsEmpty(*T))&&(!IsFull(*T))&&(IsIdxValid(i))){
    while(j>=i){
      Elmt(*T,j+1)=Elmt(*T,j);
      j--;
    }
    Elmt(*T,i)=X;
    Neff(*T)++;
  }
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X);
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
  if(!IsEmpty(*T)){
    *X=Elmt(*T,GetLastIdx(*T));
    Elmt(*T,GetLastIdx(*T))="";
    Neff(*T)--;
  }
}
void DelEli (TabInt * T, IdxType i, ElType * X);
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
  if(!IsEmpty(*T))&&IsIdxEff(i)){
    *X=Elmt(*T,i);
    for(;i<GetLastIdx(*T);i++){
      Elmt(*T,i)=Elmt(*T,i+1);
    }
    Neff(*T)--;
  }
}

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X);
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T, 
        jika belum ada elemen yang bernilai X. 
    Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S. 
    dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{
  if(!IsFull(*T)){
    if(IsEmpty(*T)){
      Neff(*T)++;
      Elmt(*T,IdxMin)=X;
    }else{
      if(!SearchSentinel(*T,X)){
        Neff(*T)++;
        Elmt(*T,GetLastIdx(*T))=X;
      }else{
        printf("nilai sudah ada");
      }
    }
  }
}

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X)
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
{
  return Search2(T,X);
}
ElType MaxUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
{
  return Elmt(T,GetLastIdx(T));
}
ElType MinUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
{
  return Elmt(T,GetFirstIdx(T));
}
void MaxMinUrut (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
  *Max=MaxUrut(T);
  *Min=MinUrut(T);
}
void Add1Urut (TabInt * T, ElType X)
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
{
  ElType temp;
  IdxType i;
  if(IsEmpty(*T)){
    Neff(*T)++;
    AddEli(T,X,IdxMin);
  }else if(!IsFull(*T)){
    i=GetLastIdx(*T);
    Elmt(*T,GetLastIdx(*T)+1)=X;
    while((Elmt(*T,i)>X)&&i>GetFirstIdx(*T)){
      Elmt(*T,i+1)=Elmt(*T,i);
      i--;
    }
    i++;
    Elmt(*T,i)=X;
    Neff(*T)++;
  }
  
  /*IdxType i=GetFirstIdx(*T);
  if(IsEmpty(*T)){
    Neff(*T)++;
    AddEli(T,X,IdxMin);
  }else if(!IsFull(*T)){
    while(i<)
  }*/
}
void Del1Urut (TabInt * T, ElType X);
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
{
  IdxType i=Search2(*T,X);
  ElType temp;
  if(!IsEmpty(*T)){
    DelEli(T,i,temp);
  }
}

