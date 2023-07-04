#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
typedef struct node{
    char stack[size];
    char postfix[size];
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
    if(isempty(s)){
        printf("Stack Underflow");
    }
    char c=s->stack[s->top];
    s->top--;
    return c;
}
int calculate(ns* n){
    char a;
    int i;
    for(i=0;i<strlen(n->postfix);i++){
        a=n->postfix[i];
        if(a>='0' && a<='9'){
            push(n,a-'0');
        }
        else{
            int a1=pop(n);
            int a2=pop(n);
            switch(a){
                case '+':
                    push(n,a2+a1);
                    break;
                case '-':
                    push(n,a2-a1);
                    break;
                case '*':
                    push(n,a2*a1);

            }
        }
    }
    return pop(n);

}
int main(){
    ns s;
    s.top=-1;
    printf("Enter postfix expression: ");
    scanf("%s",s.postfix);
    for(int i=0;i<strlen(s.postfix);i++)
         printf("%c",s.postfix[i]);
    printf("\nThe answer is:%d",calculate(&s));
return 0;
}