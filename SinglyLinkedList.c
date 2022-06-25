#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_start(int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node *));

    ptr->data = item;

    if (head == NULL)
    {
        ptr->next = NULL;
        head = ptr;
        printf("\nList was Empty! Item Inserted\n");
    }
    else
    {
        ptr->next = head;
        head = ptr;

        printf("\nItem Inserted at Start\n");
    }
}

void insert_end(int item)
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node *));

    ptr->data = item;

    if (head == NULL)
    {
        insert_start(item);
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = NULL;
        printf("\nItem inserted at End\n");
    }
}

void insert_location_A(int item, int location)
{
    int i;
    struct node *temp;
    struct node *ptr = (struct node *)malloc(sizeof(struct node *));

    ptr->data = item;
    temp = head;

    for (i = 1; i < location; i++)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            printf("\nCan't Insert\n");
            return;
        }
    }
    ptr->next = temp->next;
    temp->next = ptr;

    printf("\nItem Inserted at %dth position", location + 1);
}

void insert_location_B(int item, int location)
{
    int i;
    struct node *temp;
    struct node *ptr = (struct node *)malloc(sizeof(struct node *));

    ptr->data = item;
    temp = head;

    for (i = 1; i < location - 1; i++)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            printf("\nCan't Insert\n");
            return;
        }
    }
    ptr->next = temp->next;
    temp->next = ptr;

    printf("\nItem Inserted at %dth position", location);
}

void delete_start()
{
    struct node *ptr;

    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Item Deleted from Start\n");
    }
}

void delete_end()
{
    struct node *rmptr, *preptr;

    if (head == NULL)
    {
        delete_start();
    }
    else if (head->next == NULL)
    {
        rmptr = head;
        head = NULL;
        free(rmptr);

        printf("Only Item Present in list Deleted\n");
    }
    else
    {
        rmptr = head;
        while (rmptr->next != NULL)
        {
            preptr = rmptr;
            rmptr = rmptr->next;
        }
        preptr->next = NULL;
        free(rmptr);
        printf("Last Item Deleted\n");
    }
}

void delete_location(int del_loc)
{
    int i;
    struct node *rmptr, *preptr;
    rmptr = head;

    for (i = 1; i <= del_loc - 1; i++)
    {
        preptr = rmptr;
        rmptr = rmptr->next;
        if (rmptr->next == NULL)
        {
            printf("\nCan't Delete\n");
        }
    }
    preptr->next = rmptr->next;
    free(rmptr);
    printf("\nData of %dth Position Deleted\n", del_loc);
}

void search()
{
    int i = 1, flag, S_data;
    struct node *ptr;

    printf("\nEnter the Item you want to Search: ");
    scanf("%d", &S_data);

    ptr = head;

    if (head == NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
        while (ptr != NULL)
        {
            if (ptr->data == S_data)
            {
                printf("\nItem Found At %dth Position\n", i);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
            ptr = ptr->next;
            i++;
        }
        if (flag == 1)
        {
            printf("\nItem Not Found!\n");
        }
    }
}
void display()
{
    struct node *ptr;
    ptr = head;

    if (ptr == NULL)
    {
        printf("List is Empty! Nothing To Display\n");
    }
    else
    {
        printf("\nDisplaying : ");

        while (ptr != NULL)
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
        free(ptr);
    }
}

void main()
{
    int item, choice;

    printf("\n\n\t\t*********Welcome*********\t\t\n");

    while (1)
    {
        printf("\n1. Insert Function\n2. Delete Functions\n3. Display\n4. Search\n\n0. Exit\n\n");
        printf("\nYour Choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:

            int insertchoice;

            printf("\nInsert Functions\n\n\t1. Insert at Beginning\n\t2. Insert at End\n\t3. Insert at Position\n");
            printf("\n\nYour choice: "); // Can be improvised
            scanf("%d", &insertchoice);
            printf("\n");

            switch (insertchoice)
            {
            case 1:
                printf("Enter Data: ");
                scanf("%d", &item);
                insert_start(item);
                break;
            case 2:
                printf("Enter Data: ");
                scanf("%d", &item);
                insert_end(item);
                break;
            case 3:
                int location, loc_choice;
                if (head == 0)
                {
                    printf("\nList is Empty\n");
                    loc_choice = 0;
                }
                else
                {
                    printf("\tEnter Location: ");
                    scanf("%d", &location);
                    printf("\t1. Insert Before\n\t2. Insert After\n");
                    printf("\nYour Choice: ");
                    scanf("%d", &loc_choice);
                }
                switch (loc_choice)
                {
                case 1:
                    printf("\n\t\tEnter Data: ");
                    scanf("%d", &item);
                    insert_location_B(item, location);
                    break;
                case 2:
                    printf("\n\t\tEnter Data: ");
                    scanf("%d", &item);
                    insert_location_A(item, location);
                    break;
                default:
                    printf("\nInvalid Choice");
                }
                break;
            default:
                printf("\n\tInvalid Choice\n");
            }
            break;
        case 2:
            int deletechoice;

            printf("\nDelete Functionsn\n\n\t1. Delete at Beginning\n\t2. Delete at End\n\t3. Delete Position\n");
            printf("\n\nYour Choice: "); // Can be improvised
            scanf("%d", &deletechoice);
            printf("\n");

            switch (deletechoice)
            {
            case 1:
                delete_start();
                break;
            case 2:
                delete_end();
                break;
            case 3:
                int del_loc;

                if (head == NULL)
                {
                    printf("\nList is Empty\n");
                }
                else
                {
                    printf("\nEnter Location of Node to Delete: ");
                    scanf("%d", &del_loc);
                    delete_location(del_loc);
                }
                break;
            default:
                printf("\n\tInvalid Choice\n");
            }
            break;
        case 3:
            display();
            break;
        case 4:
            search();
            break;
        case 0:
            printf("Thank You!\n\n");
            exit(0);
            break;
        default:
            printf("\nInvalid Choice\n");
        }
    }
}