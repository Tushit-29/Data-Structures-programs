#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    printf("Enter rows and columns\n");
    scanf("%d %d",&m,&n);
    printf("No. of paths in this grid is %d",Grid(m,n));
}


Grid(int m,int n)
{
    if(m==1 || n==1)
        return 1;
    else
    {
        return (Grid(m,n-1)+Grid(m-1,n));
    }
}
