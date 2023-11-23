#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} DLL;

DLL *head = 0, *tail;

void create()
{
    DLL *newnode = (DLL *)malloc(sizeof(DLL));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;

    if (head == 0)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void display()
{
    DLL *temp;
    temp = head;

    while (temp->next != 0)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d\t", temp->data);
}

void insertbeg()
{
    DLL *newnode = (DLL *)malloc(sizeof(DLL));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    head->prev = newnode;
    newnode->prev = 0;
    newnode->next = head;
    head = newnode;
}
void insertend()
{
    DLL *newnode = (DLL *)malloc(sizeof(DLL));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    tail->next = newnode;
    newnode->prev = tail;
    newnode->next = 0;
    tail = newnode;
}
void insertatpos(){
    int pos, i=1;
    DLL *temp1;
    printf("enter the position\n");
    scanf("%d", &pos);
    temp1=head;
    while(i<pos-1){
        temp1=temp1->next;
        i++;
    }

    DLL *newnode = (DLL*)malloc(sizeof(DLL));
    printf("Enter data\n");
    scanf("%d", &newnode->data); 
    newnode->prev=temp1;
    newnode->next=temp1->next;
    temp1->next= newnode;
    newnode->next->prev =newnode;


}

void delbeg(){
    DLL *temp;
    temp=head;
    head->next->prev= NULL;
    head= temp->next;
    free(temp);
}

void delend(){
    DLL *temp;
    temp=tail;
    temp->prev->next= NULL;
    tail=temp->prev;
    free(temp);
}

void delatpos(){
    int pos, i=1;
    DLL *temp1, *nextnode;
    printf("enter the position\n");
    scanf("%d", &pos);
    temp1=head;
    while(i<pos){
        temp1=temp1->next;
        i++;
    }
    temp1->prev->next=temp1->next;
    temp1->next->prev=temp1->prev;
    free(temp1);
}

void reverse(){
    DLL *current, *nextnode;
    current=head;

    while(current!=0){
        nextnode=current->next;
        current->next=current->prev;
        current->prev=nextnode;
        current=nextnode;
    }
    current=head;
    head=tail;
    tail=current;
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
    printf("\n -1.Exit \n");
    printf("\n--------------------------------------\n");
    printf("Enter your choice:\t");
    while (choice != -1)
    {

        scanf("%d", &choice);
        if (choice == 1)
        {
            create();
        }
        if (choice == 2)
        {
            display();
        }
        if (choice == 3)
        {
            insertbeg();
        }
        if (choice == 4)
        {
            insertend();
        }
        if (choice == 9)
        {
            insertatpos();
        }
        if (choice == 6)
        {
            delbeg();
        }
        if (choice == 7)
        {
            delend();
        }
        if (choice == 8)
        {
            delatpos();
        }
        if (choice == 10)
        {
            reverse();
        }
    }
}