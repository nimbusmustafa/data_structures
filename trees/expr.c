#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define n 10

typedef struct node {
    char data;
    struct node *r, *l;
} Node;

typedef struct {
    Node* node[10];
    int top;
} Stack;

void push(Stack* s, Node* t) {
    s->top++;
    s->node[s->top] = t;
}

Node* pop(Stack* s) {
    Node* temp = s->node[s->top];
    s->top--;
    return temp;
}

Node* getnode() {
    return malloc(sizeof(Node));
}

Node* create(char c[]) {
    Stack s1;
    Stack* s = &s1;
    s->top = -1;

    for (int i = 0; c[i] != '\0'; i++) {
        char ch = c[i];
        Node* temp = getnode();
        temp->data = ch;
        temp->r = temp->l = NULL;

        if (isalnum(ch)) {
            push(s, temp);
        } else {
            temp->r = pop(s);
            temp->l = pop(s);
            push(s, temp);
        }
    }
    return pop(s);
}

void display(Node* root) {
    if (root) {
        if (root->l || root->r) {
            printf("(");
        }

        display(root->l);
        printf("%c\t", root->data);
        display(root->r);

        if (root->l || root->r) {
            printf(")");
        }
    }
}

int eval(Node* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->l == NULL && root->r == NULL) {
        return root->data - '0';
    }

    switch (root->data) {
        case '+':
            return eval(root->l) + eval(root->r);
        case '-':
            return eval(root->l) - eval(root->r);
        case '/':
            return eval(root->l) / eval(root->r);
        case '*':
            return eval(root->l) * eval(root->r);
        case '$':
        case '^':
            return pow(eval(root->l), eval(root->r));
        default:
            return 0;
    }
}

int main() {
    printf("Enter postfix expression: ");
    char c[10];
    scanf("%s", c);
    Node* root = create(c);
    printf("Infix:\n");
    display(root);
    printf("\nResult = %d\n", eval(root));

    return 0;
}
