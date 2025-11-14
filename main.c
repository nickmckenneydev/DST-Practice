#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int data;
struct node* next;
}node;

void printList(node* head)
{
    node* current=head;
    printf("==== Linked List ====");
    printf("\n");
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
}
void printBackWards(node* head)
{
    if (head == NULL) {
        return;
    }
    printBackWards(head->next);
    printf("%d ", head->data);
}
void insertBack(node** head,int v)
{
    node *newNode=(node*)malloc(sizeof(node));
    node *current = *head;
    newNode->data=v;
    newNode->next=*head;
    if(*head==NULL){
        *head=newNode;
         newNode->next=*head;
    }
    else{
    while(current->next!=*head)
    {
        current=current->next;
    }
    current->next=newNode;
     newNode->data=*head;
}
}
int main(){
    node* head = NULL;
    printf("What size should the linked list be? ");
    int size;
    scanf("%d",&size);
    int input;
    for(int i=1;i<=size;i++)
    {
    printf("Enter value %d: ", i); 
    scanf("%d", &input);
    printf("\n");
    insertBack(&head,input);
    }

printList(head);
printf("\n");
printBackWards(head);
return 0;
}