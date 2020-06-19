#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,p=0;
    printf("Enter any number");
    scanf("%d",&num);
    if(num>=0)
        printf("Reverse is %d",rev(num,&p));
    else
        printf("Wrong input.. Please try again");
}

int rev(int N,int *p)
{

    if(N/10==0)
    {
       *p = (*p)*10 + N;
        return *p;
    }
    else
    {
        *p = (*p)*10 + N%10;
        rev(N/10,p);
    }
}
