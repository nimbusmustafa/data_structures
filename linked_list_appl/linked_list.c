#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *next ;
} LL;
LL *head=0;
LL *temp=0;

void create(){
    LL *newnode = (LL*)malloc(sizeof(LL));
    printf("Enter data\n");
    scanf("%d", &newnode->data);
    newnode->next= 0;

    if(head == 0){
        head=temp=newnode;
    }
    else{
        temp->next = newnode;
        temp=newnode;
    }
}

int length(){
    int count=0;
    LL *temp1;
    temp1=head;
    while(temp1!=0){
        temp1=temp1->next;
        count++;

    }
    printf("%d", count);
    return count;
}

void middleElement(){
    int count=1;
    int d= length();
    if(d%2==0)
    d=((d)/2 +1);
    else d=(d+1)/2;
    LL *temp1;
    temp1=head;
    while(count <(d)){
        temp1=temp1->next;
        count++;
    }
    printf("The middle element is %d", temp1->data);
}

void insertFront(){
    LL *newnode = (LL*)malloc(sizeof(LL));
    printf("Enter data\n");
    scanf("%d", &newnode->data);  
    newnode->next = head;
    head=newnode;    

}

void insertEnd(){
    LL *temp1=head;
    LL *newnode = (LL*)malloc(sizeof(LL));
    printf("Enter data\n");
    scanf("%d", &newnode->data);  
    newnode->next= 0;

    while(temp1->next!=0){
        temp1=temp1->next;
    }   
    temp1->next=newnode;
}

void insertafterPos(){
    int pos, i=1;
    LL *temp1;
    printf("enter the position\n");
    scanf("%d", &pos);
    temp1=head;
    while(i<pos){
        temp1=temp1->next;
        i++;
    }

    LL *newnode = (LL*)malloc(sizeof(LL));
    printf("Enter data\n");
    scanf("%d", &newnode->data); 
    newnode->next=temp1->next;
    temp1->next=newnode;
}


void insertPos(){
        int pos, i=1;
    LL *temp1;
    printf("enter the position\n");
    scanf("%d", &pos);
    temp1=head;
    while(i<pos-1){
        temp1=temp1->next;
        i++;
    }

    LL *newnode = (LL*)malloc(sizeof(LL));
    printf("Enter data\n");
    scanf("%d", &newnode->data); 
    newnode->next=temp1->next;
    temp1->next=newnode;
}

void delbeg(){
    LL *temp1;
    temp1=head;
    head=temp1->next;
    free(temp1);
}

void delend(){
    LL *temp1;

    temp1=head;
    LL *prevnode;
    while(temp1->next!=0){
        prevnode=temp1;
        temp1=temp1->next;
    }
    if(temp1==head){
        head=0;
    }
    else{
        prevnode->next=0;
        free(temp1);
    }

}

void delpos(){
    int pos, i=1;
    LL *temp1, *nextnode;
    printf("enter the position\n");
    scanf("%d", &pos);
    temp1=head;
    while(i<pos-1){
        temp1=temp1->next;
        i++;
    }
    nextnode=temp1->next;
    temp1->next=nextnode->next;
    free(nextnode);
}   

void display(){
    LL *temp1 = head;
    while (temp1->next !=0)
    {
        printf("%d\t", temp1->data);
        temp1=temp1->next;
    }
        printf("%d\t", temp1->data);
    
}

void reverse(){
    LL *prevnode, *currentnode, *nextnode;
    currentnode=nextnode=head;
    prevnode=0;
    while(nextnode!=0){
        nextnode= nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;

    }
    head=prevnode;
}

int main()
{
 int choice;
 printf("\n MENU \n");
 printf("\n 1.Create \n");
 printf("\n 2.Display \n");
 printf("\n 3.Insert at the beginning \n");
 printf("\n 4.Insert at the end \n");
 printf("\n 5.Insert after specified position \n");
 printf("\n 6.Delete from beginning \n");
 printf("\n 7.Delete from the end \n");
 printf("\n 8.Delete from specified position \n");
 printf("\n 9. Insert at specified position \n");
 printf("\n 10. Reverse \n");
 printf("\n 11. Length \n");
 printf("\n 12. MiddleElement \n");
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
     insertFront();
 }
  if(choice==4){
     insertEnd();
 }
  if(choice==5){
     insertafterPos();
 }
  if(choice==6){
     delbeg();
 }
  if(choice==7){
     delend();
 }
   if(choice==8){
     delpos();
 }
   if(choice==9){
     insertPos();
 }
   if(choice==10){
     reverse();
 }
   if(choice==11){
     length();
 }
   if(choice==12){
     middleElement();
 }
  if(choice==-1){
     break;
 }}}


