#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void atend(int e)
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

void atinter(int e, int el)
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
        while (t->next != NULL && t->data != el)
        {
            t = t->next;
        }
        if (t->next == NULL && t->data != el)
        {
            printf("Element not found\n");
        }
        else
        {
            struct node *newnode;
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = e;
            newnode->next = t->next;
            t->next = newnode;
        }
    }
}

void atbeginning(int e)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = e;
    newnode->next = head;
    head = newnode;
}

void disp()
{
    struct node *t;
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        t = head;
        while (t != NULL)
        {
            printf("%d\t", t->data);
            t = t->next;
        }
        printf("\n");
    }
}

void delete(int e)
{
    struct node *t = head; // Initialize t to head
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else if (head->data == e)
    {
        head = head->next;
        free(t); // Free the memory of the deleted node
        printf("Element removed\n");
    }
    else
    {
        while (t->next != NULL && t->next->data != e)
        {
            t = t->next;
        }
        if (t->next == NULL)
        {
            printf("Element not found\n");
        }
        else
        {
            struct node *temp = t->next;
            t->next = t->next->next;
            free(temp); // Free the memory of the deleted node
            printf("Element removed\n");
        }
    }
}

int main()
{
    atend(10);
    atend(30);
    atend(20);
    atinter(50, 30);
    atbeginning(40);
    disp();
    delete (30);
    disp();

    // Free memory
    struct node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
