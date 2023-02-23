# include <stdio.h>
# include <stdlib.h>

void matrix_multiply(int A[][100], int B[][100], int C[][100],int r1, int c1, int r2, int c2){
    
    
    for(int i = 0;i < r1;i++){
        for(int j = 0;j < c2;j++){
            C[i][j] = 0;
        }
    }

    for(int i = 0; i < r1;i++){
        for(int j = 0;j < c2;j++){
            for(int k = 0;k < c1;k++){
                C[i][j] = C[i][j] + (A[i][j] * B[i][j]);
            }
        }
    }
}

void display(int result[][10], int row, int column){

    printf("\nOutput Matrix:\n");
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            printf("%d  ", result[i][j]);
            if (j == column - 1)
                printf("\n");
        }
    }
}

void getMatrixElements(int arr[][100], int row, int column){

    printf("\nEnter elements: \n");

    for (int i = 0; i < row; ++i){
        for (int j = 0; j < column; ++j){
            printf("Enter a%d%d: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
}

int main(){
    
    int first[10][10], second[10][10], result[10][10], r1, c1, r2, c2;
    printf("Enter rows and column for the first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and column for the second matrix: ");
    scanf("%d %d", &r2, &c2);

    getMatrixElements(first, r1, c1);

    getMatrixElements(second, r2, c2);

    matrix_multiply(first, second, result, r1, c1, r2, c2);

    display(result,r1,c2);

    return 0;
}