#include<stdio.h>
#include<stdlib.h> // Include stdlib.h for malloc

struct node
{
    int data;
    struct node *next;
};

struct node* head = NULL;

void atend(int e)
{
    if (head == NULL)
    {
        head = (struct node*)malloc(sizeof(struct node));
        head->data = e;
        head->next = NULL; // Initialize next to NULL
    }
    else
    {
        struct node *t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = (struct node*)malloc(sizeof(struct node));
        t->next->data = e;
        t->next->next = NULL;
    }
}

void atbegin(int e)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newnode->data = e;
    newnode->next = head;
    head = newnode;
}

void disp()
{
    struct node *t = head;
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        while (t != NULL)
        {
            printf("%d\t", t->data);
            t = t->next;
        }
        printf("\n");
    }
}
void afterelement(int e,int n)
{
    struct node *t,*a;
    t=head;
    while((t->next!=NULL)&&(t->data!=n))
    {
        t=t->next;
    }
    if((t->next==NULL)&&(t->data!=n))
    {
        printf("element not found");

    }
    else{
        a=(struct node*)malloc(sizeof(struct node));
        a->data=e;
        a->next=t->next;
        t->next=a;
    }
}

int main()
{
    atend(10);
    atend(30);
    atbegin(20);
    afterelem(40,30);
    disp();

    // Free memory
    struct node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
