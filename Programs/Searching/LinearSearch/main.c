#include <stdio.h>
#include <stdlib.h>

int main()
{
    int LinearSearch(int arr[],int,int);
    int n,el,arr[20],res,i;
    printf("Enter size of array ");
    scanf("%d",&n);
    printf("Enter the elements of array \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the element to be searched ");
    scanf("%d",&el);

    res = LinearSearch(arr,n,el);
    if(res==-1)
        printf("Element not found");
    else
        printf("Element is found at index no. %d",res);
}

int LinearSearch(int arr[],int n,int el)
{
    int i;
    for(i=0;i<n;i++)
        if(arr[i]==el)
            return i;
    return -1;
}










