#include <stdio.h>
#include <stdlib.h>
#define max 5

int queue[max];
int rear = -1;
int front = -1;

void insert(int item)
{
    if (rear == max - 1)
    {
        printf("\nQueue Full\n");
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = item;
    printf("\nItem Inserted\n");
}

void delete ()
{
    int item;
    if (front == -1 || front > rear)
    {
        printf("Empty List");
        return;
    }
    else
    {
        item = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        printf("\n%d Item Deleted for Stack\n", item);
    }
}

void display()
{
    int i;

    if (rear == -1)
    {
        printf("\nEmpty Queue\n");
    }
    else
    {
        printf("\nPrinting Values: ");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

void main()
{
    int choice, item;
    printf("\n\nMain Menu\n\n");
    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n\n0. Exit\n");
        printf("\nYour Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter Data: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("\nInvaid Choice\n");

        }
    }
}
