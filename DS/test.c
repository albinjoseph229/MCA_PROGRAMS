#include <stdio.h>
#include <malloc.h>
typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
} node;
struct node *head = NULL;
void insert(int e)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = e;
	if (head == NULL)
	{
		head = newnode;
		newnode->next = head;
		newnode->prev = head;
	}
	else
	{
		node *t = head;
		while (t->next != head)
		{
			t = t->next;
		}
		t->next = newnode;
		newnode->next = head;
		newnode->prev = t;
	}
}
void delete(int e)
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        if (head->data == e)
        {
            if (head->next == head)
            {
                head = NULL;
            }
            else
            {
                node *p = head->prev;
                head = head->next;
                head->prev = p;
                p->next = head;
            }
        }
		else
        {
            node *t = head;
            node *p = NULL;
            while (t->next != head && t->data != e)
            {
                p = t;
                t = t->next;
            }
            if (t->data == e)
            {
                p->next = t->next;
                t->next->prev = p;
            }
            else
            {
                printf("Element not found\n");
            }
        }
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        node *t = head;
        printf("%d\t", t->data);

        t = t->next;
        while (t != head) {
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
    delete(10);
    display();
    getchar();
	delete(100);
}


