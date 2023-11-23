#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 100
typedef struct {
    int *queue;
    int front, rear;
} Queue;

void initialize(Queue *q){
        q->queue = (int*)malloc(n * sizeof(int));

}

void enqueue(Queue *q, int x){
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

void dequeue(Queue *q){
    if(q->rear == -1 && q->front== -1){
        printf("Stack underflow");

    }
    else if(q->front == q->rear){
                q->rear=q->front=-1;

    }
    else{
        printf("%d", q->queue[q->front]);
        q->front++;
    }
}


void display(Queue *q){
    if(q->front == -1 && q->rear==-1){
        printf("Queue is empty nigga");
    }
    else{
        for(int i = q->front ; i <= q->rear ; i++){
            printf("%d\t", q->queue[i]);
        }
    }
}

int main(){
    // int expr[20];
    Queue q;
    int input, i;
    initialize(&q);
    q.front=q.rear=-1;
    printf("enter 1 for enqueue, 2 for dequeue, 3 for display and 4 for exit");
    while(input!=-1){
        scanf("%d",&input);
        if(input==1){
            printf("enter number to be inserted");
            scanf("%d", &i);
            enqueue(&q, i);
        }
        else if(input==2){
            dequeue(&q);
        }
        else if(input==3){
            display(&q);
        }
        else{
            input=-1;
        }
    }
}