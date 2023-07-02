#include <stdio.h>
#include <stdlib.h>
int binaryrecur(int arr[], int low, int high, int key)
{
    if (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] > key)
        {
            return binaryrecur(arr, low, high = mid - 1, key);
        }
        else
        {
            return binaryrecur(arr, low = mid + 1, high, key);
        }
    }
    return -1;
}
int binarsearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (high >= low)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] > key)
        {
            high = mid - 1;
        }
        if (arr[mid] < key)
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 5, 6, 7, 8, 34, 45, 54, 65, 66, 78, 89, 99, 100, 149, 150, 155};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index = binarsearch(arr,size,7);
    printf("7 found at index %d \n", index + 1);
    int e=7;
    int index1=binaryrecur(arr,0,size-1,e);
    printf("%d found at index %d",e,index1+1);
    return 0;
}