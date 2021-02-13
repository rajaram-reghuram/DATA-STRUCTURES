#include<stdio.h>  
#include<stdlib.h>  

struct node   
{  
    int data;  
    struct node *link;   
};  
struct node *head;  
  
void display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nUNDERFLOW");  
    }  
    else  
    {  
        printf("\nprinting values . . . . .\n");   
        while (ptr!=NULL)  
        {  
            printf("\n%d",ptr->data);  
            ptr = ptr -> link;  
        }  
    }  
}
void begin_insert()  
{  
    struct node *ptr;  
    int item;  
    ptr = (struct node *) malloc(sizeof(struct node *));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter value\t");    
        scanf("%d",&item);    
        ptr->data = item;  
        ptr->link = head;  
        head = ptr;  
        printf("\nNode has been inserted at beginning");  
    }  
      
}  
void last_insert()  
{  
    struct node *ptr,*temp;  
    int item;     
    ptr = (struct node*)malloc(sizeof(struct node));      
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        printf("\nEnter value?\t");  
        scanf("%d",&item);  
        ptr->data = item;  
        if(head == NULL)  
        {  
            ptr -> link = NULL;  
            head = ptr;  
            printf("\nNode has been inserted at the last");  
        }  
        else  
        {  
            temp = head;  
            while (temp -> link != NULL)  
            {  
                temp = temp -> link;  
            }  
            temp->link = ptr;  
            ptr->link = NULL;  
            printf("\nNode has been inserted at the last");  
          
        }  
    }  
}  
void random_insert()  
{  
    int i,loc,item;   
    struct node *ptr, *temp;  
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter element value\t");  
        scanf("%d",&item);  
        ptr->data = item;  
        printf("\nEnter the location after which you want to insert ");  
        scanf("\n%d",&loc);  
        temp=head;  
        for(i=0;i<loc;i++)  
        {  
            temp = temp->link;  
            if(temp == NULL)  
            {  
                printf("\ncan't insert\n");  
                return;  
            }  
          
        }  
        ptr ->link = temp ->link;   
        temp ->link = ptr;   
        printf("\nNode has been inserted at random location");  
    }  
}  
void begin_delete()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else   
    {  
        ptr = head;  
        head = ptr->link;  
        free(ptr);  
        printf("\nNode deleted from the begining ...\n");  
    }  
}  
void last_delete()  
{  
    struct node *ptr,*ptr1;  
    if(head == NULL)  
    {  
        printf("\nlist is empty");  
    }  
    else if(head -> link == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("\nOnly node of the list deleted ...\n");  
    }  
          
    else  
    {  
        ptr = head;   
        while(ptr->link != NULL)  
        {  
            ptr1 = ptr;  
            ptr = ptr ->link;  
        }  
        ptr1->link = NULL;  
        free(ptr);  
        printf("\nDeleted Node from the last ...\n");  
    }     
}  
void random_delete()  
{  
    struct node *ptr,*ptr1;  
    int loc,i;    
    printf("\n Enter the location of the node after which you want to perform deletion \n");  
    scanf("%d",&loc);  
    ptr=head;  
    for(i=0;i<loc;i++)  
    {  
        ptr1 = ptr;       
        ptr = ptr->link;  
              
        if(ptr == NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    ptr1 ->link = ptr ->link;  
    free(ptr);  
    printf("\nDeleted node %d ",loc+1);  
}  




void main ()  
{  
    int choice;  
    while(1)   
    {
        printf("\n\n");  
        printf("\n1.Insert in begining");
        printf("\n2.Insert at last");
        printf("\n3.Insert at any random location");
        printf("\n4.Delete from Beginning");
        printf("\n5.Delete from last");
        printf("\n6.Delete node after specified location");
        printf("\n7.Show");
        printf("\n8.Exit\n");  
        printf("\nEnter your choice?\t");         
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1: 
            
                begin_insert();      
                break;  
            case 2: 
            
                last_insert();         
                break;  
            case 3:  
            
                random_insert();       
                break;  
            case 4: 
            
                begin_delete();       
                break;  
            case 5:  
            
                last_delete();        
                break;  
            case 6: 
            
                random_delete();          
                break; 
            case 7:  
            
                display();        
                break;  
            case 8:  
            
                exit(0);  
                break;  
                
            default:  
                printf("Please enter valid choice..");  
        }  
    }  
}  
