#include<stdio.h>
#include<stdlib.h>
int compare(char arr[10],char arr1[10]){
    int c1,c2;
    int i=0,j=0;
    while(arr[i]=='\0'){
        if(arr[i]==arr1[j]){
            i++;
            j++;
        }
        else{
            printf("\ncharacter %c != %c at index %d\n",arr[i],arr1[j],i+1);
            j--;
            break;
        }

    }
    if(i==j){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    char wrd1[10],wrd2[10];
    printf("Enter the  1st word to compare: ");
    scanf("%s",wrd1);
    printf("Enter the 2nd word to compare: ");
    scanf("%s",wrd2);
    if(compare(wrd1,wrd2)==1){
        printf("Two words are matched.");
    }
    else{
        printf("One word is not matched.");
    }

return 0;
}