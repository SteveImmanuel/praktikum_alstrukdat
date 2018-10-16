#include <stdio.h>
#include "point.h"

int main(){
	POINT P;
	float sudut;
	BacaPOINT(&P);
	TulisPOINT(P);
	scanf("%f",&sudut);
	Putar(&P,sudut);
	TulisPOINT(P);
	return 0;
}