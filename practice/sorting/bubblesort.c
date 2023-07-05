#include <stdio.h>
#include <stdlib.h>

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
int main()
{
    int arr[] = {10, 3, 2, 9, 6, 8, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    bublesort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}