#include <stdio.h>
#include<stdlib.h> 
#include<ctype.h>     /* for isdigit(char ) and isalpha(char )*/
#include<string.h>
#define N 100
char S[N];
int TOP = -1;



void PUSH(char ITEM)/* Function for pushing*/
    {
       if(TOP >= N-1)
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

char POP() 
    {
        char ITEM;
        
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
    
int oper(char symbol)
{
    if (symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-'||symbol == '('  || symbol == ')'   )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int priority(char symbol)
{
    if(symbol == '*' || symbol == '/')
	{
		return 2;
	}
	else if(symbol == '+' || symbol == '-')          
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void InToPost( char infix[N],char postfix[N])
{
   
    char ITEM,X;
    int i=0,j=0;
    
    PUSH('(');                               /* push '(' onto stack */
	strcat(infix,")");
   
    
    ITEM = infix[i];
    
    while (ITEM != '\0')
    {
        if (ITEM = '(')
        {
           PUSH(ITEM);
        }
        else if(ITEM == ')')         /* if current symbol is ')' then */
		{
			X=POP();                   /* pop and keep popping until '(' encounterd */
			while(X != '(')            
			{
				postfix[j] = X;
				j++;
				X = POP();
			}
		}
        else if(isdigit(ITEM) || isalpha(ITEM))
        {
            postfix[j]=ITEM;
            j++;
        }
        else if(oper(ITEM)==1)
        {
            X=POP();        /* get top element of stack as X*/
            while(oper(X)==1 && priority(ITEM)<= priority(X))  /* if top element is a symbol and its priority is greater than that of the ITEM */
            {
               
                postfix[j]=X;
                j++;
                 X = POP();
            }
            PUSH(X);
            PUSH(ITEM);
        }
       
		
		else
		{ /* not operand and not operator */
			printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
			getchar();
			exit(1);
		}
		
		i++;
		ITEM = infix[i]; 
       

    }
    if(TOP>0)
	{
		printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
		getchar();
		exit(1);
	}
	if(TOP>0)
	{
		printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
		getchar();
		exit(1);
	}

    
    postfix[j] = '\0'; 
    
}

int main()
{
   char infix[N],postfix[N];
   
    printf("Enter Infix Expression : ");
    gets(infix);
    
    
    InToPost(infix,postfix);
    
    
    printf("\nPostfix Expression = \n");
    puts(postfix);

    return 0;
}

