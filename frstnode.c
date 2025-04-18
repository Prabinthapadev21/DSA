#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node * head = (struct node*)malloc(sizeof(struct node));
    // for 1st node 
    head->data=10;
    head->next=NULL;
    //for 2nd node
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=20;
    newnode->next=NULL;
    //to point head with newnode
    head->next=newnode;
    printf("The data is %d and address is %p",head->data,head->next);
    printf("The data is %d and address is %p",newnode->data,newnode->next);
    return 0;
}