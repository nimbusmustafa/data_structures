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

    // printf("in enqueu");
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

int isEmpty(Queue *q){
        // printf("in empty");

        if(q->rear == -1 && q->front== -1){
        return 1;}

        else return 0;

}

int dequeue(Queue *q){

        // printf("in dequeu");

    if(q->rear == -1 && q->front== -1){
        printf("Stack underflow");
        return 0;

    }
    else if(q->front == q->rear){
                int j= q->queue[q->front];

                q->rear=q->front=-1;
                return j;

    }
    else{
        int j= q->queue[q->front];
        // printf("%d", q->queue[q->front]);
        q->front++;
        return j;
    }
}

int main(){
    Queue q;
    int  i;
    initialize(&q);
    q.front=q.rear=-1;
int visited[10] = {0,0,0,0,0,0,0,0,0,0};
int adj_matr[][10]={
{0,1,1,0,1,0,0,1,0,0},
{1,0,0,1,0,1,0,0,1,0},
{1,0,0,0,1,0,0,0,1,0},
{0,0,1,0,0,0,0,0,1,0},
{1,1,0,0,0,0,1,0,0,0},
{0,1,0,0,0,0,0,0,0,1},
{0,1,0,0,1,0,0,0,0,0},
{1,0,0,0,0,0,0,0,0,0},
{0,0,1,1,0,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0},
};
int count = 0;
// printf("%d", count);
visited[count]=1;
enqueue(&q, count);

while(isEmpty(&q)== 0){
    int node= dequeue(&q);
    // printf("%d", node);

    for (int j=0; j<10 ;j++){
        if(adj_matr[node][j]==1 && visited[j] == 0){
            printf("%d", j);
            visited[j]=1;
            enqueue(&q, j);
        }
    }

}
}