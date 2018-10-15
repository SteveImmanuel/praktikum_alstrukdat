#include <stdio.h>
#include "mesintoken.h"

int main(){
	STARTTOKEN();
	if(EndToken){
		printf("Ekspresi kosong\n");
	}else{
		/*do{
			if(CToken.tkn=='b'){
				printf("%d\n",CToken.val);
			}else{
				printf("%c\n",CToken.tkn);
			}
			ADVTOKEN();
		}while(!EndToken);*/
		while (!EndToken) {
			if (CToken.tkn != 'b')
				printf("%c\n", CToken.tkn);
			else
				printf("%d\n", CToken.val);
			ADVTOKEN();
		}

	}
	return 0;
}
