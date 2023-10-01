#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
        head->prev = NULL;
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
        t->next->prev = t;
    }
}
void disp()
{
    struct node *t;
    if (head == NULL)
    {
        printf("linked list is empty");
    }
    else
    {
        t = head;
        while (t != NULL)
        {
            printf("%d\t", t->data);
            t = t->next;
        }
    }
}
void deleteNode(int key)
{
    struct node *t;
    struct node *p;

    if (head == NULL)
    {
        printf("List is empty");
    }
    else if (head->data == key)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
    }
    else
    {
        t = head;
        while (t != NULL && t->data != key)
        {
            p = t;
            t = t->next;
        }
        if (t == NULL)
        {
            printf("Element not found");
        }
        else
        {
            p->next = t->next;
            if (t->next != NULL)
            {
                t->next->prev = t->prev;
            }
            free(t);
        }
    }
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    disp();
    deleteNode(10);
    disp();
    return 0;
}