#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num;
    printf("Enter a number ");
    scanf("%d",&num);
    if(num>=0)
        printf("Sum of digits is %d",sumOfDigits(num));
    else
        printf("Wrong input.. Please try again");
}

int sumOfDigits(int N)
{
    if(N/10==0)
        return N;
    else
        return (N%10+sumOfDigits(N/10));
}


