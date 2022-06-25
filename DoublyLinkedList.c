#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;

    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insert_start()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));

    printf("Enter data  :  ");
    scanf("%d", &item);

    ptr->data = item;

    if (head == NULL)
    {
        ptr->next = NULL;
        ptr->prev = NULL;

        head = ptr;
    }
    else
    {
        ptr->prev = NULL;
        ptr->next = head;
        head->prev = ptr;

        head = ptr;
    }
    printf("Node inserted at Begining\n");
}

void insert_last()
{
    int item;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (head == NULL)
    {
        insert_start();
    }
    else
    {
        printf("Enter Data: ");
        scanf("%d", &item);

        ptr->data = item;
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
        ptr->next = NULL;

        printf("\nItem Inserted");
    }
}

void insert_loc() {} //Work in Progress

void delete_start()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);

        printf("Item Deleted");
    }
}

void delete_last()
{
    struct node *temp;

    if (head == NULL)
    {
        delete_start();
    }
    else if(head->next = NULL){
        head = NULL;
        free(head);
    }
    else
    {
        temp = head;

        while (temp != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        free(temp);
    }
}

void delete__loc() {} //Work in Progress

void display()
{
    struct node *temp;
    temp = head;

    printf("Displaying Items: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice, int_insert, int_del;
    printf("\n\n**********Welcome**********\n\n");

    while (1)
    {
        printf("\n1. Insert Functions\n2. Delete Functons\n3. Display\n\n0. Exit\n\n");
        printf("Your Choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 0:
            printf("\nThank You!\n\n");
            exit(0);
            break;
        case 1:
            printf("\n\t1. Insert at Start\n\t2. Insert at End\n\t3. Inser at Location\n");
            printf("\nYour Choice: ");
            scanf("%d", &int_insert);
            switch (int_insert)
            {
            case 1:
                insert_start();
                break;
            case 2:
                insert_last();
                break;
            case 3:
                insert_loc();
                break;
            default:
                printf("\nInvalid Choice\n\n");
            }
            break;
        case 2:
            printf("\n\t1. Delete at Start\n\t2. Delete at End\n\t3. Delete at Location\n");
            printf("\nYour Choice: ");
            scanf("%d", &int_del);
            switch (int_del)
            {
            case 1:
                delete_start();
                break;
            case 2:
                delete_last();
                break;
            case 3:
                delete__loc();
                break;
            default:
                printf("\nInvalid Choice\n\n");
            }
            break;
        case 3:
            display();
            break;
        default:
            printf("Invaild Choice");
        }
    }
}