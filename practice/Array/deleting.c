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
    size--;
    printf("\nthe array size :%d",size);
    for(int i=0;i<size;i++){
        arr[i]=arr[i+1];
    }
    printf("\n\nthe array :");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

return 0;
}
