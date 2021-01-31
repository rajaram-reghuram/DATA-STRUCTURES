#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define N 100

int TOP = -1;
char S[N];

void PUSH(char ITEM)
{
	if(TOP >= N-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		TOP = TOP+1;
		S[TOP] = ITEM;
	}
}

char POP()
{
	char ITEM ;

	if(TOP <0)
	{
		printf("\nStack Underflow!");
		exit(1);
	}
	else
	{
		ITEM = S[TOP];
		TOP = TOP-1;
		return(ITEM);
	}
}

int oper(char op)
{
	if(op == '*' ||  op == '/' || op == '+' || op == '-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int precedence(char op)
{
	if(op == '*' || op == '/')
	{
		return 2;
	}
	else if(op == '+' || op == '-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void infixToPostfix(char infix[], char postfix[])
{
	char X, ITEM;
	int i = 0, j = 0;
	PUSH('(');
	strcat(infix, ")");
	ITEM = infix[i];
	while(ITEM != '\0')
	{
		if(ITEM == '(')
		{
			PUSH(ITEM);
		}
		else if(isdigit(ITEM) || isalpha(ITEM))
		{
			postfix[j] = ITEM;
			j++;
		}
		else if(oper(ITEM) == 1)
		{
			X = POP();
			while(oper(X) == 1 && precedence(ITEM) <= precedence(X))
			{
				postfix[j] = X;
				j++;
				X = POP();
			}
			PUSH(X);
			PUSH(ITEM);
		}
		else if(ITEM == ')')
		{
			X = POP();
			while(X != '(')
			{
				postfix[j] = X;
				j++;
				X = POP();
			}
		}
		else
		{
			printf("\nInvalid expression!");
			exit(1);
		}
		i++;
		ITEM = infix[i];
	}
	postfix[j] = '\0';
}

int main()
{
	char infix[N], postfix[N];
	printf("Enter infix expression: ");
	gets(infix);
	infixToPostfix(infix, postfix);
	printf("\nPostfix expression is   %s", postfix);
	return 0;
}
