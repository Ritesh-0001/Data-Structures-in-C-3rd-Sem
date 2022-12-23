//program for conversion to expression from infix to prefix.

#include <stdio.h>
#include<string.h>
#include <ctype.h>
#define SIZE 50 

char stack[SIZE];
int top = -1;

void push(char element)            //function push has been initiated
{
    stack[++top] = element;
}

char pop()                          //function pop has been initiated
{
    return(stack[top--]);
}

int priority(char element)
{
    switch(element)
    {
        case '#': return 0;
        case ')': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
    }
}

int main()                                 //Main function
{
    char infix[50], prefix[50], ch, element;
    int i=0, j=0;
    printf("Enter the Infix Expression:\n");
    scanf("%s", infix);
    push('#');
    strrev(infix);
    while((ch = infix[i++]) != '\0')
    {
        if(ch == ')')
            push(ch);
        else
        {
            if(isalnum(ch))
                prefix[j++] = ch;
            else
            {
                if(ch == '(')
                {
                    while(stack[top] != ')')
                        prefix[j++] = pop();
                    element = pop();         // Remove ')'
                }
                else
                {       // Operator
                    while(priority(stack[top]) >= priority(ch))
                        prefix[j++] = pop();
                    push(ch);
                }
            }
        }
    }
    while(stack[top] != '#')     // Pop from stack till empty
        prefix[j++]=pop();
    prefix[j]='\0';          // Make prefix as valid string
    strrev(prefix);
    printf("Prefix Expression: %s", prefix);
}