#include <stdio.h>
#include "bintree.h"

int main(){
    List LS;
	BinTree T=Nil;
	infotype X,L,R,Y;
	address pt;
	int input,n,i;
    boolean kiri;

    printf("akar : ");scanf("%d",&X);
    printf("kiri : ");scanf("%d",&L);
    printf("kanan : ");scanf("%d",&R);
    printf("1. MakeTree\n2. Tree\n3. BuilBalanceTree\ninput : ");scanf("%d",&input);
    if(input==1){
        MakeTree(X,AlokNode(L),AlokNode(R),&T);
    }else if(input==2){
        T=Tree(X,AlokNode(L),AlokNode(R));
    }else{
        scanf("%d",&n);
        T=BuildBalanceTree(n);
    }
    
	while(1){
		printf("\n1. SearchTree\n2. NbElmt\n3. NbDaun\n4. Level\n5. Tinggi\n6. AddDaunTerkiri\n");
        printf("7. AddDaun\n8. DelDaunTerkiri\n9. DelDaun\n10. MakeListDaun\n11. MakeListPreorder\n");
        printf("12. MakeListLevel\n13. BSearch\n14. InsSearch\n15. DelBtree\n\n");
		printf("preorder : ");PrintPreorder(T);printf("\n");
        printf("postorder : ");PrintPostorder(T);printf("\n");
        printf("inorder : ");PrintInorder(T);printf("\n");
        printf("tree : \n");PrintTree(T,2);printf("\n");

        printf("input : ");scanf("%d",&input);
		switch(input){
			case 1:
				scanf("%d",&X);
				if(SearchTree(T,X)){
                    printf("found\n");
                }else{
                    printf("not found\n");
                }
				break;
			case 2:
				printf("nbelmt : %d\n",NbElmt(T));
				break;
			case 3:
				printf("nbdaun : %d\n",NbDaun(T));
				break;
			case 4:
                scanf("%d",&X);
				printf("level : %d\n",Level(T,X));
				break;
			case 5:
				printf("tinggi : %d\n",Tinggi(T));
				break;
			case 6:
				scanf("%d",&X);
				AddDaunTerkiri(&T,X);
				break;
			case 7:
				scanf("%d",&X);
				scanf("%d",&Y);
                scanf("%d",&n);
                if(n==1){
                    kiri=true;
                }else{
                    kiri=false;
                }
				AddDaun(&T,X,Y,kiri);
				break;
			case 8:
				DelDaunTerkiri(&T,&X);
                printf("deleted : %d",X);
				break;
			case 9:
				scanf("%d",&X);
                DelDaun(&T,X);
				break;
            case 10:
                LS=MakeListDaun(T);
                printf("list :\n");PrintList(LS);printf("\n");
                break;
            case 11:
                LS=MakeListPreorder(T);
                printf("list :\n");PrintList(LS);printf("\n");
                break;
            case 12:
                scanf("%d",&n);
                LS=MakeListLevel(T,n);
                printf("list :\n");PrintList(LS);printf("\n");
                break;
            case 13:
            	scanf("%d",&X);
				if(BSearch(T,X)){
                    printf("found\n");
                }else{
                    printf("not found\n");
                }
				break;
            case 14:
                scanf("%d",&X);
                InsSearch(&T,X);
                break;
            case 15:
                scanf("%d",&X);
                DelBtree(&T,X);
                break;

		}
	}
	return 0;
}