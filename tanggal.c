/* File : tanggal.c */
/* body ADT tanggal */
#include "tanggal.h"


boolean IsTanggalValid (int D,int M, int Y){
	if (IsKabisat(Y)){
		if (M==2){
			if((D>0)&&(D<=29)) return true; else return false;
		}else if ((M==1)||(M==3)||(M==5)||(M==7)||(M==8)||(M==10)||(M==12)){
			if ((D>0)&&(D<=31)) return true; else return false;
		}else{
			if ((D>0)&&(D<=30)) return true; else return false;	
		}
	}else{
		if (M==2){
			if((D>0)&&(D<=28)) return true; else return false;
		}else if ((M==1)||(M==3)||(M==5)||(M==7)||(M==8)||(M==10)||(M==12)){
			if ((D>0)&&(D<=31)) return true; else return false;
		}else{
			if ((D>0)&&(D<=30)) return true; else return false;	
		}
	}
}
TANGGAL MakeTANGGAL(int h,int b,int t){
	TANGGAL T;
	Day(T)=h;
	Month(T)=b;
	Year(T)=t;
	return T;
}
void BacaTANGGAL(TANGGAL *T){
	int h,b,t;
	do{
		printf("Masukkan Hari : ");scanf("%d",&h);
		printf("Masukkan Bulan : ");scanf("%d",&b);
		printf("Masukkan Tahun : ");scanf("%d",&t);
	}while(!IsTanggalValid(h,b,t));
	*T=MakeTANGGAL(h,b,t);
}
void TulisTANGGAL(TANGGAL T){
	printf("%d/%d/%d",Day(T),Month(T),Year(T));
}
TANGGAL NextDay(TANGGAL D){
	if ((Day(D)==31) && (Month(D)==12)){		
		Day(D)=1;
		Month(D)=1;
		Year(D)+=1;
	}else if (((Day(D)==31) && ((Month(D)==1)||(Month(D)==3)||(Month(D)==5)||(Month(D)==7)||(Month(D)==8)||(Month(D)==10)))
		  || ((Day(D)==30) && ((Month(D)==4)||(Month(D)==6)||(Month(D)==9)||(Month(D)==11)))
		  || (IsKabisat(Year(D)) && (Month(D)==2) && (Day(D)==29))
	      || ((!IsKabisat(Year(D))) && (Month(D)==2) && (Day(D)==28))) {
		Day(D)=1;
		Month(D)+=1;		
	}else{
		Day(D)+=1;
	}
	return D;
}
TANGGAL PrevDay(TANGGAL D){
	if ((Day(D)==1) && (Month(D)==1)){		
		Day(D)=31;
		Month(D)=12;
		Year(D)-=1;
	}else if (Day(D)==1){
		if ((Month(D)==12)||(Month(D)==5)||(Month(D)==7)||(Month(D)==8)||(Month(D)==10)){
			Day(D)=30;
			Month(D)-=1;
		}else if ((Month(D)==2)||(Month(D)==4)||(Month(D)==6)||(Month(D)==9)||(Month(D)==11)){
			Day(D)=31;
			Month(D)-=1;
		}else if (Month(D)==3){
			if (IsKabisat(Year(D))){
				Day(D)=29;
				Month(D)-=1;
			}else{
				Day(D)=28;
				Month(D)-=1;
			}
		}
	}else{
		Day(D)-=1;
	}
	return D;
}




TANGGAL NextNDay(TANGGAL D,int N){
	int i;TANGGAL temp;
	temp=D;
	for (i=1;i<=N;i++){
		temp=NextDay(temp);
	}
	return temp;
}
TANGGAL PrevNDay(TANGGAL D, int N){
	int i;TANGGAL temp;
	temp=D;
	for (i=1;i<=N;i++){
		temp=PrevDay(temp);
	}
	return temp;
}
int HariKe(TANGGAL D){
	int i,harike;
	int blntk[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int blnk[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	harike=0;
	if (IsKabisat(Year(D))){
		for(i=1;i<=(Month(D)-1);i++){
			harike+=blnk[i];
		}
		harike+=Day(D);
	}else{
		for(i=1;i<=(Month(D)-1);i++){
			harike+=blntk[i];
		}
		harike+=Day(D);
	}
	return harike;
	
}
boolean IsEqual(TANGGAL D1,TANGGAL D2){
	return ((Day(D1)==Day(D2))&&(Month(D1)==Month(D2))&&(Year(D1)==Year(D2)));
}
boolean IsBefore(TANGGAL D1,TANGGAL D2){
	return IsEqual(PrevDay(D1),D2);
}
boolean IsAfter(TANGGAL D1,TANGGAL D2){
	return IsEqual(NextDay(D1),D2);
}
boolean IsKabisat(int Y){
	return (((Y%4==0)||(Y%400==0))&&(Y%100!=0));
}	