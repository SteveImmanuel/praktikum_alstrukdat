#include <stdio.h>
#include "mesinkata.h"

int main(){
	int i;
	STARTKATA();
	IgnoreBlank();
	do{
		ADVKATA();
		for(i=1;i<=CKata.Length;i++){
			printf("%c",CKata.TabKata[i]);
		}
		printf("\ncc sekarang= %c\n",CC);
	}while(!EndKata);
	return 0;
}