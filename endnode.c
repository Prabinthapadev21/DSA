#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
int main()
{
    struct node *frstnode = (struct node*)malloc(sizeof(struct node));
    frstnode->data=20;
    frstnode->next=NULL;
    struct node * head;
    head = frstnode;
    struct node* scndnode =(struct node*)malloc(sizeof(struct node));
    scndnode->data=30;
    scndnode->next=NULL;
    frstnode->next=scndnode;

    struct node *temp;
    temp = head;
    struct node *last = (struct node*)malloc(sizeof(struct node));
    last->data=40;
    last->next=NULL;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next=last;

    printf("The data are %d,%d and %d",frstnode->data,scndnode->data,last->data);
}