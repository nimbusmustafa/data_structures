#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

int stack[N];
int top = -1;

int isFull()
{
    if (top == (N - 1))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int isEmpty()
{
    if (top == -1)
    {
        // printf("Stack underflow");
        return 0;
    }
    else
    {
        return 1;
    }
}

void push()
{
    int x;
    printf("Enter data");
    scanf("%d", &x);
    if (isFull())
    {
        top = top + 1;
        stack[top] = x;
    }
    else
    {
        printf("Stack overflow");
    }
}

void push1(int data){
        if (isFull())
    {
        top = top + 1;
        stack[top] = data;
    }
    else
    {
        printf("Stack overflow");
    }
}
int pop()
{
    if (isEmpty())
    {
        int popped =stack[top];
        // printf("%d popped", stack[top]);
        top--;
        return popped;
    }
    else{
        printf("Stack underflow");
    }
}

void display()
{
    int i;
    for (i = top; i > -1; i--)
    {
        printf("%d\t", stack[i]);
    }
}

void decimalToBinary(int decimal)
{
    while (decimal > 0)
    {
        int remainder = decimal % 2;
        push1(remainder);
        decimal = decimal / 2;
    }

    printf("Binary representation: ");
    while (isEmpty())
    {
        printf("%d", pop());
    }
    printf("\n");
}


int main()
{
    int input;
    printf("enter 1 for push, 2 for pop, 3 for display, 4 for dec to bin conversion and -1 for exit");
    while (input != -1)
    {
        scanf("%d", &input);
        if (input == 1)
        {
            push();
        }
        else if (input == 2)
        {
            pop();
        }
        else if (input == 3)
        {
            display();
        }
        else if (input == 4)
        {
            decimalToBinary(1234);
        }
        else
        {
            input = -1;
        }
    }
    return 0;
}