#include <stdio.h>

int quicksort(int list[100],int first,int last)
{
  
  int pivot,i,j,temp;
  
  

     if(first < last)
     {
         pivot = first;
         i = first;
         j = last;

         while(i < j)
         {
             while(list[i] <= list[pivot] && i < last)
                 i++;
             while(list[j] > list[pivot])
                 j--;
             if(i <j)
             {
                  temp = list[i];
                  list[i] = list[j];
                  list[j] = temp;
             }
         }

         temp = list[pivot];
         list[pivot] = list[j];
         list[j] = temp;
         quicksort(list,first,j-1);
         quicksort(list,j+1,last);
         
     }
  
}


int main()
{
    int list[100],size,i;
    
    printf("Enter the size of the List: \t");
    scanf("%d",&size);

    printf("Enter %d integer values: \n",size);
        for(i=0; i<size; i++)
            scanf("%d",&list[i]);
            
    quicksort(list,0,size-1);
            printf("Sorted elements: using selection sort is :: ");
            for(i=0;i<size;i++)
            {
                printf(" %d",list[i]);  
            }    
}

