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
ns *del_first(ns *head){
    if(head==NULL){
         printf("List is already empty");
    }
    else{
        ns *ptr=head;
        ns *ptr1=head;
        head=ptr->link;
        free(ptr1);
        ptr1=NULL;
        
    }
    return head;
}
ns *del_end(ns *head){
    if(head==NULL){
        printf("List is already empty");
    }
    else if(head->link==NULL){
        free(head);
        head=NULL;
    }
    else{
        
        ns *ptr=head;
        ns *temp=head;
        while(ptr->link!=NULL){
            temp=ptr;
            ptr=ptr->link;
        }
        temp->link=NULL;
        free(ptr);
        ptr=NULL;
    }
    return head;
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
    int num=7, i=1;
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
    head=del_end(head);
    display(head);
    printf("\n");
    head=del_first(head);
    display(head);
    printf("\n");
    
    return 0;
}
