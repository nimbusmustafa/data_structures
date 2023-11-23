#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count;
typedef struct {
    char str[20];
    int tos;
} Stack;

void push(Stack *s, int ch){
  
        int c=s->str[++s->tos]=ch;
    }
int pop(Stack *s){
    int ch= s->str[s->tos--];
   // printf("Popped %c\n",ch);
    return ch;
}

void enqueue(Stack *s1, Stack *s2, int x){
    push(s1, x);
    count++;
}

void dequeue(Stack *s1, Stack *s2){
    int i;
    for(i=0; i <count;i++){
        int a = pop(s1);
        push(s2, a);
    }
    int b = pop(s2);
    printf("dequeued element is %d", b); 
   count--;
    for (i = 0 ; i< count; i++){
        int a = pop(s2);
        push(s1, a);
    }
}


void display(Stack *s){
  for (int i =0; i<=s->tos ; i++){
    printf("%d\t", s->str[i]);
  }
}

int main(){
    // int expr[20];
    Stack s1,s2;
    int input, i;
    // initialize(&q);
    s1.tos = s2.tos =-1;
    printf("enter 1 for enqueue, 2 for dequeue, 3 for display and 4 for exit");
    while(input!=-1){
        scanf("%d",&input);
        if(input==1){
            printf("enter number to be inserted");
            scanf("%d", &i);
            enqueue(&s1,&s2, i);
        }
        else if(input==2){
            dequeue(&s1, &s2);
        }
        else if(input==3){
            display(&s1);
        }
        else{
            input=-1;
        }
    }
}