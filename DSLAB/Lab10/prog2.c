#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

Node* hashArray[SIZE];

// Hash function to calculate the index for a given key
int hash(int key) {
    return key % SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(int key, int value) {
    int index = hash(key);
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    
    // If the slot is empty, insert the new node as the head of the list
    if (hashArray[index] == NULL) {
        hashArray[index] = newNode;
    } else {
        // If there are already nodes in the slot, append the new node at the end
        Node* currentNode = hashArray[index];
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

// Function to search for a value based on a given key
int search(int key) {
    int index = hash(key);
    
    Node* currentNode = hashArray[index];
    while (currentNode != NULL) {
        if (currentNode->key == key) {
            return currentNode->value;
        }
        currentNode = currentNode->next;
    }
    
    return -1; // Key not found
}

// Function to delete a key-value pair from the hash table
void delete(int key) {
    int index = hash(key);
    
    Node* currentNode = hashArray[index];
    Node* prevNode = NULL;
    
    while (currentNode != NULL) {
        if (currentNode->key == key) {
            if (prevNode == NULL) {
                // If the node to be deleted is the head of the list
                hashArray[index] = currentNode->next;
            } else {
                prevNode->next = currentNode->next;
            }
            free(currentNode);
            return;
        }
        
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    
    printf("Key not found. Cannot delete.\n");
}

// Function to display the contents of the hash table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        Node* currentNode = hashArray[i];
        while (currentNode != NULL) {
            printf("(%d, %d) ", currentNode->key, currentNode->value);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}

int main() {
    // Initializing the hash table
    for (int i = 0; i < SIZE; i++) {
        hashArray[i] = NULL;
    }
    
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
