#include<stdio.h>
#include<stdlib.h>
void insert();
void delete();
void update();
void traverse();
void merge();
int a[10],b[10],num,choice;
int main()
{
    printf("Enter the size of the array:");
    scanf("%d",&num);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < num; i++) {
        scanf("%d", &a[i]);
    }
    while(1)
    {
        printf("\nperforming the different operations in array......\n");
        printf("\n1.Insert\n2.Delete\n3.Update\n4.Traverse\n5.Merge\n6.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            update();
            break;
            case 4:
            traverse();
            break;
            case 5:
            merge();
            break;
            case 6:
            printf("Exiting the Program.....");
            exit(0);
            default:printf("Please enter the correct options......");
        }
    }
}
void insert()
{
    int pos,new_value;
    printf("Enter the positon to insert the new value:");
    scanf("%d",&pos);
    printf("Enter the value:");
    scanf("%d",&new_value);
    if(pos<=0 || pos>num+1)
    {
        printf("Envalid position........\n");
    }
    else
    {
        for(int i = num-1;i>=pos-1;i--)
        {
            a[i+1]=a[i];
        }
        a[pos-1]=new_value;
        num=num+1;
    }
}
void delete()
{
    int pos;
    printf("Enter the position to delete the value:");
    scanf("%d",&pos);
    if(pos<=0 || pos>num+1)
    {
        printf("Envalid position to perform the opertaiton..\n");
    }
    else
    {
        for(int i=pos-1;i<num-1;i++)
        {
            a[i]=a[i+1];
        }
        num=num-1;
    }
}
void update()
{
    int pos,value;
    printf("Enter the position to update the value:");
    scanf("%d",&pos);
    printf("Enter the value to update:");
    scanf("%d",&value);
    if(pos<=0 || pos>num+1)
    {
        printf("The operation cannot be performed..\n");
    }
    else
    {
        a[pos-1]=value;
    }
}
void traverse()
{
    printf("The elements in the list are:");
    for(int i=0;i<num;i++)
    {
        printf("%d\t",a[i]);
    }
}
void merge()
{
    int m;
    printf("Enter the Size of the second array:");
    scanf("%d",&m);
    printf("Enter the elements of the second array: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    //Merging the two arrays
    for(int i=0;i<m;i++)
    {
        a[num+i]=b[i];
    }
    num=num+m;
    //displaying the merge array
    printf("The merged array is:");
    for(int i =0;i<num;i++)
    {
        printf("%d\t",a[i]);
    }
}