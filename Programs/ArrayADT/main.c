#include <stdio.h>
#include <stdlib.h>

struct Arry
{
    int capacity;
    int lastIndex;
    int *ptr;
};

struct Arry* createArray(int);
void append(struct Arry*,int);
void insert(struct Arry*,int,int);
void edit(struct Arry*,int,int);
int search(struct Arry*,int);
void del(struct Arry*,int);
void display(struct Arry*);
int count(struct Arry*);

struct Arry* createArray(int cap)
{
    struct Arry *arr;
    arr = (struct Arry*)malloc(sizeof(struct Arry));
    arr->capacity = cap;
    arr->lastIndex = -1;
    arr->ptr = (int*)malloc(cap*sizeof(int));
    return arr;
}

void append(struct Arry *arr,int data)
{
    if(arr->lastIndex+1==arr->capacity)
        printf("\nOverflow!");
    else
    {
        arr->lastIndex+=1;
        arr->ptr[arr->lastIndex]=data;
    }
}

void insert(struct Arry *arr,int index,int data)
{
    int i;
    if(index<0 || index>arr->lastIndex+1)
        printf("\nInvalid index");
    else if(arr->capacity==arr->lastIndex+1)
        printf("\nOverflow");
    else if(index<=arr->lastIndex)
    {
        for(i=arr->lastIndex;i>=index;i--)
            arr->ptr[i+1] = arr->ptr[i];
        arr->ptr[index] = data;
        arr->lastIndex += 1;
    }
    else
        append(arr,data);
}

void edit(struct Arry *arr,int index,int data)
{
    if(index<0 || index>arr->lastIndex)
        printf("\nInvalid index");
    else
        arr->ptr[index] = data;
}

int search(struct Arry *arr,int data)
{
    int i;
    for(i=0;i<=arr->lastIndex;i++)
        if(arr->ptr[i]==data)
            return i;
    return -1;
}

int count(struct Arry *arr)
{
   return (arr->lastIndex+1);
}

void del(struct Arry *arr,int index)
{
    int i;
    if(index<0 || index>arr->lastIndex)
        printf("\nInvalid index or underflow");
    else
    {
       for(i=index;i<=arr->lastIndex-1;i++)
            arr->ptr[i] = arr->ptr[i+1];
       arr->lastIndex-=1;
    }
}

void display(struct Arry *arr)
{
    int i;
    if(arr->lastIndex==-1)
        printf("Array is empty");
    else
        for(i=0;i<=arr->lastIndex;i++)
            printf("%d ",arr->ptr[i]);
}
main()
{
    int ind,choice,size,data,index;
    struct Arry *arr;

    label:
    printf("Enter your choice\n");
    printf("1. Press 1 for creating an array\n");
    printf("2. Press 2 for appending an item\n");
    printf("3. Press 3 for inserting an item\n");
    printf("4. Press 4 for editing an item\n");
    printf("5. Press 5 for deleting an item\n");
    printf("6. Press 6 for searching any item in the array\n");
    printf("7. Press 7 for displaying items of array\n");
    printf("8. Press 8 for counting total items in array\n");
    printf("9. Press 9 for exiting the program\n\n");

    while(1)
    {
    scanf("%d",&choice);
    printf("\n");

    switch(choice)
    {
    case 1:
        printf("Enter size of array\n");
        scanf("%d",&size);
        arr = createArray(size);
        system("cls");
        goto label;
        break;
    case 2:
        printf("Enter data you want to append\n");
        scanf("%d",&data);
        append(arr,data);
        system("cls");
        goto label;
        break;
    case 3:
        printf("Enter index no. and item you want to insert\n");
        scanf("%d %d",&index,&data);
        insert(arr,index,data);
        system("cls");
        goto label;
        break;
    case 4:
        printf("Enter index no. and item you want to modify\n");
        scanf("%d %d",&index,&data);
        edit(arr,index,data);
        system("cls");
        goto label;
        break;
    case 5:
        printf("Enter index no. whose data you want to be deleted\n");
        scanf("%d",&index);
        del(arr,index);
        system("cls");
        goto label;
        break;
    case 6:
        printf("Enter the item you want to search in the array\n");
        scanf("%d",&data);
        ind = search(arr,data);
        if(ind==-1)
            printf("Item not found\n");
        else
            printf("Item found at index %d",ind);
        getch();
        system("cls");
        goto label;
        break;
    case 7:
        display(arr);
        getch();
        system("cls");
        goto label;
        break;
    case 8:
        printf("Total elements currently present in array is %d",count(arr));
        getch();
        system("cls");
        goto label;
        break;
    case 9:
        printf("Thankyou for visiting");
        exit(0);
    default:
        printf("wrong input");
        system("cls");
        goto label;
    }
  }
}




