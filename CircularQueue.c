#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int f, r;

void inqueue(int);
void dequeue();
void display();

void inqueue(int ele)
{
    if ((r + 1) % MAX == f)
    {
        printf("Queue is full");
        return;
    }
    else if (f == -1 && r == -1)
    {
        f = r = 0;
        queue[r] = ele;
    }
    else
    {
        r = (r + 1) % MAX;
        queue[r] = ele;
    }
    printf("Element inserted...\n");
}

void dequeue()
{
    if (f == -1 && r == -1)
    {
        printf("Queue is Empty");
        return;
    }
    // else if(r == r)
    // {
    //     printf("Removed element in Queue is %d", queue[f]);
    //     f = r = -1;
    // }
    else
    {
        printf("Removed element in Queue is %d", queue[f]);
        f = (f + 1) % MAX;
    }
}

void display()
{
    int i = f;
    if (f == -1 && r == -1)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("Element in Queue....\n");
        while (i < r)
        {
            printf("%d\t", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d", queue[i]);
    }
}

void main()
{
    f = r = -1;
    int ch = 0, ele;
    printf("\n=========MAIN MENU==========\n");
    printf("\n1.  INQUEUE\n2.  DEQUEUE\n3.  DISPLAY\n4.  EXIT\n");

    while (ch != 4)
    {
        printf("\n\nEnter Choice  :  ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element  :  ");
            scanf("%d", &ele);
            inqueue(ele);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice, Please enter valid choice in between 1 to 4");
        }
    }
}
