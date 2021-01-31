#include<stdio.h> 
  
void main() 
{ 
    
    int SparseMatrix[4][5] = {   {0 , 0 , 13 , 0 , 4 }, {0 , 0 , 15 , 27 , 0 }, {0 , 0 , 0 , 0 , 1 }, {0 , 1 , 7 , 0 , 0 } }; 
  
    int size = 0; 
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++) 
        {
            if (SparseMatrix[i][j] != 0) 
            {
                size++; 
            }
        }
    }
  
    
    int CompactMatrix[3][size]; 
  
   
    int k = 0; 
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            if (SparseMatrix[i][j] != 0) 
            { 
                CompactMatrix[0][k] = i; 
                CompactMatrix[1][k] = j; 
                CompactMatrix[2][k] = SparseMatrix[i][j]; 
                k++; 
            } 
        }
    }
    printf("\nCompact  Matrix\n\n");
    for (int i=0; i<3; i++) 
    { 
        for (int j=0; j<size; j++) 
        {
            printf("%d ", CompactMatrix[i][j]); 
        }
  
        printf("\n"); 
    } 
    
} 
