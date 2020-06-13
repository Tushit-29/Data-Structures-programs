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
    n->next = NULL;
    if(*s==NULL)
        *s = n;
    else
    {
        t = *s;
        while(t->next!=NULL)
            t=t->next;
        t->next = n;
    }
}

void pop(struct node **s)
{
    struct node *t1,*t2;
    if(*s==NULL)
        printf("\nUnderflow");
    else
    {
      t1 = *s;
      if((*s)->next==NULL)
      {
          *s = NULL;
          free(t1);
      }
      else
      {
          while(t1->next!=NULL)
          {
              t2=t1;
              t1=t1->next;
          }
          t2->next = NULL;
          free(t1);
      }
    }
}

int peek(struct node *s)
{
    if(s==NULL)
        return -1;
    else
    {
        while(s->next!=NULL)
            s=s->next;
        return(s->item);
    }
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
    int value,topValue;

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
            topValue = peek(start);
            if(topValue==-1)
                printf("Stack is empty");
            else
                printf("Top element of stack is %d",topValue);
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
