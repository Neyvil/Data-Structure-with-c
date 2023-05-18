#include<stdio.h>  
#include<stdlib.h>  
void create(int);  
void traverse();  
struct node  
{  
    int data;  
    struct node *next;  
};  
struct node *head;  
void main ()  
{  
    int choice,item;  
    do   
    {  
        printf("1.Append List\n2.Traverse\n3.Exit\n4.Enter your choice?");  
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            printf("\nEnter the item\n");  
            scanf("%d",&item);  
            create(item);  
            break;   
            case 2:  
            traverse();  
            break;   
            case 3:  
            exit(0);  
            break;    
            default:  
            printf("\nPlease enter valid choice\n");  
        }  
                  
    }while(choice != 3);  
}  
void create(int item)    
{    
        
    struct node *ptr = (struct node *)malloc(sizeof(struct node));    
    struct node *temp;  
    if(ptr == NULL)    
    {    
        printf("\nOVERFLOW");    
    }    
    else     
    {    
        ptr -> data = item;    
        if(head == NULL)    
        {    
            head = ptr;    
            ptr -> next = head;    
        }    
        else     
        {       
            temp = head;    
            while(temp->next != head)    
                temp = temp->next;    
            ptr->next = head;     
            temp -> next = ptr;     
            head = ptr;    
        }     
    printf("\nNode Inserted\n");  
    }    
                
}    
void traverse()  
{  
    struct node *ptr;  
    ptr=head;  
    if(head == NULL)  
    {  
        printf("\nnothing to print");  
    }     
    else  
    {  
        printf("\n printing values ... \n");  
          
        while(ptr -> next != head)  
        {  
          
            printf("%d\n", ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("%d\n", ptr -> data);  
    }  
              
}  