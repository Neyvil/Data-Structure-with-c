#include<stdio.h>
#include<stdlib.h>
struct node{
     int data;
     struct node *link;
};
typedef struct node n;
// METHOD 1 TO ACESS NODES
int main(){
       n *head=(n *)malloc(sizeof(n));
       head -> data= 45;
       head -> link= NULL;
       
       n *c1 =(n *)malloc(sizeof(n));
       c1 -> data=98;
       c1 -> link= NULL;
       head ->link=c1;
       
       n *c2 =(n *)malloc(sizeof(n));
       c2 -> data=3;
       c2 -> link=NULL;
       c1 -> link=c2;


return 0;
}