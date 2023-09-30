#include<stdio.h>
#include<stdlib.h> // Include stdlib.h for malloc
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void insert(int e)
{
    if(head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node));
        head->data=e;
        head->next=NULL;
    }
    else{
        struct node *t;
        t=head;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=(struct node*)malloc(sizeof(struct node));
        t->next->data=e;
        t->next->next=NULL;

    }
}
void display()
{
    if(head==NULL)
    {
        printf("Linked List Is Empty");
    }
    else{
        struct node *t;
        t=head;
        while(t!=NULL)
        {
            printf("%d\t",t->data);
            t=t->next;
        }
        printf("\n");
    }
}
void atfront()
{
    if(head==NULL)
    {
        printf("Linked List Is Empty");
    }
    else{
        head=head->next;
        printf("First Element Deleted\n");
    }
}
void atend()
{
    if(head==NULL)
    {
        printf("Linked List Is Empty");
    }
    else
    {
        struct node *t;
        t=head;
        while(t->next->next!=NULL)
        {
            t=t->next;
        }
        printf("Last element  is deleted\n");
        t->next=NULL;
    }
}
void specified(int e)
{
    if(head == NULL)
    {
        printf("Linked List Is Empty");
    }
    else if(head->data == e)
    {
        head = head->next;
    }
    else
    {
        struct node *t = head;
        while(t->next != NULL && t->next->data != e)
        {
            t = t->next;
        }

        if(t->next != NULL)
        {
            struct node *temp = t->next;
            t->next = t->next->next;
            free(temp);
            printf("Node with data %d deleted\n", e);
        }
        else
        {
            printf("Element %d not found in the linked list\n", e);
        }
    }
}

int main()
{
    insert(10);
    insert(300);
    insert(20);
    insert(100);
    insert(200);
    insert(300);
    display();
    atfront();
    atend();
    specified(20);
    display();
}