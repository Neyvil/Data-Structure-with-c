#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
typedef struct node ns;
void add_at_end(ns *head,int d){
      ns *ptr,*temp;
      ptr=head;
      temp=(ns *)malloc(sizeof(ns));
      temp->data=d;
      temp->link=NULL;

      while(ptr->link!=NULL){
        ptr=ptr->link;
      }
      ptr->link=temp;

}
void add_beg(ns **head,int s){
    ns *ptr=malloc(sizeof(ns));
    ptr->data=s;
    ptr->link=NULL;

    ptr->link=*head;
    *head=ptr;
}
int main(){
    ns *head=(ns *)malloc(sizeof(ns));
    head->data=45;
    head->link=NULL;
    add_at_end(head,900);
    add_at_end(head,1000);
    add_beg(&head,69);
    ns *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    
return 0;
}