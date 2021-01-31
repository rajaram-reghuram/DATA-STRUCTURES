#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10

int deque[MAX];
int FRONT=0, REAR=0,ahead=0;


int insert_rear()
{
    int ITEM;
    
 if ((FRONT==1 && REAR== MAX) || (FRONT==REAR+1))   
         {
            printf("\nQUEUE FULL\n");
           return 0;
        }
         
          printf("\nEnter the value to be inserted IN REAR\t");
          scanf("%d",&ITEM);
         
        if (FRONT==0 && REAR==0)
            {
                FRONT=1;
                REAR=1;
            }
        else
        {
          
                REAR = REAR +1;  // increment REAR value
        }
        
             deque[REAR] = ITEM;         
         
}


void insert_front()
{
 int ITEM;
 
      printf("\nEnter the value to be inserted in FRONT ");
      scanf("%d",&ITEM);
         
       if(FRONT==1)
        ahead=MAX;
         
     else
      {
        if( FRONT==0 || FRONT==MAX) 
           ahead=1;
        else
           ahead=FRONT-1;
      }
      
        
      
     if((ahead==1 && REAR==MAX) || (ahead==FRONT+1)) 
      
        printf("Queue overflow");
     else
      {
        FRONT=ahead;
        deque[FRONT]=ITEM; 
          
      }

        
    
}

int delete_rear()
{
    int ITEM;
    if(FRONT==0 )
     {
       
      
       printf("Queue Underflow \n");
       return 0;
       
     }
     else 
      {
        if(FRONT==REAR)
         {
          ITEM=deque[REAR];
          FRONT=REAR=0;
         }
      
        else 
         {
          if(REAR=1)
           {
             ITEM=deque[REAR];
             REAR=MAX;
           }
          else
           {
            if(REAR==MAX)
              {
                 ITEM=deque[REAR];
                 REAR=1;
              }
            else
              {  ITEM=deque[REAR];
                 REAR=REAR-1;
              }
           }
         }
          
       
    
        if(ITEM!=0)
          {
           printf("The deleted element is %d\n",ITEM) ;
          }
      }
}

void delete_front()
{
    int ITEM;
    
 if(FRONT==0)
    {
        printf("\nUNDERFLOW");
        return;
    }
    
 printf("\nThe deleted element is %d\n", deque[FRONT]);
 
 if(FRONT==REAR)         
     {
         FRONT=0;
         REAR=0;
     }
 else
    {
        if(FRONT==MAX-1)
            FRONT=1;
        else
            FRONT=FRONT+1;
    }
    
    if(ITEM!=0)
          {
           printf("The deleted element is %d\n",ITEM) ;
          }
}



void display()
{
 
  int i;
        if (FRONT ==0)
            {
                printf("\n\nQueue is Empty\n");
            }
        if (FRONT<=REAR)
        {
            printf("\n\nThe elements in the queue are:\n");
            for (i=FRONT;i<=REAR;i++)
                {
                    printf("\n%d\t",deque[i]);
                }
        }
        else
        {
            for(i=FRONT;i<= MAX;i++)
            {
               printf("\n%d\t",deque[i]); 
            }
            
            
        }
    printf("\n");
    
}




void main()
{
    
 int choice;
 
 while(1)
 
 {
  printf("\n1.Insert at rear ");
  
  printf("\n2.Insert at front ");
  
  printf("\n3.Delete from rear ");
  
  printf("\n4.Delete from front ");
  
  printf("\n5.Display the final queue ");
  
  printf("\n6.Exit");
  
  printf("\n\nEnter your choice ::\t");
  
  scanf("%d",&choice);
  
  switch(choice)
  {
   case 1:
    insert_rear();
    display();
    break;
    
   case 2:
    insert_front();
    display();
    break;
    
   case 3:
    delete_rear();
    display();
    break;
    
   case 4:
    delete_front();
    display();
    break;
  
  case 5:
    display();
    break;
    
    case 6:
    exit(0);
     
    default :
    printf("\n!! Wrong choice !!\n");
  }


 }
}
