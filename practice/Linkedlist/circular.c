#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}ns;
ns *newnode(int data){
    ns* temp=(ns *)malloc(sizeof(ns));
    temp->data=data;
    temp->next=NULL;
}
ns *insertitem(ns *head,int data){
    ns *ptr=head;
    ns *temp=newnode(data);
    if(head==NULL){
        head=temp;
        temp->next=head;
        return temp;
    }
    while(ptr->next !=head){
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->next=head;
    return head;

}
void print(ns *head){
    ns* current=head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");

}
int main(){
    ns *head=NULL;
    head=insertitem(head,12);
    head=insertitem(head,17);
    print(head);

return 0;
}