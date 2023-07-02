#include<stdio.h>
#include<stdlib.h>
int linearsearch(int arr[],int size,int e){
    for(int i=0;i<size;i++){
        if(arr[i]==e){
            return i;
        }
    }
    return -1;
}
int recursearch(int arr[],int start,int end,int e){
    
    if(start>end){
        return -1;
    }
    if(arr[start]==e){
        return start;
    }
    return recursearch(arr,start+1,end,e);
}
int main(){
    int arr[]={8,9,6,4,5,3,21,100,199,234,69};
    int size=sizeof(arr)/sizeof(arr[0]);
    int ele;
    printf("Enter element for searching: ");
    scanf("%d",&ele);
    int index=linearsearch(arr,size,ele);
    if (index != -1){
        printf("%d present at index %d",ele,index+1);
    }
    int index1=recursearch(arr,0,size-1,ele);
    if (index1 != -1){
        printf("\n%d present at index %d",ele,index1+1);
    }



return 0;
}