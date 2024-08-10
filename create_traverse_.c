#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* link;
}node;

node* create()
{
    node* start;
    node* temp1;
    node* current;

    int val;
    start = (node*)malloc(sizeof(node));
    
    if(start == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(0);
    }

    printf("Enter the first ndoe value : ");
    scanf("%d", &val);
    start->data = val;

    if(val == (-1))
    {
        start->link =NULL;
        return NULL;
    }
    current = start;
    do
    {
        printf("To exit insert -1 \n\n");
        temp1 = (node*)malloc(sizeof(node));
        printf("Enter the next node value : ");
        scanf("%d", &val);
        temp1->data = val;

        if(val == (-1))
        {
            current->link = NULL;
            break;
        }
        current->link = temp1;
        current = temp1;
    }while(1);

    current->link = NULL;
    return start;
}

void traverse(node* head)
{
    node* temp1;
    temp1 = head;

    while(temp1 != NULL)
    {
        printf("%d  ", temp1->data);
        temp1 = temp1->link;
    }
}
int main()
{
    node* start;
    start = create();
    traverse(start);
    return 0;
}