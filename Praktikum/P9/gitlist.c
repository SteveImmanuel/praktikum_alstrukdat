//NIM/Nama		: 13517039/Steve Andreas I
//Nama File		: 
//Topik			: list
//Tanggal		: 1 November 2018
//Deskripsi		:

#include <stdio.h>
#include "listdp.h"

int main(){
	List L;
	address head=Nil,temphead=Nil;
	CreateEmpty(&L);
	char input;
	int n,i;
	boolean stop;
	infotype hash=0;
	do{
		scanf("%c",&input);
		switch(input){
		case 'C':
			if(IsEmpty(L)){
				head=Alokasi(hash);
				InsertLast(&L,head);
			}else{
				temphead=head;
				head=Alokasi(hash);
				InsertAfter(&L,head,temphead);
			}
			hash++;
			break;
		case 'R':
			scanf("%d",&n);
			if(Search(L,n)!=Nil){
				head=Search(L,n);
			}
			break;
		case 'H':
			scanf("%d",&n);
			if(Search(L,n)!=Nil){
				head=Search(L,n);
				address deltemp;
				while(Next(head)!=Nil){
					DelAfter(&L,&deltemp,head);
				}
			}
			break;
		case 'B':
			scanf("%d",&n);
			i=1;
			stop=false;
			while(i<=n&&!stop){
				if(Prev(head)!=Nil){
					head=Prev(head);
					i++;
				}else{
					stop=true;
				}
			}
			break;
		case 'F':
			scanf("%d",&n);
			i=1;
			stop=false;
			while(i<=n&&!stop){
				if(Next(head)!=Nil){
					head=Next(head);
					i++;
				}else{
					stop=true;
				}
			}
			break;
		case 'L':
			if(!IsEmpty(L)){
				printf("Isi List : ");
				PrintForward(L);printf("\n");
				printf("HEAD : %d\n",Info(head));
			}else{
				printf("Tidak ada elemen\n");
			}
			break;
		case 'V':
			if(!IsEmpty(L)){
				printf("Isi List : ");
				PrintBackward(L);printf("\n");
				printf("HEAD : %d\n",Info(head));
			}else{
				printf("Tidak ada elemen\n");
			}
			break;
		}
	}while(input!='X');
	return 0;
}
