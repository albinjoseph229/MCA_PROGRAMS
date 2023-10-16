#include <stdio.h>
#include <malloc.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node *front = NULL;
node *rear = NULL;
void enqueue(int e)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = e;
    newnode->next = NULL;
    if (front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        node *t = front;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next=newnode;
        rear=newnode;
    }
}
void display()
{
    if (front == NULL)
    {
        printf("Queue underflow");
    }
    else
    {
        node *t = front;
        while (t != NULL)
        {
            printf("%d\t", t->data);
            t=t->next;
        }
        printf("\n");
    }
}
void dequeue(){
    if(front==NULL){
        printf("Queue underflow");
    }
    else{
        node *temp=front;
        front=front->next;
        free(temp);
        if(front==NULL){
            rear=NULL;
        }
    }
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    display();
    return 0;
}