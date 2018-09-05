/* File : jam.c */

/*NIM				: 13517039
Nama				: Steve Andreas I
Tanggal				: 3 September 2018
Topik praktikum		: ADT
Deskripsi			: body ADT Jam*/

#include <stdio.h>
#include "jam.h"
boolean IsJAMValid (int H, int M, int S)
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
	return (((H>=0)&&(H<24))&&((M>=0)&&(M<60))&&((S>=0)&&(S<60)));
}
/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
	JAM J1;
	Hour(J1) = HH;
	Minute(J1) = MM;
	Second(J1) = SS;
	return J1;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J)
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */
{
	int H,M,S;
	do{
		printf("Masukan Jam : ");scanf("%d",&H);
		printf("Masukan Menit : ");scanf("%d",&M);
		printf("Masukan Detik : ");scanf("%d",&S);
	}while(!IsJAMValid(H,M,S));
	*J=MakeJAM(H,M,S);
}
   
void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 
{
	printf("%02d:%02d:%02d",Hour(J),Minute(J),Second(J));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
	return (Hour(J)*3600+Minute(J)*60+Second(J));
}
JAM DetikToJAM (long N)
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
{
	JAM J1;
	N%=86400;
	Hour(J1)=N/3600;
	Minute(J1)=(N%3600)/60;
	Second(J1)=(N%3600)%60;
	return J1;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
{
	return ((Hour(J1)==Hour(J2))&&(Minute(J1)==Minute(J2))&&(Second(J1)==Second(J2)));
}
boolean JNEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
{
	return !JEQ(J1,J2);
}
boolean JLT (JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2, false jika tidak */
{
	int secj1,secj2;
	secj1=JAMToDetik(J1);secj2=JAMToDetik(J2);
	return (secj1<secj2);
}
boolean JGT (JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
{
	int secj1,secj2;
	secj1=JAMToDetik(J1);secj2=JAMToDetik(J2);
	return (secj1>secj2);
}
/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
	int secjam=JAMToDetik(J);
	secjam+=1;
	return DetikToJAM(secjam);
}
JAM NextNDetik (JAM J, int N)
/* Mengirim N detik setelah J dalam bentuk JAM */
{
	int i;
	JAM temp=J;
	for(i=1;i<=N;i++){
		temp=NextDetik(J);
	}
	return temp;
}
JAM PrevDetik (JAM J)
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
{
	int secjam=JAMToDetik(J);
	if (secjam>0){
		secjam-=1;
	}else{
		secjam=86399;
	}	
	return DetikToJAM(secjam);
	
}
JAM PrevNDetik (JAM J, int N)
/* Mengirim N detik sebelum J dalam bentuk JAM */
/* *** Kelompok Operator Aritmetika *** */
{
	int i;
	JAM temp=J;
	for(i=1;i<=N;i++){
		temp=PrevDetik(J);
	}
	return temp;
}
long Durasi (JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
{
	int durasi=JAMToDetik(JAkh)-JAMToDetik(JAw);
	if (durasi>=0){
		return durasi;
	}else{
		return durasi+86400;
	}
}
