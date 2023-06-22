#include <stdio.h>

// Iterative Binary Search
int binarySearchIterative(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate the middle index

        if (arr[mid] == key) {
            return mid; // Key found at the middle index
        }

        if (arr[mid] < key) {
            low = mid + 1; // Key is in the right half
        } else {
            high = mid - 1; // Key is in the left half
        }
    }

    return -1; // Key not found
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2; // Calculate the middle index

        if (arr[mid] == key) {
            return mid; // Key found at the middle index
        }

        if (arr[mid] < key) {
            return binarySearchRecursive(arr, mid + 1, high, key); // Search in the right half
        } else {
            return binarySearchRecursive(arr, low, mid - 1, key); // Search in the left half
        }
    }

    return -1; // Key not found
}

int main() {
    int arr[] = {1, 2, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    // Iterative binary search
    int indexIterative = binarySearchIterative(arr, n, key);
    if (indexIterative != -1) {
        printf("Key %d found at index %d using iterative binary search.\n", key, indexIterative);
    } else {
        printf("Key %d not found using iterative binary search.\n", key);
    }

    // Recursive binary search
    int indexRecursive = binarySearchRecursive(arr, 0, n - 1, key);
    if (indexRecursive != -1) {
        printf("Key %d found at index %d using recursive binary search.\n", key, indexRecursive);
    } else {
        printf("Key %d not found using recursive binary search.\n", key);
    }

    return 0;
}