#include<stdio.h>
#include<stdlib.h>
//STRUCTURE
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}ns;

//CREATE
ns *newnode(int num){
    ns *temp=(ns *)malloc(sizeof(ns));
    temp->data=num;
    temp->left=temp->right=NULL;
    return temp;
}

//INSERT
ns *insert(ns *root,int item){
    if(root==NULL) 
        return newnode(item);
    if(item<root->data)
        root->left=insert(root->left,item);
    else
        root->right=insert(root->right,item);
    return root;
}



//DELETE
ns *minValueNode(ns *node) {
  ns *current = node;


  while (current && current->left != NULL)
    current = current->left;

  return current;
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

//INORDER,PREORDER,POSTORDER TRAVERSE
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
void preorder(ns *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        
        preorder(root->right);
    }
}

//DISPLAY
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
ns *create(ns *root){
    root=insert(root,8);
    root=insert(root,3);
    root=insert(root,10);
    display(root);
    return root;
}
//MAIN
int main(){
    ns *root=NULL;
    int num;
    
    root=create(root);
    root=insert(root,1);
    display(root);
    root=insert(root,6);
    display(root);
    root=insert(root,14);
    display(root);
    root=insert(root,4);
    display(root);
    root=insert(root,7);
    display(root);
    
    printf("After deleting 3 : \n");
    deleteNode(root,3);
    display(root);

return 0;
}