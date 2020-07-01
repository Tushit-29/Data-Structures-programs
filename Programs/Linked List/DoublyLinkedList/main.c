#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int item;
    struct node *next;
};

void InsertAtBegin(struct node**,int);
void InsertAtLast(struct node**,int);
void DeleteAtBegin(struct node**);
void DeleteAtLast(struct node**);
void InsertAfter(int,struct node*);
void DeleteNode(struct node**,struct node*);
void view(struct node*);
struct node* search(struct node*,int);

void InsertAtBegin(struct node **s,int data)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->item = data;
    n->prev = NULL;
    n->next = *s;
    if(*s != NULL)
        (*s)->prev = n;
    *s = n;
}

void InsertAtLast(struct node **s,int data)
{
    struct node *n,*t;
    n = (struct node*)malloc(sizeof(struct node));
    n->item = data;
    n->next = NULL;
    if(*s==NULL)
    {
        n->prev = NULL;
        *s = n;
    }
    else
    {
        t = *s;
        while(t->next!=NULL)
            t=t->next;
        n->prev = t;
        t->next = n;
    }
}

void DeleteAtBegin(struct node **s)
{
    struct node *t;
    if(*s == NULL)
        printf("\nUnderflow");
    else
    {
        t = *s;
        *s = (*s)->next;
        if(t->next != NULL)
            (*s)->prev = NULL;
        free(t);
    }
}

void DeleteAtLast(struct node **s)
{
    struct node *t;
    if(*s == NULL)
        printf("\nUnderflow");
    else
    {
        if((*s)->next==NULL)
            DeleteAtBegin(s);
        else
        {
            t=*s;
            while(t->next!=NULL)
                t=t->next;
            t->prev->next = NULL;
            free(t);
        }
    }
}

void InsertAfter(int data,struct node *p)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->item = data;
    n->prev = p;
    n->next = p->next;
    if(p->next!=NULL)
        p->next->prev = n;
    p->next = n;
}

void DeleteNode(struct node **s,struct node *p)
{
    if(p->prev==NULL)
        DeleteAtBegin(s);
    else
    {
      if(p->next!=NULL)
         p->next->prev=p->prev;
      p->prev->next=p->next;
      free(p);
    }
}

void view(struct node *start)
{
    if(start==NULL)
        printf("List is empty");
    else
    {
      while(start)
      {
         printf("%d ",start->item);
         start = start->next;
      }
    }
}

 struct node* search(struct node *start,int data)
{
    while(start)
    {
        if(start->item==data)
            return start;
        start = start->next;
    }
    return NULL;
}

int menu()
{
    int choice;
    system("cls");
    printf("1. Insert at Begin \n");
    printf("2. Insert at last \n");
    printf("3. Delete at begin \n");
    printf("4. Delete at last \n");
    printf("5. Insert after particular node \n");
    printf("6. Delete particular node \n");
    printf("7. View all elements of list \n");
    printf("8. Exit the program \n\n");
    printf("Enter your choice \n\n");
    scanf("%d",&choice);
    printf("\n");
    return choice;
}

main()
{
    struct node *start = NULL,*temp;
    int data,DATA;

    while(1)
    {
        switch(menu())
        {
        case 1:
            printf("Enter the data you want to insert ");
            scanf("%d",&data);
            InsertAtBegin(&start,data);
            break;

        case 2:
            printf("Enter the data you want to insert ");
            scanf("%d",&data);
            InsertAtLast(&start,data);
            break;

        case 3:
            DeleteAtBegin(&start);
            break;

        case 4:
            DeleteAtLast(&start);
            break;

        case 5:
            printf("Enter the data after which insertion is to be done ");
            scanf("%d",&DATA);
            temp = search(start,DATA);
            if(temp==NULL)
                printf("Entered item is not in list");
            else
            {
              printf("Enter the data you want to insert ");
              scanf("%d",&data);
              InsertAfter(data,temp);
            }
            break;

        case 6:
            printf("Enter the data you want to delete from list ");
            scanf("%d",&DATA);
            temp = search(start,DATA);
            if(temp==NULL)
                printf("Entered item is not in the list.. Please enter again ");
            else
                DeleteNode(&start,temp);
            break;

        case 7:
            view(start);
            break;

        case 8:
            printf("Thankyou for visiting.. Press any key to exit ");
            getch();
            exit(0);
        }
        getch();
    }

}
