#include<stdio.h>
#include<stdlib.h>
#define size 100
typedef struct node{
    char stack[size];
    int top;
}ns;
int isfull(ns *r){
    if(r->top==size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isempty(ns *r){
    if(r->top<=-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(ns *s,char symbol){
    if(isfull(s)){
        printf("Stack overflow");
    }
    s->top++;
    s->stack[s->top]=symbol;
}
char pop(ns *s){
    
}
int main(){
    
return 0;
}