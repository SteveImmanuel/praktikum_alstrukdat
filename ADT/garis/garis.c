/* File : garis.c */
/* Definisi type garis */

#include "garis.h"
#include <math.h>

void MakeGARIS(POINT P1,POINT P2,GARIS *L){
	PAw(*L)=P1;
	PAkh(*L)=P2;
}
void BacaGARIS (GARIS *L){
	POINT PAw,PAkh;
	do{
		BacaPOINT(&PAw);
		BacaPOINT(&PAkh);
	}while(NEQ(PAw,PAkh));
	MakeGARIS(PAw,PAkh,L);
}  
void TulisGARIS (GARIS L){
	printf("((%f,%f), (%f,%f))",Absis(PAw(L)),Ordinat(PAw(L)),Absis(PAkh(L)),Ordinat(PAkh(L)));
} 
boolean EQ (GARIS L1,GARIS L2){
	return (EQ(PAw(L1),PAw(L2))&&EQ(PAkh(L1),PAkh(L2)));
}
boolean NEQ (GARIS L1,GARIS L2){
	return !EQ(L1,L2);
}
boolean IsOnSbX (GARIS L1){
	return (IsOnSbX(PAw(L1))&&IsOnSbX(PAkh(L1)));
}
boolean IsOnSbY (GARIS L1){
	return (IsOnSbY(PAw(L1))&&IsOnSbY(PAkh(L1)));
}
int Kuadran (GARIS L1){
	if ((Kuadran(PAw(L1))==1)&&(Kuadran(PAkh(L1))==1)){
		return 1;
	}else if ((Kuadran(PAw(L1))==2)&&(Kuadran(PAkh(L1))==2)){
		return 2;
	}else if ((Kuadran(PAw(L1))==3)&&(Kuadran(PAkh(L1))==3)){
		return 3;
	}else if ((Kuadran(PAw(L1))==4)&&(Kuadran(PAkh(L1))==4)){
		return 4;
	}
}
boolean IsTegakLurus (GARIS L,GARIS L1){
	float m1,m2;
	m1=(Ordinat(PAkh(L))-Ordinat(PAw(L)))/(Absis(PAkh(L))-Absis(PAw(L)));
	m2=(Ordinat(PAkh(L1))-Ordinat(PAw(L1)))/(Absis(PAkh(L1))-Absis(PAw(L1)));
	return (m1*m2==-1);
}
boolean IsSejajar (GARIS L,GARIS L1){
	float m1,m2;
	m1=(Ordinat(PAkh(L))-Ordinat(PAw(L)))/(Absis(PAkh(L))-Absis(PAw(L)));
	m2=(Ordinat(PAkh(L1))-Ordinat(PAw(L1)))/(Absis(PAkh(L1))-Absis(PAw(L1)));
	return (m1==m2);
}
GARIS HslGeser (GARIS L,float DX,float DY){
	Geser(&PAw(L),DX,DY);
	Geser(&PAkh(L),DX,DY);
	return L;
} 
GARIS MirrorOf (GARIS L,boolean SbX){
	Mirror(&PAw(L),SbX);
	Mirror(&PAkh(L),SbX);
	return L;
} 
float Panjang (GARIS L){
	return Panjang(PAw(L),PAkh(L));
}
float Arah (GARIS L){
	float m;
	m=(Ordinat(PAkh(L))-Ordinat(PAw(L)))/(Absis(PAkh(L))-Absis(PAw(L)));
	return atan(m);
}
float SudutGaris (GARIS L,GARIS L1){
	float m1,m2;
	m1=(Ordinat(PAkh(L))-Ordinat(PAw(L)))/(Absis(PAkh(L))-Absis(PAw(L)));
	m2=(Ordinat(PAkh(L1))-Ordinat(PAw(L1)))/(Absis(PAkh(L1))-Absis(PAw(L1)));
	return atan((m1-m2)/(1+m1*m2));
}
void Geser (GARIS *L, float deltaX, float deltaY){
	*L=HslGeser(*L,deltaX,deltaY);
}
void Mirror (GARIS *L, boolean SbX,boolean SbY){
	if (SbX==true){
		*L=MirrorOf(*L,SbX);
	}
	if (SbY==true){
		*L=MirrorOf(*L,false);
	}
} 
void Putar (GARIS *L, float sudut){
	Absis(PAkh(*L))=((Absis(PAkh(*L))-Absis(PAw(*L)))*cos(Sudut)-(Ordinat(PAkh(*L))-Ordinat(PAw(*L)))*sin(Sudut))+Absis(PAw(*L));
	Ordinat(PAkh(*L))=((Absis(PAkh(*L))Absis(PAw(*L)))*sin(Sudut)+(Ordinat(PAkh(*L))-Ordinat(PAw(*L)))*cos(Sudut))+Ordinat(PAw(*L));
} 