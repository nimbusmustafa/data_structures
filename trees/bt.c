#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 100

int count = 0;
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} bt;
bt *root, *roota, *coppy, *merge;

typedef struct {
    bt **queue;
    int front, rear;
} Queue;

void initialize(Queue *q){
        q->queue = (bt**)malloc(n * sizeof(bt*));

}

void enqueue(Queue *q, bt* x){
    if(q->rear == n-1){
        printf("Stack overflow");
    }

    else if(q->rear == -1 && q->front== -1){
        q->rear=q->front=0;
        q->queue[q->rear]=x;
    }
    else{
        q->rear++;
        q->queue[q->rear]=x;


    }
}

bt* dequeue(Queue *q){
        // printf("in dequeu");

    if(q->rear == -1 && q->front== -1){
        printf("Stack underflow");
        return 0;

    }
    else if(q->front == q->rear){
                bt* j= q->queue[q->front];

                q->rear=q->front=-1;
                return j;

    }
    else{
        bt* j= q->queue[q->front];
        // printf("%d", q->queue[q->front]);
        q->front++;
        return j;
    }
}


typedef struct
{
    bt *s[100];
    int top;
} stack;

void push(stack *ps, bt *x)
{
    ps->s[++(ps->top)] = x;
}

bt *pop(stack *ps)
{
    return (ps->s[(ps->top)--]);
}

int isEmpty(stack *ps)
{
    return ps->top == -1;
}

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

void inorder(bt *root1)
{
    if (root1 == NULL)
    {
        return;
    }

    inorder(root1->left);
    printf("%d\t", root1->data);
    inorder(root1->right);
}
void postorder(bt *root1)
{
    if (root1 == NULL)
    {
        return;
    }

    postorder(root1->left);
    postorder(root1->right);
    printf("%d\t", root1->data);
}
void preorder(bt *root1)
{
    if (root1 == NULL)
    {
        return;
    }

    printf("%d\t", root1->data);
    preorder(root1->left);
    preorder(root1->right);
}

bt *copy(bt *root1)
{
    if (root1 == NULL)
    {
        return NULL;
    }

    bt *newnode = (bt *)malloc(sizeof(bt));
    newnode->data = root1->data;
    newnode->left = copy(root1->left);
    newnode->right = copy(root1->right);
    return newnode;
}
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
        return b;
}

int height(bt *root1)
{
    if (root1 == NULL)
    {
        return 0;
    }
    return (1 + max(height(root1->left), height(root1->right)));
}

int equal(bt *root1, bt *root2)
{

    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }
    else if (root1 != NULL && root2 != NULL)
    {
        if ((root1->data == root2->data) && equal(root1->left, root->left) && equal(root->right, root->right))
            return 1;
    }
    else
        return 0;
}

int ancestors(bt *root1, int target)
{
    if (root1 != NULL)
    {
        if (root1->data == target)
        {
            return 1;
        }

        else if (ancestors(root1->left, target) || ancestors(root1->right, target))
        {
            printf("%d\t", root1->data);
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

bt *MergeTrees(bt *t1, bt *t2)
{
    if (!t1)
        return t2;
    if (!t2)
        return t1;
    t1->data += t2->data;
    t1->left = MergeTrees(t1->left, t2->left);
    t1->right = MergeTrees(t1->right, t2->right);
    return t1;
}

int nodes(bt *root1)
{
    if (root1 == NULL)
    {
        return 0;
    }

    nodes(root1->left);
    count++;
    nodes(root1->right);
    return count;
}

int leafnodes(bt *root1)
{
    static int countl = 0;
    if (root1 == NULL)
    {
        return 0;
    }
    if (root1->left == NULL && root1->right == NULL)
    {
        printf("%d\t", root1->data);
        return 1;
    }
    else
    {
        return leafnodes(root1->left) + leafnodes(root1->right);
    }
}

void inorderIterative(bt *root)
{
    if (root != NULL)
    {
        // stack *st=(stack*)malloc(sizeof(stack));
        stack st;
        st.top = -1;
        int flag = 0;
        bt *temp = root;
        while (!flag)
        {
            while (temp != NULL)
            {
                push(&st, temp);
                temp = temp->left;
            }
            
            if (!isEmpty(&st))
            {
                temp = pop(&st);
                printf("%d\t", temp->data);
                temp = temp->right;
            }
            else
                flag = 1;
        }
    }
    else
    {
        printf("Empty tree\n");
    }
}


void preorderIterative(bt* root){
    if (root!=NULL){
        stack *st=(stack*)malloc(sizeof(stack));
        st->top=-1;
        bt *temp;
        push(st,root);
        while(!isEmpty(st)){
            temp=pop(st);
            printf("%d\t",temp->data);
            if (temp->left)
                push(st,temp->left);
            if (temp->right)
                push(st,temp->right);
        }
    }
    else{
        printf("Empty tree\n");
    }
}

void postorderIterative(bt* root){
    struct stack{
        bt* item;
        int flag;
    };
    struct stack s[100];
    int top=-1; 
    bt *temp;
    if (root==NULL){
        printf("Empty tree\n");
        return;
    }
    temp=root;
    while(1){
        while (temp!=NULL){
            s[++top].item=temp;
            s[top].flag=1;
            temp=temp->left; 
        }
        while(s[top].flag==-1){
            temp=s[top--].item;
            printf("%d\t",temp->data);
            if (top==-1)
                return;
        } 
        temp=s[top].item;
        temp=temp->right;
        s[top].flag=-1;
    }
}

int isEmpty1(Queue *q){
        // printf("in empty");

        if(q->rear == -1 && q->front== -1){
        return 1;}

        else return 0;

}

void levelorder(bt *tree){
    Queue q;
    int input, i;
    initialize(&q);
    q.front=q.rear=-1;
    bt *temp;
    temp=root;
    enqueue(&q, temp);

    while(isEmpty1(&q) == 0){


        temp=dequeue(&q);
        printf("%d\t", temp->data);
        if(temp->left != NULL)
        enqueue(&q, temp->left);
        if(temp->right!=NULL)
        enqueue(&q, temp->right);
    }

}
void iterHeight(bt *tree){
    Queue q;
    int input, i;
    initialize(&q);
    q.front=q.rear=-1;
    bt *temp;
    temp=root;
    enqueue(&q, temp);
int height=0;
    while(isEmpty1(&q) == 0){

        int nodeCount = q.rear - q.front + 1;
        while (nodeCount > 0) {

        temp=dequeue(&q);
        printf("%d\t", temp->data);
        if(temp->left != NULL)
        enqueue(&q, temp->left);
        if(temp->right!=NULL)
        enqueue(&q, temp->right);

        nodeCount--;
    }
    
    height++;}

printf("%d",height);
}
int main()
{

    int input, data;
    while (input != -1)
    {
        scanf("%d", &input);

        if (input == 1)
        {

            root = create();
            printf("%d", root->data);
        }
        if (input == 10)
        {

            roota = create();
            printf("%d", roota->data);
        }

        if (input == 2)
        {
            inorder(root);
        }
        if (input == 20)
        {
            inorder(merge);
        }
        if (input == 3)
        {
            preorder(root);
        }
        if (input == 4)
        {
            postorder(root);
        }
        if (input == 5)
        {
            coppy = copy(root);
        }
        if (input == 6)
        {
            int h = height(root);
            printf("%d", h);
        }
        if (input == 7)
        {
            int e = equal(root, roota);
            printf("%d", 3);
        }
        if (input == 9)
        {
            merge = MergeTrees(root, roota);
        }
        if (input == 11)
        {
            int c = nodes(root);
            printf("count is %d", c);
        }
        if (input == 12)
        {
            int d = leafnodes(root);
            printf("leaf node count is %d", d);
        }
        if (input == 13)
        {
            inorderIterative(root);
        }
        if (input == 14)
        {
            levelorder(root);
        }
        if (input == 15)
        {
            iterHeight(root);
        }
        if (input == 8)
        {
            int anc;
            printf("Enter acestors");
            scanf("%d", &anc);
            int e = ancestors(root, anc);
        }
    }
}