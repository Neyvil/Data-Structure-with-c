#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} ns;

void delete_node(ns** head, int key) {
    if (*head == NULL) {
        printf("Cannot delete from an empty list.\n");
        return;
    }

    ns* current = *head;
    ns* prev = NULL;
    int found = 0;

    // Traverse the list to find the node to be deleted
    do {
        if (current->data == key) {
            found = 1;
            break;
        }
        prev = current;
        current = current->link;
    } while (current != *head);

    if (found) {
        // Check if it's the only node in the list
        if (current->link == *head) {
            *head = NULL;
        }
        // Check if it's the first node in the list
        else if (current == *head) {
            ns* last = *head;
            while (last->link != *head) {
                last = last->link;
            }
            last->link = current->link;
            *head = current->link;
        }
        // It's not the first node or the only node
        else {
            prev->link = current->link;
        }

        free(current);
        printf("Node with key %d deleted from the list.\n", key);
    } else {
        printf("Node with key %d not found in the list.\n", key);
    }
}

void display(ns* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    ns* current = head;

    // Traverse the list and print the nodes
    do {
        printf("%d ", current->data);
        current = current->link;
    } while (current != head);

    printf("\n");
}

int main() {
    ns* head = NULL;

    // Create a circular linked list
    head = malloc(sizeof(ns));
    head->data = 1;
    head->link = head;

    ns* node2 = malloc(sizeof(ns));
    node2->data = 2;
    node2->link = head;

    ns* node3 = malloc(sizeof(ns));
    node3->data = 3;
    node3->link = head;

    head->link = node2;
    node2->link = node3;

    // Display the initial list
    printf("Initial list: ");
    display(head);

    // Delete nodes
    delete_node(&head, 2); // Delete node with key 2
    delete_node(&head, 1); // Delete node with key 1
    delete_node(&head, 3); // Delete node with key 3
    delete_node(&head, 4); // Try to delete node with key 4 (not found)

    // Display the final list
    printf("Final list: ");
    display(head);

    return 0;
}
