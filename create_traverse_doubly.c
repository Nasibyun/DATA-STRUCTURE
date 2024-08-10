#include<stdio.h>
#include<stdlib.h>

typedef struct DLLnode
{
    int data;
    struct DLLnode *next, *back;
}DLLnode;

DLLnode* create()
{
    DLLnode* start;
    DLLnode* temp;
    DLLnode* current;
    int val1, val2;

    start = (DLLnode*)malloc(sizeof(DLLnode));

    if(start == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(0);
    }

    printf("Enter the first ndoe value : ");
    scanf("%d", &val1);
    start->data = val1;

    if(val1 == (-1))
    {
        start->next =NULL;
        return NULL;
    }

    start->back =NULL;
    current = start;
    do
    {   
        printf("To exit insert -1 \n\n");
        temp = (DLLnode*)malloc(sizeof(DLLnode));

        printf("Enter the next node value : ");
        scanf("%d", &val2);
        temp->data = val2;

        if(val2 == (-1))
        {
            current->next = NULL;
            break;
        }
        current->next = temp;
        temp->back = current;

        current = temp;
        
    }while(1);

    current->next = NULL;
    return start;
}

void trav_forw(DLLnode* start)
{
    DLLnode* temp;
    temp = start;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp=temp->next;
    }
}
void trav_back(DLLnode* start)
{
    DLLnode* temp = start;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp=temp->back;
    }
}

int main()
{
    DLLnode* start;
    start = create();
    trav_forw(start);
    trav_back(start);

    return 0;
}