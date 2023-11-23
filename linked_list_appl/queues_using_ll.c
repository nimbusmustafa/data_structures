#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} LL;

LL *rear=0;
LL *front=0;

void enqueu(){
    LL *newnode = (LL *)malloc(sizeof(LL));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    newnode->next=0;
    if(front==0 && rear==0){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}
void display(){
    LL *temp;
    if(front==0 && rear==0){
        printf("Queue is empty");
    }
    else{
        temp=front;
        while(temp!=0){
            printf("%d\t", temp->data);
            temp=temp->next;
        }
    }
}
void dequeue(){
    LL *temp;
    if(front==0 && rear==0){
     printf("Queue is empty");
    }
    else{
    temp=front;
        printf("%d", temp->data);

    front=front->next;
    free(temp);
    
    }
    
    }


  
int main()
{
    int input;
    printf("\n 1. Display \n");
    printf("\n 2. Enqueue \n");
    printf("\n 3. Dequeue \n");

    while (input != -1)
    {
        scanf("%d", &input);

        if (input == 1)
        {
            display();
        }
        if (input == 2)
        {
            enqueu();
        }
        if (input == 3)
        {
            dequeue();
        }
        else
        {
            input == -1;
        }
    }
}
    