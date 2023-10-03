#include <stdio.h>
#include <malloc.h>
struct node
{
  int data;
  struct node *next;
};
struct node *head = NULL;
void insert(int e)
{
  struct node *t;
  if (head == NULL)
  {
    head = (struct node *)malloc(sizeof(struct node));
    head->data = e;
    head->next = NULL;
  }

  else
  {
    t = head;
    while (t->next != NULL)
    {
      t = t->next;
    }
    t->next = (struct node *)malloc(sizeof(struct node));
    t->next->data = e;
    t->next->next = NULL;
  }
}
void replace(int el, int e)
{
  struct node *t = head;
  if (head->data == el)
  {
    head->data = e;
  }
  else
  {
    while (t->next != NULL && t->data != el)
    {
      t = t->next;
    }
    if (t->next == NULL && t->data != el)
    {
      printf("Element not found");
    }
    else
      t->data = e;
  }
}
void display()
{
  if (head == NULL)
  {
    printf("Linked List Is Empty");
  }
  else
  {
    struct node *t;
    t = head;
    while (t != NULL)
    {
      printf("%d\t", t->data);
      t = t->next;
    }
    printf("\n");
  }
}
int main()
{
  insert(10);
  insert(20);
  insert(30);
  insert(40);
  display();
  replace(30, 33);
  replace(40, 43);
  display();
}
