#include <stdio.h>
#include "listlinier.h"

int main(){
	List L,L1,L2;
	infotype x;
	address pt;
	int input,n,i;
	CreateEmpty(&L);

	while(1){
		printf("1. insertfirst\n2. insertlast\n3. delfirst\n4. dellast\n5. delp\n6. search\n7. nbelmt\n8. max\n9. concat\n");
		scanf("%d",&input);
		switch(input){
			case 1:
				scanf("%d",&x);
				InsVFirst(&L,x);
				break;
			case 2:
				scanf("%d",&x);
				InsVLast(&L,x);
				break;
			case 3:
				DelVFirst(&L,&x);
				printf("deleted:%d\n",x);
				break;
			case 4:
				DelVLast(&L,&x);
				printf("deleted:%d\n",x);
				break;
			case 5:
				scanf("%d",&x);
				DelP(&L,x);
				break;
			case 6:
				scanf("%d",&x);
				pt=Search(L,x);
				if(pt==Nil){
					printf("not found\n");
				}else{
					printf("found in %d with value %d\n",pt,Info(pt));
				}
				break;
			case 7:
				printf("number of element:%d\n",NbElmt(L));
				break;
			case 8:
				printf("max:%d\n",Max(L));
				break;
			case 9:
				CreateEmpty(&L1);
				CreateEmpty(&L2);
				printf("make the 1st list\ninsert noe:");scanf("%d",&n);
				i=0;
				while(i<n){
					scanf("%d",&x);
					InsVFirst(&L1,x);
					i++;
				}
				PrintInfo(L1);printf("\n");
				
				printf("make the 2nd list\ninsert noe:");scanf("%d",&n);
				i=0;
				while(i<n){
					scanf("%d",&x);
					InsVFirst(&L2,x);
					i++;
				}
				PrintInfo(L2);printf("\n");

				Konkat1(&L1,&L2,&L);
				printf("result:\n");
				printf("1st list:");PrintInfo(L1);printf("\n");
				printf("2nd list:");PrintInfo(L2);printf("\n");
				printf("concatenated:");
				break;

		}
		PrintInfo(L);
		printf("\n\n");
	}
	return 0;
}