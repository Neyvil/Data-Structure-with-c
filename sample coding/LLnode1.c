#include<stdio.h>
#include<stdlib.h>
//METHOD 2 FOR ACCESING NODES
struct node{
     int data;
     struct node *link;
};
typedef struct node n;
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
return 0;
}