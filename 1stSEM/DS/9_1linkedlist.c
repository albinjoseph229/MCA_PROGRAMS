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
	printf("\n%d is inserted", e);
}
void disp()
{
	struct node *t;
	if (head == NULL)
	{
		printf("Linked List Is Empty");
	}
	else
	{
		t = head;
		printf("\nLinked list elements are:\n");
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
	disp();
	insert(10);
	insert(20);
	insert(30);
	disp();
	return 0;
}
