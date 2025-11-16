#include <stdio.h>
#include <stdlib.h>

//Define node structure - written in class
typedef struct node{
        int data;
        struct node* next;

}node;

//Print entire list - written in class
void printList(node *head)
{
        node *current;
        current = head;
        //printf("---- LIST ----\n");
        while(current != NULL)
        {
                printf("%d  ", current->data);
                current = current->next;
        }
        printf("\n");
}

//Insert node at beginning of the list - written in class
node *insertFront(node *head, int val)
{
        node *newNode;
        newNode = malloc(sizeof(node));

        newNode->data = val;
        newNode->next = NULL;

        if(head == NULL)
        {
                head = newNode;
        }else
                newNode->next = head;

        return newNode;
}

//Insert node at end of list - writen in class
void insertBack(node *head, int val)
{
        node *newNode=malloc(sizeof(node));

        newNode->data = val;
        newNode->next = NULL;

        node *current=head;

        while(current->next != NULL)
        {
                current = current->next;
        }
        current->next = newNode;
}

//Delete node at front of list - written in class
node *deleteFront(node *head)
{
        node *current = head;
        head = head->next;
        printf("deleting %d\n", current->data);
        free(current);

        return head;
}

//Delete node at end of list - written in class
void deleteBack(node *head)
{
        node *current=head;
        while(current->next->next != NULL)
        {
                current = current->next;
        }
        printf("deleting %d\n", current->next->data);
        free(current->next);

        current->next = NULL;
}

//Insert a node at a specified index in the middle of list
void insertMiddle(node *head,int val,int index)
{
    node* current=head;
    node* newNode=(node*)malloc(sizeof(node));

    newNode->data=val;
    newNode->next=NULL;

    for(int i=1;i<index;i++){
        current=current->next;
    }
    newNode->next=current->next;
    current->next=newNode;
}

//Delete a node at a specified index in the middle of list
void deleteMiddle(node *head,int index)
{
    node* current = head;
    for(int i=0;current != NULL && i<index-1;i++)
    {
        current=current->next;
    }
    node* nodeToDelete = current->next;
    printf("deleting %d\n", current->next->data);
    current->next=current->next->next;
    free(nodeToDelete);
}

//Delete the entire list
void deleteList(struct node** head)
{
    node* tmp = *head;
    if(*head != NULL)
    {
        while(*head != NULL)
        {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
        }
    }
}
//Delete the node containing a specified value in list
void deleteValue(node* head,int val)
{
    node* current = head;
    while(current->next->data != val)
    {
        current=current->next;
    }
    node* deleteNode = current->next;

    printf("deleting %d\n", current->next->data);
        current->next=current->next->next;

        free(deleteNode);
}

int main()
{
        //--DO NOT CHANGE THIS SECTION--//
        //Create and initialize head pointer
        node *head = NULL;

        //~~~~Insert Nodes~~~~//
        head = insertFront(head, 42);
        head = insertFront(head, 37);
        head = insertFront(head, 235);
        head = insertFront(head, 877);
        head = insertFront(head, 88);
        head = insertFront(head, 401);
        head = insertFront(head, 323);
        head = insertFront(head, 461);
        head = insertFront(head, 784);
        head = insertFront(head, 358);
        insertBack(head, 12);
        insertBack(head, 713);
        insertBack(head, 209);
        insertBack(head, 466);
        insertBack(head, 55);
        insertBack(head, 10);
        insertBack(head, 515);
        insertBack(head, 2);
        insertBack(head, 75);
        insertBack(head, 199);

        //Print the list
        printf("--Initial List--\n");
        printList(head);

        //--END OF SECTION--//


        //Insert the value 99 at index 5 of the linked list (using insertMiddle())
        insertMiddle(head,99,5);
        //Print the list
        printf("--List after inserting 99 at index 5--\n");
        printList(head);
   

        //Insert the value 32 at index 7 of the linked list (using insertMiddle())
        insertMiddle(head,32,7);
        //Print the list
        printf("--List after inserting 32 at index 7--\n");
        printList(head);


        //Delete the node at index 3 (using deleteMiddle())
        deleteMiddle(head,3);
        //Print the list
        printf("--List after deleting index 3--\n");
        printList(head);



        //Delete the node holding the value of 10 from the inked list (using deleteValue())
        deleteValue(head,10);
        //Print the list
        printf("--List after deleting value 10--\n");
        printList(head);


        //Delete the entire list (using deleteList())

        //Print the list
        deleteList(&head);
        printf("--Result of deleting entire list--\n");
        printList(head);
        return 0;
    }