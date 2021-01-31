#include <stdio.h>

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


int main()
{
   int list[100],size,i;
    
    printf("Enter the size of the List: \t");
    scanf("%d",&size);

    printf("Enter %d integer values: \n",size);
        for(i=0; i<size; i++)
            scanf("%d",&list[i]);
            
    mergesort(list,0,size-1);
            printf("Sorted elements: using merge sort is :: ");
            for(i=0;i<size;i++)
            {
                printf(" %d",list[i]);  
            }    
}
