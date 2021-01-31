#include <stdio.h>
#include <ctype.h>

#define N 100 

int S[N];
int TOP = -1;

void PUSH(int ITEM)/* Function for pushing*/
    {
       if(TOP >= N-2)
       {
        printf("\nStack is Full!!!\n");
       }
      else
     {
      TOP++;
      S[TOP] = ITEM;
    }
}
/*Function for poping */

int POP() 
    {
        int ITEM;
        
       if (TOP < 0)
       {
        printf("\nStack is Empty!!!\n");
        
       }
        else
        {
            ITEM=S[TOP];
            TOP--;
            return ITEM;
        }
    }
    
void EvalPostfix(char postfix[])
{

    int i;
    char ch;
    int val;
    int A, B;

    /* evaluate postfix expression */
    for (i = 0; postfix[i] != ')'; i++) 
    {
        ch = postfix[i];
        if (isdigit(ch))
        {
            
           PUSH(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') 
        {
           
            A = POP();
            B = POP();

            switch (ch)                          /* ch is an operator */
            {
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            }

            
            PUSH(val);             /* push the value obtained above onto the stack */
        }
    }
    printf(" \n Result of expression evaluation : %d \n", POP());
}

int main()
{

    int i;

    
    char postfix[100];
   
    printf("\nEnter postfix expression,\npress right parenthesis ')' for end expression : ");

  

    for (i = 0; i <= 100 - 1; i++) 
    {
        scanf("%c", &postfix[i]);

        if (postfix[i] == ')')
        {
            break;
        } 
    }

    

    EvalPostfix(postfix);

    return 0;
}    
