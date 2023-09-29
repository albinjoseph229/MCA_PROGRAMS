#include<stdio.h>
#include<stdlib.h> // Include stdlib.h for malloc
struct node
{
    int data;
    struct node *next;
}
Struct node*  head=NULL;
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
        while(t-next!=NULL)
        {
            t=t->next;
        }
        t->next=(struct node*)malloc(sizeof(structt node));
        t->next->data=e;
        t->next->next=NULL;

    }
}