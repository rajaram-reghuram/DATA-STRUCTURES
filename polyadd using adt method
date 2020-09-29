#include <stdio.h>
#define MAX_TERMS 100;
                    // Create the userdefined ADT
struct Polynomial
    {
        int coef;
        int expon;
    };
    
struct Polynomial t[100];
int avail = 0;

       //Add a new term to the polynomial
void attach (int coefficient, int exponent)
{
            
if (avail >= 100)
    {
        printf("Too many terms in the polynomial");
    }
else
    {
        t[avail].coef = coefficient;
        t[avail].expon = exponent;
        avail++;
    }
}

                //Function to compare two exponents
int compare(int exp_a, int exp_b)
                // Returns values 0, 1 or -1 based on comparison
{
    if (exp_a > exp_b)
        return 0;
    else if(exp_a == exp_b)
        return 1;
    else
        return -1;
}


// Function to perform polynomial addition
int polyadd (int starta, int finisha, int startb, int finishb, int startc, int finishc)
{
// Add twp polynomials a(x) and b(x) and return c(x)
int i;
int coefficient;

while(starta <= finisha && startb <=finishb)
{
    switch(compare(t[starta].expon,t[startb].expon))
    {
        case 0:
        attach(t[starta].coef, t[starta].expon);
        starta++;
        break;
        case 1:
        coefficient = t[starta].coef + t[startb].coef;
        attach(coefficient,t[starta].expon);
        starta++;
        startb++;
        break;
        case -1:
        attach(t[startb].coef, t[startb].expon);
        startb++;
        break;
        
    }
    
     //To add the remaining terms of a(x)
    for(;starta<=finisha;starta++)
    attach(t[starta].coef,t[starta].expon);
    for(;startb<=finishb;startb++)
    attach(t[startb].coef,t[startb].expon);
    finishc = avail-1;


}

}


void display(int start,int finish)
{
  int i;
  for(i=start;i<=finish;i++)
  {
      printf(" (%d X^%d) +",t[i].coef,t[i].expon);
  }
printf(" (%d X^%d)",t[i].coef,t[i].expon);
}
int main()
{

     
 int numa, numb, starta, finisha, startb, finishb, startc, finishc;
 
 /* FOR a(x) */
 printf("Enter the number of terms of polynomial a(x):"); // takes polynomial a(x)
 scanf("%d",&numa);
 
 starta=avail;
 for(avail;avail<numa;avail++)
 {
 
    //entering values in coefficient of the polynomial terms
    printf("\nEnter the coeffient of term %d :",avail+1);
    scanf("%d",&t[avail].coef);
    
    printf("\nEnter the exponent of term %d :",avail+1);
    scanf("%d",&t[avail].expon);
	
 }
 finisha=avail-1;
 
 /* FOR b(x) */
 startb=avail;
 printf("Enter the number of terms of polynomial b(x):"); // takes polynomial b(x)
 scanf("%d",&numb);
 
 
 for(startb=avail;avail<startb+numb;avail++)
    {
 
    //entering values in coefficient of the polynomial terms
    printf("\nEnter the coeffient of term %d :",avail - finisha);
    scanf("%d",&t[avail].coef);
    
    printf("\nEnter the exponent of term %d :",avail - finisha);
    scanf("%d",&t[avail].expon);
	
    }
finishb=avail-1;

/*for printing the result*/
startc=avail;

finishc=polyadd(starta,finisha,startb,finishb,avail,avail);

printf("\n\n Polynomial a(x) :");
display(starta,finisha);      // to display the polynomial
printf("\n\n Polynomial b(x) :");
display(startb,finishb);
printf("\n\n Resultant Polynomial is :");
display(startc,finishc);    // to display the sum of polynomials
}
