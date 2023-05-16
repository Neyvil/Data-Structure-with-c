#include<stdio.h>
#include<stdlib.h>

// Matrix Multiplication
int arr1[2][2] = {{1, 2}, {6, 8}};
int arr2[2][2] = {{3, 6}, {5, 9}};
int arr4[2][2];

int matrixmul(int i, int j, int k) {
    arr4[i][j] += arr1[i][k] * arr2[k][j];
    return arr4[i][j];
}

int main() {
    int i, j, k;
    
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            arr4[i][j] = 0;
            for (k = 0; k < 2; k++) {
                matrixmul(i, j, k);
            }
        }
    }
    
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", arr4[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
