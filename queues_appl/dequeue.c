#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 20

typedef struct
{
    int deque[n];
    int front, rear;
} Queue;

void enqueueFront(Queue *q, int in)
{
    if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
        q->deque[q->front] = in;
    }
    else if (((q->rear + 1) % n) == q->front)
    {
        printf("Queue is full\n");
    }
    else if (q->front == 0)
    {
        q->front = n-1;
        q->deque[q->front] = in;
    }
    else
    {
        q->front--;
        q->deque[q->front] = in;
    }
}

void enqueueRear(Queue *q, int in)
{
    if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
        q->deque[q->rear] = in;
    }
    else if (((q->rear + 1) % n) == q->front)
    {
        printf("Queue is full\n");
    }
    else if (q->rear == n - 1)
    {
        q->rear = 0;
        q->deque[q->rear] = in;
    }
    else
    {
        q->rear++;
        q->deque[q->rear] = in;
    }
}

void dequeueFront(Queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf("Queue is empty\n");
    }
    else if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else if (q->front == n - 1)
    {
        printf("%d\n", q->deque[q->front]);
        q->front = 0;
    }
    else
    {
        printf("%d\n", q->deque[q->front]);
        q->front++;
    }
}

void dequeueRear(Queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf("Queue is empty\n");
    }
    else if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else if (q->rear == 0)
    {
        printf("%d\n", q->deque[q->rear]);
        q->rear = n - 1;
    }
    else
    {
        printf("%d\n", q->deque[q->rear]);
        q->rear--;
    }
}

void display(Queue *q)
{
    int i = q->front;
    if (q->front == -1 || q->rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        while (i != q->rear)
        {
            printf("%d\t", q->deque[i]);
            i = (i + 1) % n;
        }
        printf("%d\n", q->deque[q->rear]);
    }
}

int main()
{
    Queue q;
    int input=0, i;

    q.front = q.rear = -1;

    printf("Enter 1 for enqueueFront, 2 for enqueueRear, 3 for dequeueFront, 4 for dequeueRear, and 5 for display\n");

    while (input != -1)
    {
        scanf("%d", &input);
        if (input == 1)
        {
            printf("Enter number to be inserted: ");
            scanf("%d", &i);
            enqueueFront(&q, i);
        }
        if (input == 2)
        {
            printf("Enter number to be inserted: ");
            scanf("%d", &i);
            enqueueRear(&q, i);
        }
        else if (input == 3)
        {
            dequeueFront(&q);
        }
        else if (input == 4)
        {
            dequeueRear(&q);
        }
        else if (input == 5)
        {
            display(&q);
        }
        else if(input ==-1)
        {
            break;
        }
    }

    return 0;
}
