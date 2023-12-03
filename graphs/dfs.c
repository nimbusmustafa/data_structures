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

int isEmpty(Stack *s)
{
    if (s->tos == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main(){

    Stack s;
    s.tos=-1;

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
push(&s, count);
while(isEmpty(&s)== 1){
    int node= pop(&s);
    // printf("%d", node);

    for (int j=0; j<10 ;j++){
        if(adj_matr[node][j]==1 && visited[j] == 0){
            printf("%d", j);
            visited[j]=1;
            push(&s, j);
        }
    }

}
}
