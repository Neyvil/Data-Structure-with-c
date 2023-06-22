#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 100
struct eval{
    int stack[max];
    char postfix[max];
    int top;
};
typedef struct eval ev;
int isFull(ev *s){
     if(s->top==max-1)
         return 1;
        else
         return 0;
}
void push(ev *s,char symbol){
    if(isFull(s)){
        printf("STACK OVERFLOW");
    }
    else{
        s->top=s->top+1;
        s->stack[s->top]=symbol;
    }
}
int isEmpty(ev *s){
     if(s->top<=-1){
        return 1;
     }
     else{
        return 0;
     }
}
 char pop(ev *s){
    char c;
    if(isEmpty(s)){
        printf("Stack underflow");
        return 1;
    }
    c=s->stack[s->top];
    s->top--;
    return c;

 }
 int calculate(ev *s){
    int i;
    char t;
    for(i=0;i<strlen(s->postfix);i++){
         t=s->postfix[i];
         if(t>='0'&& t<='9')
           push (s,t-'0');
         else{
            int a1=pop(s);
            int a2=pop(s);
            switch(t){
                case '+':
                     push(s,a2+a1);
                     break;
                case '-':
                    push(s,a2-a1);
                    break;
                case '*':
                     push(s,a2*a1);
                     break;
                case '/':
                    push(s,a2/a1);
                    break;
                case '^':
                    push(s,pow(a2,a1));
                    break;
            }
         }
    }
    return pop(s);
 }

int main(){
    ev s;
    s.top=-1;
    printf("Enter postfix expression: ");
    scanf("%s",s.postfix);
    for(int i=0;i<strlen(s.postfix);i++)
         printf("%c",s.postfix[i]);
    printf("\nThe answer is:%d",calculate(&s));
    return 0;
}
