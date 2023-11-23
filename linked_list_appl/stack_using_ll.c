#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} LL;
LL *top = 0;
LL *temp = 0;

void push()
{
    LL *newnode = (LL *)malloc(sizeof(LL));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = top;
    top = newnode;
}

void pop()
{
    LL *temp;
    temp = top;
    printf("popped element is %d", top->data);
    top = top->next;
    free(temp);
}

void display()
{
    LL *temp;
    temp = top;
    while (temp != 0)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int input;
    printf("\n 2. Display \n");
    printf("\n 3. Push \n");
    printf("\n 4. Pop \n");

    while (input != -1)
    {
        scanf("%d", &input);

        if (input == 2)
        {
            display();
        }
        if (input == 3)
        {
            push();
        }
        if (input == 4)
        {
            pop();
        }
        else
        {
            input == -1;
        }
    }
}