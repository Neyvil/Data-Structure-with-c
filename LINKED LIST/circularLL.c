#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} ns;

ns* add_empty(ns* head, int data) {
    ns* temp = malloc(sizeof(ns));
    temp->data = data;
    temp->link = NULL;
    head = temp;
    return head;
}

ns* add_end(ns* head, int data) {
    if (head == NULL)
        return add_empty(head, data);

    ns* temp = malloc(sizeof(ns));
    temp->data = data;
    temp->link = NULL;

    ns* ptr = head;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = temp;

    return head;
}

ns* add_first(ns* head, int data) {
    if (head == NULL)
        return add_empty(head, data);

    ns* temp = malloc(sizeof(ns));
    temp->data = data;
    temp->link = head;
    head = temp;

    return head;
}
ns *add_after(ns *head, int data,int item){
    ns *ptr,*temp;
    ptr=head->link;
    do{
        if(item==ptr->data){
        ns*temp=malloc(sizeof(ns));
        temp->data=data;
        temp->link=ptr->link;
        ptr->link=temp;
        if(ptr==head)
            head=temp;
        return head;
        }
        ptr=ptr->link;

    }while(ptr!=head->link);
    printf("Item not present on list\n");
    return head;
}

void display(ns* head) {
    ns* ptr = head;
     printf("Output: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

int main() {
    ns* head = NULL;
    head = add_empty(head, 5);
    head = add_end(head, 2);
    head = add_end(head, 3);
    head = add_end(head, 4);
    head = add_end(head, 50);
    display(head);
    printf("\n");
    // head= add_first(head,1);
    // display(head);
    // printf("\n");
    head=add_after(head,78,5);
    display(head);
    printf("\n");


    return 0;
}
