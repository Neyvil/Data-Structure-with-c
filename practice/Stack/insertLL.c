#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* link;
}stack;
stack *createnode(int value){
    stack *new=(stack *)malloc(sizeof(stack));
    new->data=value;
    new->link=NULL;
    return new;
}
void push(stack **root,int value){
    stack *newnode=createnode(value);
    newnode->link  =*root;
    *root=newnode;

}
int isEmpty(stack *root){
    return(root==NULL);
}
int pop(stack ** root) {
    if (isEmpty(*root)) {
        printf("Stack is empty!\n");
        return -1;
    }
    stack *temp = *root;
    *root = (*root)->link;
    int poppedValue = temp->data;
    free(temp);
    return poppedValue;
}
void displayStack(stack* root) {
    if (isEmpty(root)) {
        printf("Stack is empty!\n");
        return;
    }
    stack* temp = root;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
int main(){
    stack *root=NULL;
    push(&root,1);
    push(&root,2);
    displayStack(root);

return 0;
}