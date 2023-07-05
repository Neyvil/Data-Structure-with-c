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
int main()
{
    int arr[] = {78, 45, 24, 53, 69, 99, 10, 18};
    int size = sizeof(arr) / sizeof(arr[0]);

    selectsort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}