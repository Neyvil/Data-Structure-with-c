#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}ns;
ns *newnode(int data){
    ns *temp=(ns *)malloc(sizeof(ns));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
ns *additem(ns *head,int item){
    ns *temp=newnode(item);
    ns *ptr;
    ptr=head;
    if(head == NULL){
        head=temp;
        return head;
    }
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
    return head;
}
ns* del(ns* head, int ele) {
    ns* ptr = head;
    ns* prev = NULL;

    while (ptr != NULL) {
        if (ptr->data == ele) {
            if (prev == NULL) {
                head = ptr->next;
            } else {
                prev->next = ptr->next;
            }
            ns* temp = ptr;
            ptr = ptr->next;
            free(temp);
        } else {
            prev = ptr;
            ptr = ptr->next;
        }
    }
    return head;
}
void print(ns *head){
    ns*ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    ns* head = NULL;
    int el;
    printf("ENTER : ");
    for(int i=0;i<3;i++){
        scanf("%d",&el);
        head=additem(head,el);
    }
    head=additem(head, 12);
    head=additem(head, 15);
    print(head);
printf("\n");
    head=del(head,15);
    print(head);

return 0;
}