#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node node;
node *front,*rear;
void enqueue(int e)
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=e;
    newnode->next=NULL;
    if(rear==NULL)
    {
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeue()
{
    if(front==NULL)
    {
        printf("Queue is empty!");
    }
    node *t=front;
    front=front->next;
    printf("\nRemoved element is %d",t->data);
    if(front==NULL);
    {
        rear=NULL;
    }
    free(t);
}
void display()
{
    if(front==NULL)
    {
        printf("\nQueue is empty!");
    }
    else{
        struct node *t=front;
        printf("Queue Elements Are: ");
        while(t!=NULL)
        {
            printf("%d\t",t->data);
            t=t->next;
        }
        printf("\n");
    }
}
int menu()
{
    int ch;
    printf("\nEnter Your choice\n 1-Enqueue\n 2-Deque\n 3-Display\n 4-Exit\n");
    scanf("%d",&ch);
    return ch;
}
int main()
{
    int ch,e;
    for(ch=menu();ch!=4;ch=menu())
    {
        switch (ch)
        {
        case 1:
            printf("Enter The Element");
            scanf("%d",&e);
            enqueue(e);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            printf("\ninvalid choice!");
            break;
        }
    }
}