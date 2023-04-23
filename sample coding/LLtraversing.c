#include<stdio.h>
#include<stdlib.h>
//USING METHOD 2 FOR ACCESING NODES
struct node{
     int data;
     struct node *link;
};
typedef struct node n;
void count_nodes(n *head){
    int count = 0;
    if(head == NULL)
       printf("LINKED LIST is EMPTY\n");
    n *ptr=head;
    while(ptr != NULL)
    {
        count++;
        
        printf("%d\n",ptr->data);
        ptr = ptr->link;
    }
    printf("%d",count);
}
int main(){
      n *head=(n *)malloc(sizeof(n));
       head -> data= 45;
       head -> link= NULL;
       
       n *current =(n *)malloc(sizeof(n));
       current -> data=98;
       current-> link= NULL;
       head ->link=current;
       
       current =(n *)malloc(sizeof(n));
       current-> data=3;
       current -> link=NULL;

       head->link->link=current;
       count_nodes(head);
return 0;
}
