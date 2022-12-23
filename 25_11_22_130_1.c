//Implementation of stack using Array.

#include<stdio.h>
#include<stdlib.h>
#define size 10
int top=-1;
int arr[size];
void push();
void pop();
void show();
int main()                     //Main funcction
{
    int choice;
    while(1)
    {
        printf("Select the operation\n");
        printf("1.push\n 2.pop\n 3.show\n 4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();
                    break;
            case 2:pop();
                    break;
            case 3:show();
                    break;
            case 4:exit(0);
            default:printf("Invalid\n");                        
        }
    }
}
void push()                    //Push declaration
{
    int n;
    if(top==size-1)
    {
        printf("Outflow\n");
    }
    else
    {
        printf("Enter the element\n");
        scanf("%d",&n);
        top++;
        arr[top]=n;
    }
}
void pop()                    //Pop declaration
{
    if(top==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("deleted element is %d\n",arr[top]);
        top--;
    }
}
void show()                   //Show declaration
{
    int i;
    if(top!=-1)
    {
        for(int i=0;i<=top;i++)
        {
            printf("%d\t",arr[i]);
        }
    }
    else
    {
        printf("No element is present\n");
    }
}