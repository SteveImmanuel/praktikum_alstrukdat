/* File : array.c */

/*NIM            : 13517039
Nama             : Steve Andreas I
Tanggal          : 15 September 2018
Topik praktikum  : ADT
Deskripsi        : Body ADT array*/

#include <stdio.h>
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M) 
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	NBrsEff(*M)=NB;
	NKolEff(*M)=NK;
}
/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
	return (i>=BrsMin && i<=BrsMax && j>=KolMin && j<= KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
	return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
	return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
	return GetFirstIdxBrs(M)+NBrsEff(M)-1;
}
indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
	return GetFirstIdxKol(M)+NKolEff(M)-1;
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	return (i>=GetFirstIdxBrs(M)&&i<=GetLastIdxBrs(M)&&j>=GetFirstIdxKol(M)&&j<=GetLastIdxKol(M));
}
ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
	return Elmt(M,i,i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
	indeks i=GetFirstIdxBrs(MIn);
	indeks j=GetFirstIdxKol(MIn);
	MakeMATRIKS(NBrsEff(MIn),NKolEff(MIn),MHsl);
	for(i;i<=GetLastIdxBrs(MIn);i++){
		for(j;j<=GetLastIdxKol(MIn);j++){
			Elmt(*MHsl,i,j)=Elmt(MIn,i,j);
		}
	}
}
/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
	indeks i=GetFirstIdxBrs(*M);
	indeks j;
	MakeMATRIKS(NB,NK,M);
	for(i;i<=GetLastIdxBrs(*M);i++){
		for(j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
			scanf("%d",&Elmt(*M,i,j));
		}
	}
}
void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
	indeks i=GetFirstIdxBrs(M);
	indeks j;
	for(i;i<=GetLastIdxBrs(M);i++){
		for(j=GetFirstIdxKol(M);j<GetLastIdxKol(M);j++){
			printf("%d ",Elmt(M,i,j));
		}
		printf("%d\n",Elmt(M,i,j));
	}
}
/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
	indeks i=GetFirstIdxBrs(M1);
	indeks j;
	MATRIKS temp;
	MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&temp);
	for(i;i<=GetLastIdxBrs(M1);i++){
		for(j=GetFirstIdxKol(M1);j<=GetLastIdxKol(M1);j++){
			Elmt(temp,i,j)=Elmt(M1,i,j)+Elmt(M2,i,j);
		}
	}
	return temp;
} 
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
{
	indeks i=GetFirstIdxBrs(M1);
	indeks j;
	MATRIKS temp;
	MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&temp);
	for(i;i<=GetLastIdxBrs(M1);i++){
		for(j=GetFirstIdxKol(M1);j<=GetLastIdxKol(M1);j++){
			Elmt(temp,i,j)=Elmt(M1,i,j)-Elmt(M2,i,j);
		}
	}
	return temp;
} 
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
	indeks i=GetFirstIdxBrs(M1);
	indeks j;
	indeks k;
	MATRIKS temp;
	MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&temp);
	for(i;i<=GetLastIdxBrs(M1);i++){
		for(j=GetFirstIdxKol(M2);j<=GetLastIdxKol(M2);j++){
			Elmt(temp,i,j)=0;
			for(k=GetFirstIdxBrs(M2);k<=GetLastIdxBrs(M2);k++){
				Elmt(temp,i,j)+=Elmt(M1,i,k)*Elmt(M2,k,j);
			}
		}
	}
	return temp;
}
MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
	indeks i=GetFirstIdxBrs(M);
	indeks j;
	MATRIKS temp;
	MakeMATRIKS(NBrsEff(M),NKolEff(M),&temp);
	for(i;i<=GetLastIdxBrs(M);i++){
		for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
			Elmt(temp,i,j)=Elmt(M,i,j)*X;
		}
	}
	return temp;
} 
void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
	indeks i=GetFirstIdxBrs(*M);
	indeks j;
	for(i;i<=GetLastIdxBrs(*M);i++){
		for(j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
			Elmt(*M,i,j)*=K;
		}
	}
} 
/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
	indeks i,j;
	boolean sama;
	if(NBrsEff(M1)==NBrsEff(M2)&&NKolEff(M1)==NKolEff(M2)){
		sama=true;
		i=GetFirstIdxBrs(M1);
		while(i<=GetLastIdxBrs(M1)&&sama){
			j=GetFirstIdxKol(M1);
			while(j<=GetLastIdxKol(M1)&&sama){
				if (Elmt(M1,i,j)!=Elmt(M2,i,j)){
					sama=false;
				}else{
					j++;
				}
			}
			if (sama){
				i++;
			}
		}
		return sama;
	}else{
		return false;
	}
}
boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
	return !EQ(M1,M2);
}
boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
	return NBrsEff(M1)==NBrsEff(M2)&&NKolEff(M1)==NKolEff(M2);
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
	return NBrsEff(M)*NKolEff(M);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
	return NBrsEff(M)==NKolEff(M);
}
boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
	MATRIKS temp;
	CopyMATRIKS(M,&temp);
	Transpose(&temp);
	return EQ(M,temp);
}
boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
{
	boolean sat;
	indeks i,j;
	if (IsBujurSangkar(M)){
		sat=true;
		i=GetFirstIdxBrs(M);
		while(i<=GetLastIdxBrs(M)&&sat){
			j=GetFirstIdxKol(M);
			while(j<=GetLastIdxKol(M)&&sat){
				if (i==j){
					if(GetElmtDiagonal(M,i)!=1){
						sat=false;
					}else{
						j++;
					}
				}else{
					if(Elmt(M,i,j)!=0){
						sat=false;
					}else{
						j++;
					}
				}
			} 
			if (sat){
				i++;
			}
		}
		return sat;
	}else{
		return false;
	}
}
boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
{
	float sparse=NBElmt(M)/20,temp;
	indeks i,j;
	boolean sp=true;
	i=GetFirstIdxBrs(M);
	temp=0;
	while(i<=GetLastIdxBrs(M)&&sp){
		j=GetFirstIdxKol(M);
		while(j<=GetLastIdxKol(M)&&sp){
			if (Elmt(M,i,j)!=0){
				temp+=1;
			}
			if (temp<=sparse){
				j++;
			}else{
				sp=false;
			}
		}
		if (sp){
			i++;
		}
	}
	return sp;

}
MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
	return KaliKons(M,-1);
}
float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
	float temp[BrsMax+1][KolMax+1],det,kons;
	indeks i,j,k;
	for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
		for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
			temp[i][j]=Elmt(M,i,j);
		}
	}
	for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
        for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
            if(j>i){
                kons=((float)Elmt(M,j,i)/(float)Elmt(M,i,i));
                for(k=GetFirstIdxBrs(M);k<=GetLastIdxBrs(M);k++){
                    temp[j][k]-=kons*temp[i][k];
                }
            }
        }
    }


	for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
		for(j=GetFirstIdxKol(M);j<GetLastIdxKol(M);j++){
			printf("%.2f ",temp[i][j]);
		}
		printf("%.2f\n",temp[i][j]);
	}

    det=1;
    for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
        det*=temp[i][i];
    }
    return det;
}
void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
	return PKaliKons(M,-1);
}
void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
	ElType temp;
	indeks i=GetFirstIdxBrs(*M),j;
	for(i;i<GetLastIdxBrs(*M);i++){
		for(j=i+1;j<=GetLastIdxKol(*M);j++){
			temp=Elmt(*M,i,j);
			Elmt(*M,i,j)=Elmt(*M,j,i);
			Elmt(*M,j,i)=temp;
		}
	}
}

