#include <stdio.h>

int insertionsort(int list[100],int size)
{
    int  i, j, temp;
 
  
   for (i = 1; i < size; i++)
   {
      temp = list[i];
      j = i - 1;
      while ((temp < list[j]) && (j >= 0)) 
      {
         list[j + 1] = list[j];
         j = j - 1;
      }
      
      list[j + 1] = temp;
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
            
    insertionsort(list,size);
            printf("Sorted elements: using indertion sort is :: ");
            for(i=0;i<size;i++)
            {
                printf(" %d",list[i]);  
            }         
}

