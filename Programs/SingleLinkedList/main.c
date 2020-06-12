#include <stdlib.h>
#include<stdio.h>

struct node
{
    int item;
    struct node *next;
};

void Display(struct node**);
void InsertAtBegin(int,struct node**);
void InsertAtLast(int,struct node**);
void DeleteAtBegin(struct node**);
void DeleteAtLast(struct node**);
void InsertAfter(int,struct node*);
void DeleteNode(struct node*,struct node**);

struct node* search(int data,struct node *start)
{
    while(start)
    {
        if(start->item == data)
        {
            return start;
        }
        start=start->next;
    }
    return NULL;
}

void Display(struct node **s)
{
    struct node *t;
    if(*s==NULL)
        printf("\nList is empty");
    else
    {
        t=*s;
//        while(t->next!=NULL)
//        {
//            printf("%d ",t->item);
//            t=t->next;
//        }
//        printf("%d",t->item);

          printf("%d",t->item);
          while(t->next!=NULL)
          {
              t=t->next;
              printf(" %d",t->item);
          }
    }

}

void InsertAtBegin(int data,struct node **s)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->item = data;
    n->next = *s;
    *s = n;
}

void InsertAtLast(int data,struct node **s)
{
    struct node *n,*t;
    n = (struct node*)malloc(sizeof(struct node));
    n->item = data;
    n->next = NULL;

    if(*s==NULL)
        *s = n;
    else
        t = *s;
        while(t->next!=NULL)
            t=t->next;
        t->next = n;
}

void DeleteAtBegin(struct node **s)
{
  struct node *n;
  if(*s==NULL)
        printf("\nUnderflow");
  else
  {
      n = *s;
      *s = (*s)->next;   // *s = t->next;
      free(n);
  }
}

void DeleteAtLast(struct node **s)
{
    struct node *t1,*t2;
    if(*s==NULL)
        printf("\nUnderflow");
    else
    {
        if((*s)->next==NULL)
        {
            t1=*s;
            *s = NULL;
            free(t1);
        }
        else
        {
            t1=*s;
            t2=NULL;
            while(t1->next!=NULL)
            {
                t2=t1;
                t1=t1->next;
            }
            t2->next=NULL;
            free(t1);
        }
    }
}

void InsertAfter(int data,struct node*t)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->item = data;
    n->next = t->next;
    t->next = n;
}

void DeleteNode(struct node *t,struct node **s)
{
    struct node *n;
    if(*s==NULL)
        printf("\nUnderflow");
    else
    {
        if(*s==t)
        {
            *s=(*s)->next;
            free(t);
        }
        else
        {
            n=*s;
            while(n->next!=t)
                n=n->next;
            n->next=t->next;
            free(t);
        }
    }
}

int menu()
{
    int choice;
    system("cls");
    printf("1. Press 1 for inserting new node at beginning \n");
    printf("2. Press 2 for inserting new node at end\n");
    printf("3. Press 3 for inserting new node after particular node\n");
    printf("4. Press 4 for deleting node at beginning\n");
    printf("5. Press 5 for deleting node at end\n");
    printf("6. Press 6 for deleting node at after particular node\n");
    printf("7. Press 7 for displaying all nodes of list\n");
    printf("8. Press 8 for exiting the program\n\n");

    printf("Please enter your choice\n\n");

    scanf("%d",&choice);
    return choice;
}

main()
{
    struct node *start=NULL,*temp;
    int DATA,data;

    while(1)
    {
        switch(menu())
        {
        case 1:
            printf("Enter the data ");
            scanf("%d",&data);
            InsertAtBegin(data,&start);
            break;

        case 2:
            printf("Enter the data ");
            scanf("%d",&data);
            InsertAtLast(data,&start);
            break;

        case 3:
            printf("Enter the data ");
            scanf("%d",&data);
            printf("Enter value after which data should be inserted ");
            scanf("%d",&DATA);
            if(start==NULL)
            {
                printf("List is empty.Please fill some items in the list");
                break;
            }
            temp = search(DATA,start);
            if(temp==NULL)
                printf("Entered item not found .. Please try again");
            else
            {
                InsertAfter(data,temp);
            }
            break;

        case 4:
            DeleteAtBegin(&start);
            break;

        case 5:
            DeleteAtLast(&start);
            break;

        case 6:
            printf("Enter the data you want to delete ");
            scanf("%d",&DATA);
            temp = search(DATA,start);
            if(temp==NULL)
                printf("Entered item not found..Please try again");
            else
                DeleteNode(temp,&start);
            break;

        case 7:
            Display(&start);
            break;

        case 8:
            printf("Thankyou for visiting. Press any key to exit");
            getch();
            exit(0);

        default:
            printf("Please enter correct choice");
        }
        getch();
    }

}










