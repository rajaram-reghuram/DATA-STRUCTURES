#include<stdio.h>
#include<stdlib.h>
#define N 50
int CQ[N],REAR=-1, FRONT =-1; // Global Declaration

/*Function for Insertion */
int CQINSERT(int ITEM)
    {
        if ((FRONT==-1 && REAR== N-1) || (FRONT==REAR+1))   
         {
            printf("\nCIRCULAR QUEUE FULL\n");
            return 0;
        }
         
          printf("\n INSERT the element in the circular queue:\t");
          scanf("%d",&ITEM);
         
        if (FRONT==-1 && REAR==-1)
            {
                FRONT=0;
                REAR=0;
            }
        else
        {
          if (REAR== N-1)
            {
                REAR=0;
            }
          else 
                REAR = REAR +1;  // increment REAR value
        }
        
             CQ[REAR] = ITEM;         
         
    }

/*Function for Deletion */

int CQDELETE(int ITEM) 
    {
        
        if (FRONT == -1 && REAR == -1)
            {
                printf("\n\nCircular Queue is Empty\n");
                return 0;
            }
          
        
        if (FRONT == N-1)
            {
                FRONT= 0;
                
            }
        else if(FRONT==REAR)
            {
                FRONT = REAR = -1;
            }
        else
        {
            printf("\nDELETED ITEM :\t %d\n",CQ[FRONT]);
            FRONT=FRONT+1;
        }
        
        return ITEM;
    }

/*Function for displaying*/
void DISPLAY()
    {
        int i;
        if (FRONT == -1)
            {
                printf("\n\nCircular Queue is Empty\n");
            }
        if (FRONT<=REAR)
        {
            printf("\n\nThe elements in the queue are:\n");
            for (i=FRONT;i<=REAR;i++)
                {
                    printf("\n%d\t",CQ[i]);
                }
        }
        else
        {
            for(i=FRONT;i<= N-1;i++)
            {
               printf("\n%d\t",CQ[i]); 
            }
            
            
        }
    }


void main()
    {
            int choice,ITEM;
            

    while (1)

    {

        printf("\n\n1.Insert element to queue \n");

        printf("2.Delete element from queue \n");

        printf("3.Quit \n");

        printf("Enter your choice :\t ");

        scanf("%d", &choice);

        switch (choice)

        {

            case 1:
            
                CQINSERT(ITEM);
                DISPLAY();
                break;

            case 2:

                CQDELETE(ITEM);
                DISPLAY();
                break;

            case 3:
            
                exit(0);

                
            default:

            printf("\n!! Wrong choice !!\n");

        } 

    } 

}
    
