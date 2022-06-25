#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;

    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void preorder(struct node *root)
{   
    if(root == NULL)
        return;
    printf("%d -> ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d -> ", root->data);
}

void inorder(struct node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d -> ", root->data);
    inorder(root->right);
}

void insert(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node *));
    struct node *current, *parent;

    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        current = root;
        parent = NULL;

        while (1)
        {
            parent = current;

            if (item < parent->data)
            {
                current = current->left;
                if (current == NULL)
                {
                    parent->left = temp;
                    printf("\nNew Node Inserted at LeftSubTree\n");
                    return;
                }
            }
            else if (item > parent->data)
            {
                current = current->right;
                if (current == NULL)
                {
                    parent->right = temp;
                    printf("\nNew Node Inserted at RightSubTree\n");
                    return;
                }
            }
            else
            {
                printf("\nInvalid Value\n");
                return;
            }
        }
    }
}

int main()
{
    int item, choice;

    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Inorder\n4. Preorder\n5. Postorder\n\n0. Exit\n");
        printf("\nYour Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter Data: ");
            scanf("%d", &item);
            insert(item);
            break;
        case 2:
            printf("Work in Progress");
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Invalid Choice");
        }
    }
}
