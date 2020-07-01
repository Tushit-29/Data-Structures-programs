#include <stdio.h>
#include <stdlib.h>

int main()
{
    int BinarySearch(int arr[],int,int,int);
    int n,el,arr[20],res,i;

    printf("Enter size of array ");
    scanf("%d",&n);
    printf("Enter the elements of array in a sorted manner \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("Enter the element to be searched ");
    scanf("%d",&el);

    res = BinarySearch(arr,el,0,n-1);
    if(res==-1)
        printf("Element not found");
    else
        printf("Element is found at index no. %d",res);
}

int BinarySearch(int arr[],int el,int l,int u)
{
    int i;
    i=(l+u)/2;
    if(el==arr[i])
        return i;

    if(l==u)
        return -1;
    else if(el<arr[i])
        BinarySearch(arr,el,l,i-1);
    else
        BinarySearch(arr,el,i+1,u);

}










