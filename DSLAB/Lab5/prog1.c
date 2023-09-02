#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectsort(int arr[], int size)
{
    int i;
    for (i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(&arr[min_index], &arr[i]);
    }
}
void bublesort(int arr[], int size)
{
    int step, i;
    for (step = 0; step < size-1; step++)
    {
        for (i = 0; i < size-1 - step; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}
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
void printArray(int arr[], int size) {
    printf("\n Soted Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[] = {10, 3, 2, 9, 6, 8, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    bublesort(arr, size);
    printArray(arr,size);

    int arr1[] = {10, 3, 2, 9, 6, 8, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    selectsort(arr1, size1);
    printArray(arr1,size1);

    int arr2[] = {10, 3, 2, 9, 6, 8, 7};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    insertion(arr2, size2);
    printArray(arr2,size2);

    return 0;
}