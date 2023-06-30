#include<stdio.h>
#include<stdlib.h>
int main(){
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("\nthe array size :%d",size);
    printf("\n\nthe array :");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    size=size+1;
    for(int i=size-1;i>0;i--){
    arr[i]=arr[i-1];
}

    arr[0]=9;
    printf("\nthe array size :%d",size);
    printf("\n\nthe array :");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }



return 0;
}
