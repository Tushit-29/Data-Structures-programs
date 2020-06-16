#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int rear,front,capacity;
    int *ptr;
};

struct Queue* createQueue(int);
void Insert(struct Queue*,int);
void Delete(struct Queue*);
void Display(struct Queue*);

void viewQueue(struct Queue* Q)
{
    int i;
    if(Q->front!=-1)
        {
             for(i=Q->front;i!=Q->rear;Q->front==Q->capacity-1?i=0:i++)
                printf("%d ",Q->ptr[i]);
             printf("%d",Q->ptr[i]);
        }
    else
        printf("\nQueue is empty");
    printf("\nfront=%d rear=%d",Q->front,Q->rear);
}

struct Queue* createQueue(int cap)
{
    struct Queue *Q;
    Q = (struct Queue*)malloc(sizeof(struct Queue));
    Q->front = -1;
    Q->rear = -1;
    Q->capacity = cap;
    Q->ptr = (int*)malloc(sizeof(int)*cap);
    return Q;
}

void Insert(struct Queue *Q,int data)
{
    if( Q->rear+1 == Q->front || Q->front == 0 && Q->rear == Q->capacity-1)
        printf("\nOverflow ");
    else if(Q->rear == -1)
    {
        Q->rear = Q->front = 0;
        Q->ptr[Q->rear] = data;
    }
    else if(Q->rear == Q->capacity-1)
    {
        Q->rear = 0;
        Q->ptr[Q->rear] = data;
    }
    else
    {
        Q->rear += 1;
        Q->ptr[Q->rear] = data;
    }
}

void Delete(struct Queue *Q)
{
    if(Q->front == -1)
        printf("\nUnderflow");
    else if(Q->front == Q->rear)
        Q->front = Q->rear = -1;
    else if(Q->front == Q->capacity-1)
        Q->front = 0;
    else
        Q->front += 1;
}


int menu()
{
    int choice;
    printf("\n1. Create a queue \n");
    printf("2. Insert in the queue \n");
    printf("3. Delete in the queue \n");
    printf("4. Exit the program \n\n");
    printf("Enter your choice \n");
    scanf("%d",&choice);
    return choice;
}

main()
{
    struct Queue *Q = NULL;
    int data,size;
    while(1)
    {
        system("cls");
        switch(menu())
        {
          case 1:
              printf("Enter the size of queue ");
              scanf("%d",&size);
              Q = createQueue(size);
              break;

          case 2:
              printf("Enter the data to be inserted ");
              scanf("%d",&data);
              Insert(Q,data);
              break;

          case 3:
              Delete(Q);
              break;

          case 4:
              printf("Thankyou for visiting.. Press any key to exit");
              getch();
              exit(0);

          default:
              printf("Wrong choice. Please enter again");
        }
        viewQueue(Q);
        getch();
    }

}




