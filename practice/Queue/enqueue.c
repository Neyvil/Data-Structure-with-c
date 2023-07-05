#include<stdio.h>
#include<stdlib.h>
#define size 100
typedef struct queue{
    int f;
    int r;
    int *arr;
}q;
int isfull(q *s){
    if(s->r==size-1){
        return 1;
    }
    else{return 0;}
}
int isempty(q *v){
    if(v->f==v->r){
        return 1;
    }
    else {return 0;}
    
}
void enqueue(q *h,int data){
    if(isfull(h)){
        printf("Queue is full");
    }
    else{
        if(h->f==-1)
            h->f=0;
        h->r++;
        h->arr[h->r]=data;
    }
}
int dequeue(q *p){
    if(isempty(p)){
        printf("Queue is empty");
    }
    int c=p->arr[p->f];
    p->f++;
    return c;
}
void display(q* root){
    for(int i=root->f;i<=root->r;i++){
        printf("%d ",root->arr[i]);
    }
}

int main(){
    q Queue;
    Queue.f=Queue.r=-1;
    Queue.arr=(int *)malloc(size*sizeof(int));
    enqueue(&Queue,14);
    enqueue(&Queue,89);
    display(&Queue);
    printf("\n");
    int num=dequeue(&Queue);
    printf("The dequeue element:%d ",num);
    printf("\n");
    display(&Queue);


return 0;
}