#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 20
typedef struct {
    int queue[n];
    int front, rear;
} Queue;
// void initialize(Queue *q){
//     q->queue = (int*)malloc(n * sizeof(int));

// }
void enqueue(Queue *q, int in){
    if(q->front==-1 && q->rear==-1){
        q->front=q->rear=0;
        q->queue[q->rear]=in;
    }
    else if(((q->rear+1)%n)== q->front){
        printf("queue is full");
    }
    else{
        q->rear=(q->rear+1)%n;
        q->queue[(q->rear)]= in;
    }
}

void dequeue(Queue *q){
    if(q->front==-1 && q->rear==-1){
        printf("queue is empty");
    }
    else if(q->front==q->rear){
        q->front==q->rear==-1;
    }
    else{
        q->front=(q->front+1)%n;
    }
}

void display(Queue *q){
    int i=q->front;
        if(q->front==-1 || q->rear==-1){
        printf("queue is empty");
}
else {
    while(i!=q->rear){
        printf("%d\t",q->queue[i]);
        i=(i+1)%n;
    }
    printf("%d", q->queue[q->rear]);
}

}

int main(){
    int expr[20];
    Queue q;
    int input, i;
    // initialize(&q);
    q.front=q.rear=-1;
    printf("enter 1 for enqueue, 2 for dequeue, 3 for display and 4 for exit");
    while(input!=-1){
        scanf("%d",&input);
        if(input==1){
            printf("enter number to be insertes");
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