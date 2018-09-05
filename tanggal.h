#/* File : tanggal.h */
/* header ADT tanggal */
#ifndef tanggal_H
#define tanggal_H
#include "boolean.h"

typedef struct{
	int DD,MM,YY;
}TANGGAL;

#define Day(T) (T).DD
#define Month(T) (T).MM
#define Year(T) (T).YY


boolean IsTanggalValid (int D,int M, int Y);
TANGGAL MakeTANGGAL(int h,int b,int t);
void BacaTANGGAL(TANGGAL*T);
void TulisTANGGAL(TANGGAL T);
TANGGAL NextDay(TANGGAL D);
TANGGAL PrevDay(TANGGAL D);
TANGGAL NextNDay(TANGGAL D,int N);
TANGGAL PrevNDay(TANGGAL D,int N);
int HariKe(TANGGAL D);
boolean IsEqual(TANGGAL D1,TANGGAL D2);
boolean IsBefore(TANGGAL D1,TANGGAL D2);
boolean IsAfter(TANGGAL D1,TANGGAL D2);
boolean IsKabisat(int Y);
#endif