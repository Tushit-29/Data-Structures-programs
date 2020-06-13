#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int capacity;
    int *ptr;
};

struct stack* createStack(cap);
void push(struct stack*,int);
void pop(struct stack*);
int peek(struct stack*);

struct stack* createStack(int cap)
{
    struct stack *n;
    n = (struct stack*)malloc(sizeof(struct stack));
    n->top = -1;
    n->capacity = cap;
    n->ptr = (int*)malloc(sizeof(int)*cap);
    return n;
}

void push(struct stack *stak,int data)
{
    if(stak->top+1 == stak->capacity)
        printf("Stack is full");
    else
    {
        stak->ptr[stak->top+1] = data;
        stak->top += 1;
    }
}

void pop(struct stack *stak)
{
    if(stak->top == -1)
        printf("\nStack is empty");
    else
    {
        stak->top -= 1;
    }
}

int peek(struct stack *stak)
{
    if(stak->top == -1)
        return -1;
    else
        return(stak->ptr[stak->top]);
}

int count(struct stack *stak)
{
    if(stak->top==-1)
        return 0;
    else
        return stak->top+1;
}

int menu()
{
    int choice;
    system("cls");
    printf("1. create a stack\n");
    printf("2. push element into stack\n");
    printf("3. pop element from stack\n");
    printf("4. total no. of elements in stack\n");
    printf("5. view the top element of stack\n");
    printf("6. Exit the program\n");
    printf("Enter your choice\n\n");
    scanf("%d",&choice);
    return choice;
}

main()
{
    int topValue,size,data;
    struct stack *stak = NULL;

    while(1)
    {
        switch(menu())
        {
        case 1:
            printf("Enter size of stack\n");
            scanf("%d",&size);
            stak = createStack(size);
            break;

        case 2:
            printf("Enter the element you want to add\n");
            scanf("%d",&data);
            push(stak,data);
            break;

        case 3:
            pop(stak);
            break;

        case 4:
            printf("Total no. of elements currently present in stack : %d \n",count(stak));
            break;

        case 5:
            topValue = peek(stak);
            if(topValue==-1)
                printf("Stack is empty.");
            else
                printf("Top element in the stack is %d \n",topValue);
            break;

        case 6:
            printf("Thankyou for visiting.. Press any key to exit");
            getch();
            exit(0);

        default:
            printf("Please enter correct choice");

        }
        getch();
    }

}
