#include<stdio.h>
#include<stdlib.h>
int main(){
char wrd[18];
printf("Enter the word: ");
scanf("%[^\n]s",wrd);
int i=0;
while(wrd[i]!='\0'){
    printf("%c\n",wrd[i]);
    i++;
}


return 0;
}