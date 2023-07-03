#include<stdio.h>
#include<stdlib.h>
#define max 100
//ARRAY IMPLEMENTATITON
typedef struct stack{
    int stack[max];
    int top;
}ns;
void push(ns* s,int data){
    if(s->top==max-1){printf("STACK OVERFLOW");}
    else{
        printf("\nPushed %d to stack \n",data);
        s->top++;
        s->stack[s->top]=data;
    }
}
void pop(ns* s){
    if(s->top<=-1){printf("Stack underflow");}
    else{
        printf("\n%d removed from stack",s->stack[s->top]);
        s->top--;
    }
}
void display(ns* s){
    int i=0;
    printf("\nstack: ");
    while(i<=s->top){
        printf("%d ",s->stack[i++]);
    }
}
int main(){
    ns s;
    s.top=-1;
    push(&s,9);
    display(&s);
    push(&s,10);
    display(&s);
    push(&s,78);
    display(&s);
    push(&s,90);
    display(&s);
    int i=s.top;
    while(i>=0){
        pop(&s);
        display(&s);
        i--;
    }

return 0;
}