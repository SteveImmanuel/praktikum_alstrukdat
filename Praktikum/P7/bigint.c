/*  NIM		: 13517039
    Nama	: Steve Andreas Immanuel
    Tanggal	: 18/10/18
    Topik praktikum	: Stack
    Deskripsi 
    */

#include <stdio.h>
#include <string.h>
#include "stackt.h"
#include "boolean.h"

int main(){
	char s1[200],s2[200];
	Stack bil1,bil2,smin;
	int i,x,simpan,temp1,temp2,hasil;
	boolean lebihbesar;
	scanf("%s",s1);
	scanf("%s",s2);
	CreateEmpty(&bil1);
	CreateEmpty(&bil2);
	CreateEmpty(&smin);
	i=0;
	while(i<strlen(s1)){
		Push(&bil1,(int)(s1[i]-'0'));
		i++;
	}
	i=0;
	while(i<strlen(s2)){
		Push(&bil2,(int)(s2[i]-'0'));
		i++;
	}
	
	if(strlen(s1)>strlen(s2)){
		lebihbesar=true;
	}else if (strlen(s1)<strlen(s2)){
		lebihbesar=false;
	}else{
		i=0;
		lebihbesar=true;
		while(i<strlen(s1)&&lebihbesar){
			if((int)s1[i]<(int)s2[i]){
				lebihbesar=false;
			}else{
				i++;
			}
		}
	}
	
	
	
	
	//printf("%d %d %d\n",lebihbesar,Top(bil1),Top(bil2));
	simpan=0;
	
	while(!(IsEmpty(bil1)&&IsEmpty(bil2))){
		
		if(!IsEmpty(bil1)){
			Pop(&bil1,&temp1);
		}else{
			temp1=0;
		}
		if(!IsEmpty(bil2)){
			Pop(&bil2,&temp2);
		}else{
			temp2=0;
		}
		
		if(lebihbesar){
			if(simpan==1){
				//printf("simpan!=0\n");
				temp1--;
			}
			
			if(temp1>=temp2){
				hasil=temp1-temp2;
				simpan=0;
			}else{
				hasil=temp1-temp2+10;
				simpan=1;
			}
		}else{
			if(simpan==1){
				//printf("simpan!=0\n");
				temp2--;
			}
			
			if(temp2>=temp1){
				hasil=temp2-temp1;
				simpan=0;
			}else{
				hasil=temp2-temp1+10;
				simpan=1;
			}
		}
		
		
		//printf("temp1=%d temp2=%d hasil=%d simpan=%d\n",temp1,temp2,hasil,simpan);
		Push(&smin,hasil);
		
	}
	if(!lebihbesar){
		printf("-");
	}
	while(InfoTop(smin)==0){
		Pop(&smin,&x);
	}
	if(!IsEmpty(smin)){
		while(!IsEmpty(smin)){	
			Pop(&smin,&x);
			printf("%d",x);
		}
	}else{
		printf("0");
	}
	printf("\n");
	return 0;
}
