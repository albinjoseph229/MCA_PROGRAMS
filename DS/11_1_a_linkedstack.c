#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
}*top=NULL,*head=NULL;

void push(int e)
{
    struct node *new= (struct  node*)malloc(sizeof(struct node));
    if(new==NULL)
    {
        printf("stack underflow");
        return;
    }
    new->data=e;
    new->next=top;
    top=new;
    printf("%d is pushed onto the stack\n",e);
    if(head==NULL)
    {
        head=new;
    }
}
void pop()
{
    if(top==NULL)
    {
        printf("stack underflow");
    }
    else
    {
        struct node *t = top;
        printf("%d is popped out",top->data);
        top=top->next;
    }
    if(top==NULL)
    {
        head==NULL;
    }
}
void peek()
{
    if(top==NULL)
    {
        printf("stack is empty");
    }
    printf("Element at top is %d\n",top->data);
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    peek();
    pop();
}