#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* link;
}node;

node* insert_at_start(node* start , int newval)
{
    node* temp;
    temp =(node*)malloc(sizeof(node));
    if(temp  == NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    temp->data = newval;
    temp->link = start;

    start = temp;
    return start;
}

node* delete_at_start(node* start, int * val)
{   
    node* temp;
    if(start==NULL)
    {
        return NULL;
    }
    *val = start-> data;
    temp = start;

    start = start-> link;
    free(temp);

    return start;
}
void display(node* start)
{
    node* temp = start;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
}

int main()
{
    node* start = NULL;
    int newval,delval;
    int choice;

    while(choice!=4)
    {
        printf("1: insert\n2: delete\n3: display\n4: exit\n");
        printf("Enter your choice : ");
        scanf("%d" ,&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value : ");
            scanf("%d", &newval);
            start = insert_at_start(start,newval);
            printf("\n\n");
            break;
        case 2:
            start = delete_at_start(start,&delval);
            printf("Inserted value is : %d\n\n", delval);
            break;
        case 3:
            display(start);
            printf("\n\n");
            break;
        case 4:
            printf("Exiting........\n\n");
            exit(0);
        default:
            break;
        }
    }
    return 0;
}