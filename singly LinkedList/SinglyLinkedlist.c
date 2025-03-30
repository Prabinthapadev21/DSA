#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node NodeType;
NodeType *first,*last;
first=NULL;
last=NULL;
void insert_at_beginning(int);
void insert_given_position(int);
void insert_at_end(int);
void delete_at_beginning();
void delete_given_position();
void delete_at_end();
void delete_nth_node();
void info_sum();
void count_nodes();
void display();
int main()
{
    int choice;
    int item;
    do
    {
        printf("Menue for singly linked list:\n");
        printf("1.Insert at beginning\n 2.Insert at given position\n 3.Insert at end\n 4.Delete at beginning\n 5.Delete at given position\n 6.Delete at end\n 7.Delete nth node\n 8.Info sum\n 9.Count nodes\n 10.Display\n 11.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the value to insert:");
            scanf("%d",&item);
            insert_at_beginning(item);
            break;
            case 2:
            printf("Enter the value to insert:");
            scanf("%d",&item);
            insert_given_position(item);
            break;
            case 3:
            printf("Enter the value to insert:");
            scanf("%d",&item);
            insert_at_end(item);
            break;
            case 4:
            delete_at_beginning();
            break;
            case 5:
            delete_given_position();
            break;
            case 6:
            delete_at_end();
            break;
            case 7:
            delete_nth_node();
            break;
            case 8:
            info_sum();
            break;
            case 9:
            count_nodes();
            break;
            case 10:
            display();
            break;
            case 11:
            exit(0);
            break;
            default:
            printf("Invalid choice");
        }
    }while(choice!=11);
    return 0;
}
void insert_at_beginning(int item)
{
    NodeType *NewNode;
    NewNode=(NodeType*)malloc(sizeof(NodeType));
    if(first==NULL)
    {
        NewNode->next=NULL;
        first=NewNode;
        last=NewNode;
    }
    else
    {
        NewNode->next=first;
        first=NewNode;
    }
}
void insert_given_position(int item)
{
    int pos,i;
    NodeType *NewNode,*temp;
    NewNode->info=item;
    printf("Enter the position of node at which you want to insert a new node:");
    scanf("%d",&pos);
    if(first==NULL)
    {
       first=NewNode;
       last=NewNode;
    }
    else
    {
        temp=first;
        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        NewNode->next=temp->next;
        temp->next=NewNode;
    }
}
void insert_at_end(int item)
{
    NodeType *NewNode;
    NewNode=(NodeType*)malloc(sizeof(NodeType));
    NewNode->info=item;
    NewNode->next=NULL;
    if(first==NULL)
    {
        first=NewNode;
        last=NewNode;
    }
    else
    {
        last->next=NewNode;
        last=NewNode;
    }
}