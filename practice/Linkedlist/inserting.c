#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} ns;

ns* newnode(int data) {
    ns* temp = (ns*)malloc(sizeof(ns));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void add_at_end(ns** head, int data) {
    ns* temp = newnode(data);
    
    if (*head == NULL) {
        *head = temp;
        return;
    }

    ns* ptr = *head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void print(ns* head) {
    ns* ptr = head;
    while (ptr != NULL) {
        printf("->%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    ns* head = NULL;
    add_at_end(&head, 12);
    add_at_end(&head, 14);
    print(head);

    return 0;
}
