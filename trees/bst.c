#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} bst;

bst *root = NULL;
bst *searched;
bst *create(bst *root1, int item)
{
    if (root1 == NULL)
    {
        root1 = (bst *)malloc(sizeof(bst));
        root1->data = item;
        root1->left = root1->right = NULL;
        return root1;
    }

    else if (item < root1->data)
    {
        root1->left = create(root1->left, item);
    }
    else if (item > root1->data)
    {
        root1->right = create(root1->right, item);
    }
    else
    {
        printf("Duplicates not allowed");
    }
    return root1;
}

void inorder(bst *root1)
{
    if (root1 == NULL)
    {
        return;
    }
    else
    {
        inorder(root1->left);
        printf("%d\t", root1->data);
        inorder(root1->right);
    }
}

bst *search(bst *root1, int key)
{
    if (root1 == NULL)
    {
        return NULL;
    }
    else if (key == root1->data)
    {
        return root1;
    }
    else if (key < root1->data)
    {
        return search(root1->left, key);
    }
    else
    {
        return search(root1->right, key);
    }
}

void createiterative(bst *root1, int item)
{
    bst *prev = NULL;
    while (root1 != NULL)
    {
        prev = root1;
        if (item == root1->data)
        {
            printf("no duplicates allowed");
        }
        else if (item < root1->data)
        {
            root1 = root1->left;
        }
        else if (item > root1->data)
        {
            root1 = root1->right;
        }
    }
    bst *newnode = (bst *)malloc(sizeof(bst));
    newnode->data = item;
    if (item > prev->data)
    {
        prev->right = newnode;
    }
    else if (prev == NULL)
    {
        root1 = newnode;
    }
    else
    {
        prev->left = newnode;
    }
}

void findmax(bst *root1)
{
    while (root1->right != NULL)
    {
        root1 = root1->right;
    }
    printf("%d\n", root1->data);
}

bst *findmin(bst *root1)
{
    while (root1->left != NULL)
    {
        root1 = root1->left;
    }
    printf("%d\n", root1->data);
    return root1;
}

bst *Delete(bst *root1, int data)
{
    if (root1 == NULL)
    {
        return root1;
    }

    else if (data < root1->data)
    {
        root1->left = Delete(root1->left, data);
    }
    else if (data > root1->data)
    {
        root1->right = Delete(root1->right, data);
    }
    else
    { // found you
        if (root1->left == NULL && root1->right == NULL)
        {
            free(root1); // leaf nofe
        }
        else if (root1->left == NULL)
        {
            bst *temp = root1;
            root1 = root1->right;
            free(temp);
        }
        else if (root1->right == NULL)
        {
            bst *temp = root1;
            root1 = root1->left;
            free(temp);
        }

        else
        {
            bst *temp = findmin(root1->right);
            root1->data = temp->data;
            root1->right = Delete(root1->right, temp->data);
        }
    }

    return root1;
}

int main()
{
    int input, data;
    while (input != -1)
    {
        scanf("%d", &input);

        if (input == 1)
        {
            printf("enter data: ");
            scanf("%d", &data);
            root = create(root, data);
            printf("%d", root->data);
        }
        if (input == 4)
        {
            printf("enter data: ");
            scanf("%d", &data);
            createiterative(root, data);
        }

        else if (input == 2)
        {
            inorder(root);
        }
        else if (input == 3)
        {
            searched = search(root, 5);
            if (searched != NULL)
            {
                printf("Found %d", searched->data);
            }
            else
            {
                printf("not found");
            }
        }
        else if (input == 5)
        {
            findmax(root);
        }
        else if (input == 6)
        {
            Delete(root, 50);
        }
        else
        {
            input == -1;
        }
    }
}