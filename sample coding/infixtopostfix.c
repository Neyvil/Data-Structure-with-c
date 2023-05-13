#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100

typedef struct eversion{
     char stack[size];
     char infix[size];
     char postfix[size];
     int top;
}ev;
int isFull(ev *s){
     if(s->top==size-1)
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

int precedence(char symbol){
   switch(symbol){
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default: return 0;
   }

}

void print(ev *s){
    int i=0;
    printf("The equivalent postfix expression is: ");
    while(s->postfix[i]){
        printf("%c",s->postfix[i++]);
    }
    printf("\n");
}

void intopost(ev *s){
    int i,j=0;
    char symbol,next;
    for(i=0;i<strlen(s->infix);++i){
        symbol=s->infix[i];
        switch(symbol){
            case '(':
               push(s,symbol);
               break;
            case ')':
               while((next=pop(s))!='(')
                 s->postfix[j++]=next;
               break;
            case '+':
            case '-':
            case '*':
            case '/':
            case'^':
               while(!isEmpty(s) && precedence(s->stack[s->top])>=precedence(symbol))
                s->postfix[j++]=pop(s);
               push(s,symbol);
               break;
               
            default:
                s->postfix[j++]=symbol;

        }
    }
    while(!isEmpty(s))
        s->postfix[j++]=pop(s);
    
    s->postfix[j]='\0';
}

int main(){
    ev s;
    s.top=-1;
    printf("Enter infix expression: ");
    scanf("%[^\n]s",s.infix);
    intopost(&s);
    print(&s);

return 0;
} 
