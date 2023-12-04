#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
    int leftIsThreaded;
    int rightIsThreaded;
} Node;
Node *root=NULL, *head;



void insert(Node *root, Node *temp){
    if(temp->data < root->data){
        while(root->left!=head){
             root=root->left;
        }
        temp->left=root->left;

        root->left=temp;
        temp->right=root;
        root->leftIsThreaded=1;
    }

    if(temp->data > root->data){
        while(root->right!=head){
             root=root->right;
        }
        temp->right=root->right;

        root->right=temp;
        temp->left=root;
        root->rightIsThreaded=1;
    }
}

Node* create(int x){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    newNode->leftIsThreaded = newNode->rightIsThreaded = 0;
    // return newNode;

    if(root==NULL){
        root = newNode;
        head = (Node *)malloc(sizeof(Node));
        head->data=0;
        head->right=head;
        head->rightIsThreaded=1;
        head->left=root;
        head->leftIsThreaded=1;
        root->left=head;
        root->right=head;
    }

    else{
        insert(root, newNode);

    }
    return root;
    }


void inroder(Node *head){
   Node *current = head->left;
   while( current!= head){
    while(current->left != head && current->leftIsThreaded != 0){
        current=current->left;
    }
            printf("%d ", current->data);
   while (current->right != head && current->rightIsThreaded !=1) {
    current = current->right;
            printf("%d ", current->data);

   }

   current=current->right;

   }

}



int main(){
    int input, data;
    while (input != -1)
    {
        scanf("%d", &input);

        if (input == 1)
        {
            printf("enter value");
            scanf("%d", &data);
            root = create(data);
            printf("%d", root->data);
        }

        if(input==2){
            inroder(head);
        }
}}