#include<stdio.h>

int main(){

    float  matrix[10][10], ratio, det;

    int i, j, k, n;

    printf("Enter order of matrix: ");

    scanf("%d", &n);

    printf("Enter the matrix: \n");

    for(i = 0; i < n; i++){

        for(j = 0; j < n; j++){

            scanf("%f", &matrix[i][j]);

        }

    }

    /* Conversion of matrix to upper triangular */

    for(i = 0; i < n; i++){

        for(j = 0; j < n; j++){

            if(j>i){

                ratio = matrix[j][i]/matrix[i][i];

                for(k = 0; k < n; k++){

                    matrix[j][k] -= ratio * matrix[i][k];

                }

            }

        }

    }
        for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%.2f ",matrix[i][j]);
        }
        printf("%.2f\n",matrix[i][j]);
    }

    det = 1; //storage for determinant

    for(i = 0; i < n; i++)

        det *= matrix[i][i];

    printf("The determinant of matrix is: %.2f\n\n", det);

    return 0;

}