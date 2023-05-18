#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} ns;

void add_last(ns *head, int data) {
    ns *ptr, *temp;
    ptr = head;
    temp = malloc(sizeof(ns));
    temp->data = data;
    temp->link = NULL;

    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

ns *add_beg(ns *head, int s) {
    ns *ptr = malloc(sizeof(ns));
    ptr->data = s;
    ptr->link = head;

    head = ptr;
}
void add_pos(ns *head,int d,int pos){
    pos--;
    ns *ptr;
    ptr= head;
    ns *temp = malloc(sizeof(ns));
    temp->data =d;
    temp->link =NULL;
    while(pos!=0){
        ptr = ptr->link;
        pos--;
    }
    temp->link = ptr->link;
    ptr->link = temp;

}

void display(ns *head) {
    ns *ptr;
    ptr = head;
    printf("Output:");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

int main() {
    int num=2, i=1;
    ns *head = (ns *)malloc(sizeof(ns));
    head->data=1;
    head->link=NULL;
    while (num != 0) {
        i++;
        add_last(head, i);
        num--;
    }
    display(head);
    printf("\n");
    head=add_beg(head,4);
    display(head);
    printf("\n");
    add_last(head,5);
    display(head);
    printf("\n");
    add_pos(head,6,3);
    display(head);
    printf("\n");
    add_pos(head,7,2);
    display(head);
    printf("\n");
    add_pos(head,8,6);
    display(head);
    printf("\n");
    return 0;
}
