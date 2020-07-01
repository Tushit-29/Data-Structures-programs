#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *next;
};

void InsertAtBegin(struct node**,int);
void InsertAtLast(struct node**,int);
void DeleteAtBegin(struct node**);
void DeleteAtLast(struct node**);
struct node* search(struct node*,int);
void InsertAfter(struct node**,struct node*,int);
void DeleteNode(struct node**,struct node*);
void Display(struct node*);

InsertAtBegin(struct node **l,int data)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->item = data;
    if(*l==NULL)
    {
       n->next = n;
       *l = n;
    }
    else
    {
       n->next = (*l)->next;
       (*l)->next = n;
    }
}

InsertAtLast(struct node **l,int data)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->item = data;
    if(*l==NULL)
        InsertAtBegin(l,data);
    else
    {
         n->next = (*l)->next;
        (*l)->next = n;
        *l = n;
    }
}

void DeleteAtBegin(struct node **l)
{
    struct node *n;
    if(*l == NULL)
    {
        printf("\nUnderflow");
        return;
    }

    if((*l)->next == *l)
    {
        n = *l;
        *l = NULL;
        free(n);
    }
    else
    {
        n = (*l)->next;
        (*l)->next = n->next;
        free(n);
    }

}

void DeleteAtLast(struct node **l)
{
    struct node *n,*t;
    if(*l == NULL)
    {
        printf("\nUnderflow");
        return;
    }

    if((*l)->next == *l)
        DeleteAtBegin(l);
    else
    {
        n = *l;
        t = (*l)->next;
        while(t->next!=*l)
            t=t->next;
        t->next = (*l)->next;
        *l = t;
        free(n);
    }
}

struct node* search(struct node *last,int data)
{
    struct node *t;
    if(last==NULL)
        return NULL;
    else
    {
        t = last->next;
        while(t!=last)
        {
            if(t->item==data)
                return t;
            t=t->next;
        }
        if(t->item==data)
            return t;
        return NULL;
    }
}

void InsertAfter(struct node **l,struct node *p,int data)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->item=data;
    n->next=p->next;
    p->next=n;
    if(p==*l)
        *l=n;
}

void DeleteNode(struct node **l,struct node *p)
{
    struct node *t;
    if(*l==p)
        DeleteAtLast(l);
    else if((*l)->next==p)
        DeleteAtBegin(l);
    else
    {
        t=(*l)->next;
        while(t->next!=p)
           t=t->next;
        t->next=p->next;
        free(p);
    }
}

void Display(struct node *last)
{
    struct node *t;
    if(last==NULL)
        printf("\nList is empty");
    else
    {
        t = last->next;
        while(t!=last)
        {
            printf("%d ",t->item);
            t=t->next;
        }
        printf("%d",t->item);
    }
}

int menu()
{
    int choice;
    system("cls");
    printf("1. Insert at beginning \n");
    printf("2. Insert at last \n");
    printf("3. Delete at beginning \n");
    printf("4. Delete from last \n");
    printf("5. Insertion after particular node \n");
    printf("6. Deletion of particular node \n");
    printf("7. View all elements of list \n\n");

    printf("Enter your choice  ");
    scanf("%d",&choice);
    return choice;
}

main()
{
    struct node *last = NULL,*temp;
    int data,DATA;
    while(1)
    {
        switch(menu())
        {
        case 1:
            printf("Enter the data ");
            scanf("%d",&data);
            InsertAtBegin(&last,data);
            break;

        case 2:
            printf("Enter the data ");
            scanf("%d",&data);
            InsertAtLast(&last,data);
            break;

        case 3:
            DeleteAtBegin(&last);
            break;

        case 4:
            DeleteAtLast(&last);
            break;

        case 5:
            printf("\nEnter the data after which insertion is done ");
            scanf("%d",&DATA);
            temp = search(last,DATA);
            if(temp==NULL)
                printf("Entered data is not in last.. Please try again");
            else
            {
              printf("Enter the data ");
              scanf("%d",&data);
              InsertAfter(&last,temp,data);
            }
            break;

        case 6:
             printf("Enter the data to delete ");
             scanf("%d",&DATA);
             temp = search(last,DATA);
             if(temp==NULL)
                printf("Entered data is not in list");
             else
                DeleteNode(&last,temp);
             break;

        case 7:
            Display(last);
            break;

        case 8:
            printf("Thankyou for visiting.. Press any key to exit");
            getch();
            exit(0);

        default:
            printf("Wrong choice.. Please try again");

        }
        getch();
    }
}
