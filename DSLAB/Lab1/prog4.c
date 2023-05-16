#include<stdio.h>
#include<stdlib.h>

#define SPACE 32

int main(){
char wrd[18];
printf("Enter the word: ");
scanf("%[^\n]s",wrd);
long int i=0,k=0;
while(wrd[i]!='\0'){
    if(wrd[i]==9 || wrd[i]==SPACE){
        k--;
    }
    printf("%c\n", wrd[i]);
    i++;
    k++;
}
printf("The number of Alphabets: %ld",k);


return 0;
}