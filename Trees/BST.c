#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}ns;
ns *newnode(int num){
    ns *temp=(ns *)malloc(sizeof(ns));
    temp->data=num;
    temp->left=temp->right=NULL;
    return temp;
}
ns *insert(ns *root,int item){
    if(root==NULL) 
        return newnode(item);
    if(item<root->data)
        root->left=insert(root->left,item);
    else
        root->right=insert(root->right,item);
    return root;
}
void inorder(ns *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(ns *root){
    if(root!=NULL){
        postorder(root->left);
        
        postorder(root->right);
        printf("%d ",root->data);

    }
}
ns *minValueNode(ns *node) {
  ns *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}
void preorder(ns *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        
        preorder(root->right);
    }
}
ns *deleteNode(ns *root, int key) {
 
  if (root == NULL) return root;

  
  if (key < root->data)
    root->left = deleteNode(root->left, key);
  else if (key > root->data)
    root->right = deleteNode(root->right, key);

  else {
    
    if (root->left == NULL) {
      ns *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      ns *temp = root->left;
      free(root);
      return temp;
    }

    
    ns *temp = minValueNode(root->right);

    
    root->data = temp->data;

   
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}
void display(ns *root){
    printf("The inorder traversal: \n");
    inorder(root);
    printf("\n");
    printf("The preorder traversal: \n");
    preorder(root);
     printf("\n");
    printf("The postorder traversal: \n");
    postorder(root);
     printf("\n");
     printf("\n");

}
void op(ns *root){
    int num;
    root=insert(root,1);
    display(root);
    root=insert(root,2);
    display(root);
    root=insert(root,3);
    display(root);
    root=insert(root,4);
    display(root);
    root=insert(root,90);
    display(root);
    printf("Enter no to be delete from tree:");
    scanf("%d",&num);
    printf("After deleting %d : \n",num);
    deleteNode(root,num);
    display(root);
}

int main(){
    ns *root=NULL;
    op(root);
return 0;
}