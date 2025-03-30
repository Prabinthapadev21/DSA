#include<stdio.h>
#include<stdlib.h>
#define Size 4
void push();
void pop();
void display();
int top=-1,stack[Size],choice,n,value;
int main()
{
    printf("Enter the number of the elements allowed in the stack:\n");
    scanf("%d",&n);
    if(n>Size)
    {
        printf("Size excedded so setting the number to the max size:");
        n=Size;
    }
printf("Performing the push and pop operation in stack:\n");
printf("************************************\n");

while(1)
{
    printf("\nChoose one from the below options:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            case 4:
            printf("Exiting the program:\n");
            exit(0);
            default:
            printf("Please enter the correct options....\n");
            break;
        }
}
}
void push()
{
    if(top==n-1)
    {
        printf("The stack is in overflow condition.\n");
    }
    else
    {
        printf("Enter the value to push in the stack:");
        scanf("%d",&value);
        stack[top++]=value;
    }
     printf("%d is pushed into the stack",value);
}
void pop()
{
    if(top==-1)
    {
        printf("The stack is in underflow condition....\n");

    }
    else
    {
        printf("The popped element from the stack is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top==-1)
    {
        printf("The stack is empty so value cannot be displayed...\n");
    }
    else
    {
        printf("The elements in the stack are......\n");
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}