#include<stdio.h>
#include<stdlib.h>
void insertion(int arr[],int size){
    for(int i=1;i<size;i++){
        int key=arr[i];
        int j=i-1;

        while (key<arr[j]&&j>=0)
        {
            arr[j+1]=arr[j];
            --j;
        }
        
        arr[j+1]=key;
    }
}
int main(){
    int arr[] = {78, 45, 24, 53, 69, 99, 10, 18};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertion(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

return 0;
}