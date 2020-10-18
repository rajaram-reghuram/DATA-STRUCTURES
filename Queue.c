#include<stdio.h>
#include <stdlib.h>
int Q[20],REAR=-1, FRONT =-1; // Global Declaration

/*Function for Insertion */
void QINSERT(int N,int ITEM)
    {
        if (REAR== N-1 )
            {
                printf("\nQUEUE FULL\n");
            }
        else
            {
                if (FRONT==-1)// if queue is intially empty
                    {
                        FRONT = 0;
                    }
                    
                printf("\n INSERT the element in the queue:\t");
                scanf("%d",&ITEM);   
                REAR = REAR +1;  // increment REAR value
                Q[REAR] = ITEM;
                
                
                
            }
            
    }

/*Function for Deletion */

int QDELETE(int ITEM) 
    {
        
        if (FRONT == -1 || FRONT>REAR )
            {
                printf("\n\nQueue is Empty\n");
                return 0;
            }
        if (FRONT == REAR)
            {
                FRONT = REAR = -1;  
            }
        
        
        ITEM=Q[FRONT];
        FRONT++;
        
        
    }

/*Function for displaying*/
void DISPLAY()
    {
        int i;
        if (FRONT == -1 || FRONT>REAR )
            {
                printf("\n\nQueue is Empty\n");
                
            }
        else if(FRONT !=-1)
        {
            printf("\n\nThe elements in the queue are:\t");
            for (i=FRONT;i<=REAR;i++)
                {
                    printf("\n%d\t",Q[i]);
                }
            
        }
    }


void main()
    {
            int choice,N,ITEM;
            printf("\n ENTER THE NUMBER OF TERMS IN QUEUE\t");
            scanf("%d",&N);

    while (1)

    {

        printf("\n1.Insert element to queue \n");

        printf("2.Delete element from queue \n");

        printf("3.Quit \n");

        printf("Enter your choice : \t");

        scanf("%d", &choice);

        switch (choice)

        {

            case 1:
            
            QINSERT(N,ITEM);
            DISPLAY();
            break;

            case 2:

            QDELETE(ITEM);
            DISPLAY();
            break;

            case 3:

            exit(0);

            default:

            printf("Wrong choice \n");

        } 

    } 

}
    



