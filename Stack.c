#include <stdio.h>
#include<stdlib.h>
int S[20],TOP=-1;


void PUSH(int N,int ITEM)/* Function for pushing*/
    {
       if(TOP == N-1)
       {
        printf("\nStack is Full!!!\n");
       }
      else
     {
         printf("Enter the value to be insert: ");
		    scanf("%d",&ITEM);
      TOP++;
      S[TOP] = ITEM;
    }
}
/*Function for poping */

int POP(int ITEM) 
    {
        
       if (TOP == -1)
       {
        printf("\nStack is Empty!!!\n");
       }
        else
        {
          printf("\nDeleted ITEM : %d\n", S[TOP]);
          TOP--;
        }
    }

/*Function for displaying*/
void DISPLAY()
    {
        int i,N;
        
        if (TOP == -1)
        {
            printf("\nStack is Empty!!!\n");
        }
      else
        {
            
            printf("\nStack elements are:\n");
            for(i=TOP; i>=0; i--)
                {
	                printf("%d\n",S[i]);
                }
        }
    }

void main()
{
   int ITEM,N,choice;
   
            printf("\n ENTER THE NUMBER OF TERMS IN STACKS\t");
            scanf("%d",&N);
   
   while(1)
   {
      
      printf("\n1. Push\n2. Pop\n3. Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&choice);
      switch(choice)
    {
	    case 1: 
	        
		    PUSH(N,ITEM);
		    DISPLAY();
		     break;
	    case 2: 
	        POP(ITEM);
	        DISPLAY();
		    break;
	    case 3:   
	        exit(0);
	     
	    default: printf("\nWrong selection!!!\n");
   }
      
 }

}

