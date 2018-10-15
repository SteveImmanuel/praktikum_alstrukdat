/* File : garis.h */
/* Header type garis */

#ifndef garis_H
#define garis_H
#include "boolean.h"
#include "point.c"

typedef struct {
	POINT PAw,PAkh;
}GARIS;

#define PAw(G) (G).PAw
#define PAkh(G) (G).PAkh

void MakeGARIS(POINT P1,POINT P2,GARIS *L);
//I.S. P1 dan P2 terdefinisi  
//F.S. L terdefinisi dengan L.PAw= P1 dan L.Pakh=P2  
//Membentuk sebuah L dari komponen-komponennya  
void BacaGARIS (GARIS *L);
// I.S. sembarang  
// F.S. L terdefinisi sebagai GARIS yang valid  
// Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat membentuk 
//GARIS yang valid. GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya.  
void TulisGARIS (GARIS L); 
// I.S. L terdefinisi  
// F.S. L tertulis di layar dengan format ((x,y), (x,y))  
boolean EQ (GARIS L1,GARIS L2);
//Mengirimkan true jika L1  = L2 
//L1  dikatakan sama dengan L2 jika titik awal dari L1 sama dengan titik awal dari 
//L2 dan titik akhir L1 sama titik akhir dari L2. 
boolean NEQ (GARIS L1,GARIS L2);
//Mengirimkan true jika L tidak sama dengan L : Negasi dari fungsi
boolean IsOnSbX (GARIS L1);
//Menghasilkan true jika L  terletak pada sumbu X 
boolean IsOnSbY (GARIS L1);
//Menghasilkan true jika L terletak pada sumbu Y 
int Kuadran (GARIS L1);
//Menghasilkan kuadran dari L (di mana PAw dan PAkh berada) 
//Prekondisi : L  tidak terletak di salah satu sumbu, dan 
//PAw serta PAkh selalu terletak a kuadran yang sama 
boolean IsTegakLurus (GARIS L,GARIS L1);
//Menghasilkan true jika L tegak lurus terhadap L1
boolean IsSejajar (GARIS L,GARIS L1);
//Menghasilkan true jika L "sejajar" terhadap L1
GARIS HslGeser (GARIS L,float DX,float DY); 
//Menghasilkan salinan L yang titik awal dan titik akhirnya digeser sejauh DX dan DY 
GARIS MirrorOf (GARIS L,boolean SbX); 
//Menghasilkan salinan L  yang tergantung nilai SbX dan SbY 
//Jika SbX bernilai true, maka dicerminkan terhadap sumbu X 
//Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y 
float Panjang (GARIS L);
//Menghitung panjang garis L : berikan rumusnya 
float Arah (GARIS L);
//Menghitung arah dari garis L yaitu sudut yang dibentuk dengan sumbu X positif 
float SudutGaris (GARIS L,GARIS L1);
//Menghasilkan sudut perpotongan antara L  dengan L1 
//Prekondisi : L tidak sejajar dengan L1 dan 
//             L tidak berimpit dengan L1 
void Geser (GARIS *L, float deltaX, float deltaY);
//I.S. L terdefinisi 
//F.S. L digeser sebesar deltaX dan ordinatnya sebesar deltaY 
//Proses : PAw dan PAkh digeser! 
void Mirror (GARIS *L, boolean SbX,boolean SbY); 
//I.S. L terdefinisi 
//F.S. L dicerminkan tergantung nilai SbX atau SbY 
//Jika SbX true maka dicerminkan terhadap sumbu X 
//Jika SbY true maka dicerminkan terhadap sumbu Y 
void Putar (GARIS *L, float sudut); 
//I.S. L terdefinisi 
//F.S. L diputar sebesar Sudut derajat : PAw tetap dan PAkh berubah 




#endif