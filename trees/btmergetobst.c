#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} bt;
bt *root, *root2, *rootm=NULL, *merged;

bt *create()
{
    int x;
    printf("enter data: ");
    scanf("%d", &x);
    bt *newnode = (bt *)malloc(sizeof(bt));
    if (x == -1)
    {
        return NULL;
    }
    newnode->data = x;

    printf("enter left child of %d", x);
    newnode->left = create();
    printf("enter right child of %d", x);
    newnode->right = create();
    return newnode;
}

bt *createbst(bt *root1, int item)
{
    if (root1 == NULL)
    {
        root1 = (bt *)malloc(sizeof(bt));
        root1->data = item;
        root1->left = root1->right = NULL;
        return root1;
    }

    else if (item < root1->data)
    {
        root1->left = createbst(root1->left, item);
    }
    else if (item > root1->data)
    {
        root1->right = createbst(root1->right, item);
    }
    else
    {
        printf("Duplicates not allowed");
    }
    return root1;
}

void inorder(bt *root1)
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
bt *MergeTrees(bt *t1, bt *t2)
{
    if (t1 == NULL && t2 == NULL) {
        return NULL;
    }

    if (t1 != NULL && t2 == NULL) {
        // printf("%d\t", t1->data);
        rootm=createbst(rootm, t1->data);
        return t1;
    }
    if (t2 != NULL && t1 == NULL) {
        // printf("%d\t", t2->data);
                rootm=createbst(rootm, t2->data)
;
        return t2;
    }

    t1->data += t2->data;
    // printf("%d\t", t1->data);
            rootm=createbst(rootm, t1->data);

    t1->left = MergeTrees(t1->left, t2->left);
    t1->right = MergeTrees(t1->right, t2->right);
    
    return t1;
}

int main()
{

    int input, data;
    while (input != -1)
    {
        scanf("%d", &input);

        if (input == 1)
        {

            root = create(root, data);
            printf("%d", root->data);
        }
        if (input == 2)
        {

            root2 = create(root2, data);
            printf("%d", root2->data);
        }
        if (input == 3)
        {
            merged = MergeTrees(root, root2);
        }
        if (input == 4)
        {
            inorder(rootm);
        }
    }
}