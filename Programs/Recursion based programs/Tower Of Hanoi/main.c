
main()
{
    int N;
    printf("Enter number of discs  ");
    scanf("%d",&N);
    TOH(N,'A','B','C');
}

void TOH(int N,char A,char B,char C)
{
    if(N==1)
        printf("%c->%c  ",A,C);
    else
    {
        TOH(N-1,A,C,B);
        printf("%c->%c  ",A,C);
        TOH(N-1,B,A,C);
    }
}








