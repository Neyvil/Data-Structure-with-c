#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}
 

 
int main(){
    struct queue q;
    
    q.f = q.r = 0;
    int choice,d,num,pos;
    num=q.size;
    q.arr = (int*) malloc(q.size*sizeof(int));
    printf("Total no of entries: ");
    scanf("%d",&num);

    // Enqueue few elements
    for(int i=0;i<num;i++){
        printf("Enter element to be inserted: ");
        scanf("%d",&d);
        enqueue(&q,d);
    }
    for(int j=q.f+1;j<=q.r;j++){
        printf("%d ",q.arr[j]);
    }
      
    printf("\n\nThe dequeue element is %d\n",dequeue(&q));
    printf("After dequeing the  list  is: ");
      for(int j=q.f+1;j<=q.r;j++){
        printf("%d ",q.arr[j]);
    }
    
    return 0;
}
