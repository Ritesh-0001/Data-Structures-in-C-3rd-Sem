#include <stdio.h>  
int fact (int);  
int main()               //main function
{  
	int n,f;  
	printf("Enter the number whose factorial you want to calculate:\n");  
	scanf("%d",&n);  
	f = fact(n);         //function calling
	printf("factorial = %d",f);  
}  
int fact(int n)          //function declaration
{  
	if (n==0)  
	{  
	    return 0;  
	}  
	else if ( n == 1)  
    {  
        return 1;  
	}  
    else   
	{  
        return n*fact(n-1);  
	}  
}  
