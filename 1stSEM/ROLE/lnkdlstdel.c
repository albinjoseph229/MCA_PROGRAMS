#include <stdio.h>
#include <stdlib.h>
struct node
{
 int data;
 struct node *next;
};
typedef struct node node;
node *head = NULL;
void insert(int e)
{
 if(head == NULL) //case 1 when there is no element
 {
 head = (node *)malloc(sizeof(node)); //allocate memory to the head
 head->data = e; // copy the value
 head->next = NULL; //make the next as NULL
 }
 else //case 2 when one or more elements
 {
 node *t = head;
 while(t->next != NULL) // traverse up to the last node
 { //last node , its next is NULL
 t = t->next;
 }
 t->next = (node *)malloc(sizeof(node)); //allocate memory to the next of last node
 t->next->data = e; //copy the value
 t->next->next = NULL; // make the next of new node as null
 }
}
void delete(int e)
{
 node *t;
 int f = 0;
 if(head == NULL) //case 1:
 {
 printf("List is Empty");
 }
 else if(head->data == e) //case 2 data from head and one element (head will be null) or several elements
 {
 head = head->next;
 }
 else //case 3 element to be deleted is not head
 {
 t = head;
 while(t->next != NULL)
 {
 if(t->next->data == e)
 {
 t->next = t->next->next; //deleting intermediate or last node
 f = 1;
 break;
 }
 t= t->next;
 }
 if(f == 0) //case 4 element not found
 {
 printf("Not Found");
 }
 }
}
void display()
{
 node *t = head;
 if(t == NULL)
 {
 printf("List is Empty\n");
 return;
 }
 while (t != NULL)
 {
 printf("%d\t",t->data);
 t = t->next;
 }
 printf("\n\n");
}
int main()
{
 display();
 insert(10);
 insert(5);
 insert(20);
 delete (10);

 display();
 insert(50);
 insert(60);
 display();
 delete(60);
 display();
 return 0;
}