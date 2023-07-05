#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

Node* x[SIZE];


int modulo10(int key) {
    return key % SIZE;
}

void insert(int key, int value) {
    int index = modulo10(key);
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    
    // If the slot is empty, insert the new node as the head of the list
    if (x[index] == NULL) {
        x[index] = newNode;
    } else {
        // If there are already nodes in the slot, append the new node at the end
        Node* currentNode = x[index];
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        Node* currentNode = x[i];
        while (currentNode != NULL) {
            printf("(%d, %d) ", currentNode->key, currentNode->value);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}
int main(){
    for (int i = 0; i < SIZE; i++) {
        x[i] = NULL;
    }
    insert(0, 10);
    insert(0, 70);
    insert(2, 32);
    insert(2, 52);
    insert(2, 12);
    insert(3, 73);
    insert(6, 26);
    insert(8, 88);
    

    display();
}