#include <stdio.h>

int selectionsort(int list[100],int size)
{
     int i,j,temp,min;

    for(i=0; i<size-1; i++)
    {
      min=i;
      for(j=i+1;j<size;j++)
      {
          if(list[j]<list[min])
          {
              min=j;
          }
      }
               temp=list[i];
               list[i]=list[min];
               list[min]=temp;
        
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
            
    selectionsort(list,size);
            printf("Sorted elements: using selection sort is :: ");
            for(i=0;i<size;i++)
            {
                printf(" %d",list[i]);  
            }    
}
