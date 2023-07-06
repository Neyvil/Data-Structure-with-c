#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int left[], int leftsize, int right[], int rightsize)
{
    int i = 0, j = 0, k = 0;

    while (i < leftsize && j < rightsize)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while(i<leftsize){
        arr[k++]=left[i++];
    }
    while (j<rightsize)
    {
        arr[k++]=right[j++];
    }
    
}
void mergsort(int arr[], int size)
{
    if (size < 2)
        return;
    int mid = size / 2;
    int left[mid], right[size - mid];
    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++)
    {
        right[i - mid] = arr[i];
    }
    mergsort(left, mid);
    mergsort(right, size - mid);
    merge(arr, left, mid, right, size - mid);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[]={3,6,2,1,9,7,5,4,8};
    int size=sizeof(arr)/sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    mergsort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);



    return 0;
}