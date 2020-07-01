#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int item;
    struct node *next;
};

void InsertAtFirst(struct node**,int);
void InsertAtLast(struct node**,int);
void InsertAfter(struct node**,struct node*,int);
void DeleteAtFirst(struct node**);
void DeleteAtLast(struct node**);
void DeleteNode(struct node**,struct node*);
void Display(struct node*);
struct node* search(struct node*,int);

void InsertAtFirst(struct node **l,int data)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->item=data;
    if(*l==NULL)
    {
        *l=n;
        n->next=n;
        n->prev=n;
    }
    else
    {
        n->prev=*l;
        n->next=(*l)->next;
        (*l)->next=n;
        n->next->prev=n;
    }
}

void InsertAtLast(struct node **l,int data)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    if(*l==NULL)
        InsertAtFirst(l,data);
    else
    {
        n->item=data;
        n->next=(*l)->next;
        n->prev=*l;
        (*l)->next->prev=n;
        (*l)->next=n;
        *l=n;
    }
}

void InsertAfter(struct node **l,struct node *p,int data)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->item=data;
    if(p==*l)
        InsertAtLast(l,data);
    else
    {
        n->next=p->next;
        n->prev=p;
        n->next->prev=n;
        p->next=n;
    }
}

void DeleteAtFirst(struct node **l)
{
    struct node *n;
    if(*l==NULL)
    {
        printf("\nUnderflow");
        return;
    }
    if((*l)->next==*l)
    {
        n=*l;
        *l=NULL;
        free(n);
    }
    else
    {
        n=(*l)->next;
        (*l)->next=n->next;
        n->next->prev=*l;
        free(n);
    }
}

void DeleteAtLast(struct node **l)
{
    struct node *n;
    if(*l==NULL)
    {
        printf("\nUnderflow");
        return;
    }
    if((*l)->next==*l)
        DeleteAtFirst(l);
    else
    {
        n=*l;
        n->prev->next=n->next;
        n->next->prev=n->prev;
        *l=n->prev;
        free(n);
    }
}

void DeleteNode(struct node **l,struct node *p)
{
    if(p==*l)
        DeleteAtLast(l);
    else if(p==(*l)->next)
        DeleteAtFirst(l);
    else
      {
         p->next->prev=p->prev;
         p->prev->next=p->next;
         free(p);
      }
}

Display(struct node *last)
{
    struct node *t;
    if(last==NULL)
        printf("\nList is empty");
    else
    {
        t=last->next;
        while(t!=last)
        {
            printf("%d ",t->item);
            t=t->next;
        }
        printf("%d",t->item);
    }
}

struct node* search(struct node *last,int data)
{
    struct node *t;
    if(last==NULL)
        return NULL;
    else
    {
        t=last->next;
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

int menu()
{
    int choice;
    printf("1. Insert at begin\n");
    printf("2. Insert at end\n");
    printf("3. Insert after particular node\n");
    printf("4. Delete at begin\n");
    printf("5. Delete at end\n");
    printf("6. Delete particular node\n");
    printf("7. View all elements\n");
    printf("8. Exit\n\n");
    printf("Enter your choice ");
    scanf("%d",&choice);
    return choice;
}

main()
{
    struct node *last=NULL,*temp;
    int data,DATA;
    while(1)
    {
        system("cls");
        switch(menu())
        {
        case 1:
            printf("Enter the data to insert ");
            scanf("%d",&data);
            InsertAtFirst(&last,data);
            break;

        case 2:
            printf("Enter the data to insert ");
            scanf("%d",&data);
            InsertAtLast(&last,data);
            break;

        case 3:
            printf("Enter the data after which insertion is to be done ");
            scanf("%d",&DATA);
            temp=search(last,DATA);
            if(temp==NULL)
                printf("Entered data is not in list");
            else
            {
                printf("Enter the data to insert ");
                scanf("%d",&data);
                InsertAfter(&last,temp,data);
            }
            break;

        case 4:
            DeleteAtFirst(&last);
            break;

        case 5:
            DeleteAtLast(&last);
            break;

        case 6:
            printf("Enter the data to be deleted");
            scanf("%d",&DATA);
            temp=search(last,DATA);
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











