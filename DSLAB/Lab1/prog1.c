#include<stdio.h>
#include<stdlib.h>
//Matrix addition & subtraction
int arr1[2][2]={{1,2},{6,8}};
int arr2[2][2]={{3,6},{5,9}};
int arr3[2][2];
int arr4[2][2];
int matrixadd(int i,int j){
  arr3[i][j]=arr1[i][j]+arr2[i][j];
  return arr3[i][j];
}
int matrixsub(int i,int j){
  arr4[i][j]=arr1[i][j]-arr2[i][j];
  return arr3[i][j];
}
int main(){
   int i,j;
   for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        matrixadd(i,j);
    }
   }
   printf("Matrix Addition: \n");
   for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        printf("%d ",arr3[i][j]);
    }
    printf("\n");
   }
   printf("\n");
   
   for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        matrixsub(i,j);
    }
   }
   printf("Matrix Substraction: \n");
   for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        printf("%d ",arr4[i][j]);
    }
    printf("\n");
   }



return 0;
}