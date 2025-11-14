#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Code a node structure that is referenced by the variable name “car”.
//  It should contain the following member variables: 
//  make, model, year, color, price. Ask the user to enter their car’s information and save it in an instance of this structure.
//   Prompt the user to enter another car or quit the program. Create a singularly linked list of car structures. 
//   Print out the list of cars before exiting the program.
typedef struct Car{
char* make;
char* model;
int year;
char* color;
double price;
struct Car* car;
}node;

void printInfo(node *head)
{
}
node* addCar(node *head,)
{
struct Car* car1=malloc(sizeof(struct Car));

return car1;
}

int main(){
struct Car *head = NULL;
printf("Enter your car information\n");

addCar();



printInfo(head);
return 0;
}