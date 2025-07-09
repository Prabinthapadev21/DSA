#include<stdio.h>
int binarysearch(int arr[],int key,int first,int last);
int main()
{
    int arr[5],key=4;
    int first=0;
    int last=4;
    printf("Enter the number of elements:");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&arr[i]);
    }
    int result = binarysearch(arr,key,first,last);
    if(result!=-1)
    {
        printf("The key found at index %d",result);
    }
    else
    {
        printf("The key not found at any index.");
    }
    return 0;
}
int binarysearch(int arr[],int key,int first,int last)
{
    if(first>last)
    {
        return -1;
    }
    int mid = (first+last)/2;

    if(arr[mid]==key)
    {
        return mid;
    }
    else if(key<arr[mid])
    {
        return binarysearch(arr,key,first,mid-1);
    }
    else
    {
        return binarysearch(arr,key,mid+1,last);
    }
}