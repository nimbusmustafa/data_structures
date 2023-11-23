#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int st[20];
    int tos;
} Stack;

void push(Stack *s,int ch) {
    (s->st)[++(s->tos)] = ch; 
}

int pop(Stack *s) {
    return s->st[(s->tos)--];
}

int operate(int op1,int op2,char operator) {
    switch (operator) {
        case '+': return (op1+op2);
        case '-': return (op1-op2);
        case '*': return (op1*op2);
        case '/': return (op1/op2);
        case '^': return (op1^op2);
        default: return 0;
    }
}

int main(){
    int i,j=0;
    char expr[20],temp;
    printf("Enter the prefix expression ");
    scanf("%s",expr);
    Stack s;
    s.tos=-1;

    int op1,op2;

    i = strlen(expr)-1;

    while( expr[i] != '\0' ) {
        if (expr[i]=='+' || expr[i]=='-' || expr[i]=='*' || expr[i]=='/'|| expr[i]=='^') {
            op2 = pop(&s);
            op1 = pop(&s);
            temp = operate(op2,op1,expr[i]);
            push(&s,temp);
        }
        /*else if(expr[i]==' ' || expr[i]== '\t'){
            continue;
        }*/
        else {
            temp = expr[i] - 48;
            push(&s,temp);
        }
        i--;
    } while( expr[i] != '\0' );

    printf("Final answer: %d",s.st[0]);
}