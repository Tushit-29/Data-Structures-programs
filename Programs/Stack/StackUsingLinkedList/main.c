#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *next;
};

void push(struct node**, int);
void pop(struct node**);
int peek(struct node*);

void push(struct node **s, int data)
{
    struct node *n,*t;
    n = (struct node*)malloc(sizeof(struct node));
    n->item = data;
    n->next = *s;
    *s = n;
}

void pop(struct node **s)
{
    struct node *n;
    if(*s==NULL)
        printf("\nUnderflow");
    else
    {
        n = *s;
        *s = n->next;
        free(n);
    }


}

int peek(struct node *s)
{
    if(s==NULL)
        printf("\n Stack is empty");
    else
        printf("%d",s->item);
}

int menu()
{
    int choice;
    system("cls");
    printf("1. Push the element to top of stack \n");
    printf("2. Pop the top element of stack \n");
    printf("3. View the top element of stack \n");
    printf("4. Exit the program \n\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    return choice;
}

main()
{
    struct node *start = NULL;
    int value;

    while(1)
    {
        switch(menu())
        {
        case 1:
            printf("Enter the element to be pushed\n");
            scanf("%d",&value);
            push(&start,value);
            break;

        case 2:
            pop(&start);
            break;

        case 3:
            peek(start);
            break;

        case 4:
            printf("Thankyou for visiting.. Press any key to exit");
            getch();
            exit(0);

        default:
            printf("Please enter correct choice");
    }
    getch();
  }

}
