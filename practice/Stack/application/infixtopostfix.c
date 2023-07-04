#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size  100
typedef struct node{
    char infix[size];
    char stack[size];
    int postfix[size];
    int top;
}ns;
int isfull(ns *s){
    if(s->top==size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isempty(ns *s){
    if(s->top<=-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(ns *p,char symbol){
    if(isfull(p)){
        printf("Stack is overflow");
    }
    else{
        p->top++;
        p->stack[p->top]=symbol;
    }
}
char pop(ns *po){
    if(isempty(po)){
        printf("Stack underflow");
    }
    else{
        char c=po->stack[po->top];
        po->top--;
        return(c);
    }
}
int precedence(char symbol){
    switch(symbol){
        case'^':
            return 5;
        case '/':
            return 4;
        case '*':
            return 3;
        case '+':
            return 2;
        case '-':
            return 1;
        default:return 0;
    }
}
void print(ns *s){
    int i=0;
    printf("The equivalent postfix expression is: ");
    while(s->postfix[i]){
        printf("%c",s->postfix[i++]);
    }
    printf("\n");
}
void infixtopost(ns *a){
    int i,j=0;
    char symbol;
    for(i=0;i<strlen(a->infix);i++){
        symbol=a->infix[i];
        switch(symbol){
            case '(':
                push(a,symbol);
                break;
            case ')':
                while(pop(a)!='('){
                    a->postfix[j++]=pop(a);
                }
                break;
            case '^':
            case '/':
            case '*':
            case '+':
            case '-':
                while(!isempty(a)&&(precedence(symbol)<=precedence(a->stack[a->top]))){
                    a->postfix[j++]=pop(a);
                }
                push(a,symbol);
                break;
            default:
                a->postfix[j++]=symbol;

        }

    }
    while(!isempty(a)){
        a->postfix[j++]=pop(a);
    }
    a->postfix[j]='\0';
}

int main(){
    ns h;
    
    h.top=-1;
    printf("Enter infix expression : ");
    scanf("%[^\n]s",h.infix);
    infixtopost(&h);
    print(&h);

return 0;
}