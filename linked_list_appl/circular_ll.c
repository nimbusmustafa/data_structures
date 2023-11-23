#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *next ;
} LL;

LL *tail=0;

void create(){
    LL *newnode = (LL*)malloc(sizeof(LL));
    printf("Enter data\n");
    scanf("%d", &newnode->data);
    newnode->next= 0;

    if(tail==0){
      tail=newnode;
      tail->next=newnode;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
}

void display(){
    LL *temp1;
    temp1=tail->next;
    while(temp1->next != tail->next){
        printf("%d\t", temp1->data);
        temp1=temp1->next;
    }
        printf("%d\t", temp1->data);
}

void insertbeg(){
    LL *newnode = (LL*)malloc(sizeof(LL));
    printf("Enter data\n");
    scanf("%d", &newnode->data);  
    newnode->next= tail->next;
    tail->next=newnode;
    printf("%d", tail->next->data);

}

void insertend(){
    LL *newnode = (LL*)malloc(sizeof(LL));
    printf("Enter data\n");
    scanf("%d", &newnode->data);
    newnode->next=tail->next;
    tail->next=newnode; 
    tail=newnode;   
        printf("%d", tail->next->data);

}

void delbeg(){
    LL *temp1;
    temp1=tail->next;
    tail->next=temp1->next;
    free(temp1);
        printf("%d", tail->next->data);

}

void delend(){
       LL *temp1;

    temp1=tail->next;
    LL *prevnode;
    while(temp1->next!=tail->next){
        prevnode=temp1;
        temp1=temp1->next;
    }


        prevnode->next=tail->next;
        tail=prevnode;
        free(temp1);
            printf("%d", tail->next->data);

    

}

void reverse(){
    LL *prevnode, *currentnode, *nextnode;
    currentnode=tail->next;
    nextnode=currentnode->next;
    prevnode=0;

    while(currentnode != tail){
        prevnode=currentnode;
        currentnode=nextnode;
        nextnode=currentnode->next;
        currentnode->next=prevnode;
    }
    nextnode->next=tail;
    tail=nextnode;
}


int main()
{
 int choice;
  printf("\n MENU \n");
 printf("\n 1.Create \n");
 printf("\n 2.Display \n");
 printf("\n 3.Insert at the beginning \n");
 printf("\n 4.Insert at the end \n");
 printf("\n 5.Insert at specified position \n");
 printf("\n 6.Delete from beginning \n");
 printf("\n 7.Delete from the end \n");
 printf("\n 8.Delete from specified position \n");
 printf("\n -1.Exit \n");
 printf("\n--------------------------------------\n");
 printf("Enter your choice:\t");
 while(choice != -1){

 scanf("%d",&choice);
 if(choice==1){
     create();
 }
  if(choice==2){
     display();
 }
  if(choice==3){
     insertbeg();
 }
  if(choice==4){
     insertend();
 }

  if(choice==6){
     delbeg();
 }
  if(choice==7){
     delend();
 }
   if(choice==10){
     reverse();
 }

  if(choice==-1){
     break;
 }}}


