//program for conversion to expression from infix to postfix.

#include<stdio.h>
#include<stdlib.h>
char stack[20];
int top=-1;
void push(char x)           //function push has been initiated
{
    stack[++top]=x;
}
char pop()                   //function pop has been initiated
{
    if(top==-1)
        return 1;
    else{
        return stack[top--];
    }
}
int priority(char x)
{
    if(x=='(')
        return 0;
    if(x=='+' || x=='-')
        return 1;  
    if(x=='*' || x=='/')
        return 2;    
}
void main()                    //Main function
{
    char exp[20];
    char *e,x;
    printf("Enter the expression\n");
    scanf("%s",exp);
    e=exp;
    while(*e!='\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e=='(')
            push(*e);
        else if(*e==')')
        {
            while((x=pop())!='(')
                printf("%c",x);
        }
        else
        {
            while(priority(stack[top])>=priority(*e))
                printf("%c",pop());
                push(*e);

        }
        e++;
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }
    }