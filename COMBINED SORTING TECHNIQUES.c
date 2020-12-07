#include <stdio.h>
#include <stdlib.h>

int bubblesort(int list[100],int size)
{
   int temp, i, j;

 
   for(i=size-2;i>=0;i--)
   {
      for(j=0;j<=i;j++)
      {
        if(list[j]>list[j+1])
        {
           temp=list[j];
           list[j]=list[j+1];
           list[j+1]=temp;
        }
      }
   }
   

   
}

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

void merge(int list[100],int left,int mid,int right)
{
    int i=left,k=left,c[100];
     int j=mid+1,m;
     
     while(i<=mid && j<=right)
      {
          if(list[i]<=list[j])
          {
           c[k]=list[i];
           i++;
           k++;
          }
         else
          {
           c[k]=list[j];
           j++;
           k++;
          }
          
      }
    
      if(i>mid && j<=right)
       {
            for(m=j;m<=right;m++)
             {
                 c[k]=list[m];
                 k++;
                 j++;
             }
                 
             
       }
      else
       {
           if(i<=mid && j>right)
            {
                for(m=i;m<=mid;m++)
                {
                    c[k]=list[m];
                    k++;
                    i++;
                }
            }
        }
     for(i = left; i <= right; i++)
        {
                  list[i] = c[i];
       
        }
}

int mergesort(int list[100],int left,int right)
 {
     
     if(right<=left)
     {
         return;
     }
       
      else
      {
          int mid=(left+right)/2;
          mergesort(list,left,mid);
          mergesort(list,mid+1,right);
          merge(list,left,mid,right);  
          
      }
       
}

void heapify(int list[100], int size, int i) 
{
    
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < size && list[left] > list[largest])
      largest = left;
  
    if (right < size && list[right] > list[largest])
      largest = right;
  
    
    if (largest != i) 
    {
        int temp;
        temp = list[i];
        list[i] = list[largest];
        list[largest] = temp;
        heapify(list, size, largest);
    }
  }
  

void heapsort(int list[100], int size)
{
    
    for (int i = size / 2 - 1; i >= 0; i--)
      heapify(list, size, i);
  
   
    for (int i = size - 1; i >= 0; i--) 
    {
        int temp; 
        
      temp = list[0];
      list[0] = list[i];
      list[i] = temp;
      
      heapify(list, i, 0);
    }
  }

int main()
{
    int list[100],size,i,choice;
    
    printf("Enter the size of the List: \t");
    scanf("%d",&size);

    printf("Enter %d integer values: \n",size);
        for(i=0; i<size; i++)
            scanf("%d",&list[i]);
            
    printf("The elements in the array are ::: \t");
    for(int i=0;i<size;i++)
     {
         printf("%d\t ",list[i]);
     }
     
    printf("\n\n ************** SELECT SORTING TECHNIQUE ********************* \n\n ");
    
        printf("\n1.BUBBLE SORT \n");

        printf("2.INSERTION SORT\n");

        printf("3.SELECTION SORT \n");
        
        printf("4.QUICK SORT \n");
        
        printf("5.MERGE SORT \n");
        
        printf("6.HEAP SORT \n");
        
        printf("7.EXIT \n");

        printf("Enter your choice : \t");

        scanf("%d", &choice);

        switch (choice)

        {

            case 1:
            bubblesort(list,size);
            printf("Sorted elements: using bubble sort is :: ");
            for(i=0;i<size;i++)
            {
                printf(" %d",list[i]);  
            }      
       
            
            break;

            case 2:
            insertionsort(list,size);
            printf("Sorted elements: using indertion sort is :: ");
            for(i=0;i<size;i++)
            {
                printf(" %d",list[i]);  
            }      
       
            break;

            case 3:
            selectionsort(list,size);
             printf("Sorted elements: using selection sort is :: ");
            for(i=0;i<size;i++)
            {
                printf(" %d",list[i]);  
            }      
       
            break;
            
            case 4:
            quicksort(list,0,size-1);
             printf("Sorted elements: using quick sort is :: ");
            for(i=0;i<size;i++)
            {
                printf(" %d",list[i]);  
            }      
       
            break;
            
            case 5:
            mergesort(list,0,size-1);
            printf("Sorted elements: using merge sort is :: ");
            for(i=0;i<size;i++)
            {
                printf(" %d",list[i]);  
            }    
            
            break;
            
            case 6:
            heapsort(list,size);
            printf("Sorted elements: using heap sort is :: ");
            for(i=0;i<size;i++)
            {
                printf(" %d",list[i]);  
            }    
            
            break;


            case 7:
            
            exit(0);

            default:

            printf("Wrong choice \n");
            
         } 
     
   
}


