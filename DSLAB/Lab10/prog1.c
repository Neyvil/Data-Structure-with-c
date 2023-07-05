#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 8

typedef struct {
    int key;
    int value;
} HashNode;

HashNode* x[SIZE];
int itemCount = 0;

int modulo10(int key) {
    return key % SIZE;
}


void insert(int key, int value) {
    if (itemCount == SIZE) {
        printf("Hash table is full. Cannot insert more elements.\n");
        return;
    }
    
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    
    int index = modulo10(key);
    
    // Linear probing to find an empty slot
    while (x[index] != NULL) {
        index++;
        index %= SIZE;
    }
    
    x[index] = newNode;
    itemCount++;
}
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (x[i] != NULL) {
            printf("(%d, %d) ", x[i]->key, x[i]->value);
        } else {
            printf("-- ");
        }
    }
    printf("\n");
}

int main(){
    insert(0,10);
    insert(1,70);
    insert(2,32);
    insert(3,73);
    insert(4,52);
    insert(5,12);
    insert(6,26);
    insert(8,88);
    
    display();
}