#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* lchild;
    struct node* rchild;
}node;

typedef struct {
    node *s[100];
    int top;
}stack;

void push(stack *ps, node* x) {
    ps->s[++(ps->top)] = x;
}

node* pop(stack *ps) {
    return (ps->s[(ps->top)--]);
}

int isEmpty(stack* ps) {
    return ps->top == -1;
}

node* createRecursive(){
    int ele;
    printf("Enter the element to inserted (-1 for no data): ");
    scanf("%d",&ele);
    if (ele==-1){
        return NULL;
    }
    node* newnode=(node*)malloc(sizeof(node));
    newnode->val=ele;
    printf("Enter lchild of %d:\n",ele);
    newnode->lchild=createRecursive();
    printf("Enter rchild of %d:\n",ele);
    newnode->rchild=createRecursive();
    return newnode;
}

node *createNode(int x) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->val = x;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

void createIterative(node** tree){
    stack *st=(stack*)malloc(sizeof(stack));
    st->top=-1;
    int x,ele;
    printf("Enter value of root ");
    scanf("%d",&x);
    node *new,*temp;
    new = createNode(x);
    push(st,new);
    *tree = new;
    printf("\n1. Enter left, 2. Enter right, 3. Move up, -1. Exit");
    do {
        printf("\nEnter choice ");
        scanf("%d",&x);
        switch (x){
            case 1:
                printf("Enter value to insert ");
                scanf("%d",&ele);
                temp = createNode(ele);
                push(st,new);
                new->lchild=temp;
                new=new->lchild;
                break;
            case 2:
                printf("Enter value to insert ");
                scanf("%d",&ele);
                temp = createNode(ele);
                push(st,new);
                new->rchild=temp;
                new=new->rchild;
                break;
            case 3:
                if (st->top == 0)
                    printf("Already at root");
                else 
                    new = pop(st);
                break;
        }
    } while(x != -1);
}

void inorderRecursive(node* root){
    if (root!=NULL){
        inorderRecursive(root->lchild);
        printf("%d\t",root->val);
        inorderRecursive(root->rchild);
    }
}

void inorderIterative(node* root){
    if (root!=NULL){
        // stack *st=(stack*)malloc(sizeof(stack));
        stack st;
        st.top=-1;
        int flag=0;
        node *temp=root;
        while(!flag){
            while(temp!=NULL){
                push(&st,temp);
                temp=temp->lchild;
            }
            if(!isEmpty(&st)){
                temp=pop(&st);
                printf("%d\t",temp->val);
                temp=temp->rchild;
            }
            else
                flag = 1;
        }
    } 
    else{
        printf("Empty tree\n");
    }
}

void preorderRecursive(node* root){
    if (root!=NULL){
        printf("%d\t",root->val);
        preorderRecursive(root->lchild);
        preorderRecursive(root->rchild);
    }
}

void preorderIterative(node* root){
    if (root!=NULL){
        stack *st=(stack*)malloc(sizeof(stack));
        st->top=-1;
        node *temp;
        push(st,root);
        while(!isEmpty(st)){
            temp=pop(st);
            printf("%d\t",temp->val);
            if (temp->lchild)
                push(st,temp->lchild);
            if (temp->rchild)
                push(st,temp->rchild);
        }
    }
    else{
        printf("Empty tree\n");
    }
}

void postorderRecursive(node* root){
    if (root!=NULL){
        postorderRecursive(root->lchild);
        postorderRecursive(root->rchild);
        printf("%d\t",root->val);
    }
}

void postorderIterative(node* root){
    struct stack{
        node* item;
        int flag;
    };
    struct stack s[100];
    int top=-1; 
    node *temp;
    if (root==NULL){
        printf("Empty tree\n");
        return;
    }
    temp=root;
    while(1){
        while (temp!=NULL){
            s[++top].item=temp;
            s[top].flag=1;
            temp=temp->lchild; 
        }
        while(s[top].flag==-1){
            temp=s[top--].item;
            printf("%d\t",temp->val);
            if (top==-1)
                return;
        } 
        temp=s[top].item;
        temp=temp->rchild;
        s[top].flag=-1;
    }
}

void levelorder(node* root){
    node** q=(node**)calloc(20,sizeof(node*));
    int front=0,rear=0;
    q[rear++]=root;
    while (front < rear) {
        node* temp = q[front++];
        printf("%d ", temp->val);
        if (temp->lchild != NULL) {
            q[rear++] = temp->lchild;
        }
        if (temp->rchild != NULL) {
            q[rear++] = temp->rchild;
        }
    }
    free(q);
}


int main(){
    // node* root=createRecursive();
    node* tree=(node*)malloc(sizeof(node));
    createIterative(&tree);
    // inorderRecursive(tree);
    inorderIterative(tree);
    printf("\n");
    // preorderRecursive(tree);
    preorderIterative(tree);
    printf("\n");
    // postorderRecursive(tree);
    postorderIterative(tree);
    printf("\n");
    levelorder(tree);
    printf("\n");
}
