#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char str[]="Hello";
    char str1[]=" KOMLAKSH";
    int i,total;
    
    total=strlen(str)+strlen(str1);
    char str2[total];
    for(i=0;i<strlen(str);i++){
      str2[i]=str[i];
    }
    for(i=strlen(str);i<total;i++){
        str2[i]=str1[i-strlen(str)];
    }
    for(i=0;i<total;i++){
        printf("%c",str2[i]);
    }
return 0;
}