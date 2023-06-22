#include <stdio.h>
void printarray(int arr[],int n);

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            printarray(arr,n);
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printarray(arr,n);
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap arr[i] and arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        printarray(arr,n);
    }
}

// Function to print an array
void printarray(int arr[],int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {13,9,2,12,7,64,25};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Bubble Sort
    printf("Array sorted using Bubble Sort: ");
    bubbleSort(arr, n);
    printf("\n");
    
    

    // Resetting array to its original state
    int resetArr[] = {13,9,2,12,7,64,25};

    // Insertion Sort
    
    printf("Array sorted using Insertion Sort: ");
    insertionSort(resetArr, n);
    printf("\n");

    // Resetting array to its original state
    int resetArr2[] = {13,9,2,12,7,64,25};

    // Selection Sort
    printf("Array sorted using Selection Sort: ");
    selectionSort(resetArr2, n);
    printf("\n");
    
   
    
    return 0;
}