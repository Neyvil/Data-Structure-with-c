#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 8

typedef struct {
    int key;
    int value;
} HashNode;

HashNode* hashArray[SIZE];
int itemCount = 0;

// Hash function to calculate the index for a given key
int hash(int key) {
    return key % SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(int key, int value) {
    if (itemCount == SIZE) {
        printf("Hash table is full. Cannot insert more elements.\n");
        return;
    }
    
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    
    int index = hash(key);
    
    // Linear probing to find an empty slot
    while (hashArray[index] != NULL) {
        index++;
        index %= SIZE;
    }
    
    hashArray[index] = newNode;
    itemCount++;
}

// Function to search for a value based on a given key
int search(int key) {
    int index = hash(key);
    int probes = 0;
    
    while (hashArray[index] != NULL) {
        if (hashArray[index]->key == key) {
            return hashArray[index]->value;
        }
        
        index++;
        index %= SIZE;
        probes++;
        
        // If we have gone through all the slots or encountered an empty slot,
        // the key is not present in the hash table
        if (probes == SIZE || hashArray[index] == NULL) {
            break;
        }
    }
    
    return -1; // Key not found
}

// Function to delete a key-value pair from the hash table
void delete(int key) {
    int index = hash(key);
    int probes = 0;
    
    while (hashArray[index] != NULL) {
        if (hashArray[index]->key == key) {
            free(hashArray[index]);
            hashArray[index] = NULL;
            itemCount--;
            return;
        }
        
        index++;
        index %= SIZE;
        probes++;
        
        // If we have gone through all the slots or encountered an empty slot,
        // the key is not present in the hash table
        if (probes == SIZE || hashArray[index] == NULL) {
            break;
        }
    }
    
    printf("Key not found. Cannot delete.\n");
}

// Function to display the contents of the hash table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashArray[i] != NULL) {
            printf("(%d, %d) ", hashArray[i]->key, hashArray[i]->value);
        } else {
            printf("-- ");
        }
    }
    printf("\n");
}

int main() {
    // Inserting elements into the hash table
    insert(1, 10);
    insert(2, 20);
    insert(3, 30);
    insert(4, 40);
    insert(14, 140); // Hash collision with key 4
    
    display();
    
    // Searching for values based on keys
    int value = search(3);
    if (value != -1) {
        printf("Value for key 3: %d\n", value);
    } else {
        printf("Key 3 not found.\n");
    }
    
    value = search(5);
    if (value != -1) {
        printf("Value for key 5: %d\n", value);
    } else {
        printf("Key 5 not found.\n");
    }
    
    // Deleting elements from the hash table
    delete(2);
    delete(6); // Key not present
    
    display();
    
    return 0;
}
