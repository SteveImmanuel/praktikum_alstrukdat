/*   NIM	: 13517039
    Nama	: Steve Andreas I
    Tanggal	: 27 September 2018
    Topik praktikum	: Mesin
    Deskripsi	
    */
 
#include <stdio.h>
#include "mesinkata.h"

void copyKata(Kata *hasil, Kata sumber) {
	int i;
	for (i=1;i<=sumber.Length;i++) {
		(*hasil).TabKata[i] = sumber.TabKata[i];
	}
	(*hasil).Length = sumber.Length;
}

void printkata(Kata kata){
	int i;
	for(i=1;i<=kata.Length;i++){
		printf("%c",kata.TabKata[i]);
	}
}

void geserkata(Kata *kata,int geser){
	int i,temp;
	for(i=1;i<=(*kata).Length;i++){
		//printf("charawal=%d ",(int)(*kata).TabKata[i]);
		(*kata).TabKata[i]=((geser+(int)(*kata).TabKata[i]-64)%26);
		if((*kata).TabKata[i]==0){
			(*kata).TabKata[i]=(char)26;
		}
		(*kata).TabKata[i]=(char)((int)(*kata).TabKata[i]+64);
		//printf("charakhir=%d\n",(int)(*kata).TabKata[i]);
	}
}

int main(){
	int geser,i=0;
	Kata temp[100];
	STARTKATA();
	while(!EndKata){
		i++;
		copyKata(&temp[i],CKata);
		ADVKATA();
	}
	geser=temp[1].Length;
	int j;
	for(j=1;j<=i;j++){
		geserkata(&temp[j],geser);
	}
	for(j=1;j<i;j++){
		printkata(temp[j]);
		printf(" ");	
	}
	printkata(temp[j]);
	printf(".\n");


	/*geser=CKata.Length;

	//printf("GESER=%d\n",geser);

	IgnoreBlank();
	geserkata(&CKata,geser);
	printkata(CKata);
	while(!EndKata){
		printf(" ");
		ADVKATA();
		geserkata(&CKata,geser);
		printkata(CKata);
	}
	printf(".\n");*/
	return 0;
}
