#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
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

    // now create a new node
    struct node* newnode =(struct node*)malloc(sizeof(struct node));
    newnode->data=40;
    newnode->next=NULL;
    int pos=2;
    struct node *temp = head;
    for(int i =1;i<pos-1;i++)
    {
        if(temp==NULL)
        {
            printf("The operation cannot be performd");
            return 0;
        }
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    printf("The data are %d,%d and %d",frstnode->data,scndnode->data,newnode->data);
    return 0;
}