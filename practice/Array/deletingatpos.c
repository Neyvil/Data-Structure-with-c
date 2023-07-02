#include<stdio.h>
#include<stdlib.h>
int main(){
    int arr[]={1,4,5,2,4,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("THe size: %d",size);
    int pos=2;
    int i;
    for(i=pos-1;i<size;i++){
        arr[i]=arr[i+1];
    }
    size--;
    printf("\nthe array size :%d",size);
    printf("\n\nthe array :");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    

return 0;
}