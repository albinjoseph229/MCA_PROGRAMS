/*Topic Title : Self Referential Structure Pointer
Description : Program of self referential structure with while loop for display. NULL is used to mark that there is not valid address.*/

#include <stdio.h>
#include <stdlib.h>
struct A
{
 int data;
 struct A *next;
};
int main()
{
 struct A *first,*t;
 first = (struct A *)malloc(sizeof(struct A));
 first->data =10;
 first->next = (struct A*)malloc(sizeof(struct A));
 first->next->data = 20;
 first->next->next = (struct A*)malloc(sizeof(struct A));
 first->next->next->data = 30;
 printf("%d %d %d\n",first->data,first->next->data,first->next->next->data);
 first->next->next->next = NULL;
 t = first;
 while(t != NULL)
 {
 printf("%d\t",t->data);
 t = t->next;
 }
 return 0;
}