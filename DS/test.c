#include<stdio.h>
#define MAX 5
int front=-1,rear=-1;
int dq[MAX];
int isempty() {
    return (front == -1 && rear == -1);
}

int isfull() {
    return (rear == MAX - 1 && front == 0) || (rear == front - 1);
}

void insertFront(int value)
{
    if(isfull())
    {
        printf("deque is full!\n");
    }
    else{
        if(isempty())
        {
            front=rear=0;
        }
        else if(front==0)
        {
            front=MAX-1;
        }
        else
        {
            front--;
        }
        dq[front]=value;
        printf("elemnt %d is inserted at the front\n",dq[front]);
    }
}
void insertRear(int value)
{
    if(isfull())
    {
        printf("deque is full!");
    }
    else
    {
        if(isempty())
        {
            front=rear=-1;
        }
        else if(rear=MAX-1)
        {
            rear=0;
        }
        else
        {
            rear++;
        }
        dq[rear]=value;
        printf("%d is inserted at rear",value);
    }
}
void deleteFront()
{
    if(isempty())
    {
        printf("Error deque is empty");
    }
    printf("deleted element is %d\n",dq[front]);
    if(front==rear)
    {
        front=rear=-1;
    }  
    else{
        front++;
    }
}
void deleteRear()
{
    if(isempty())
    {
        printf("deque is empty!\n");
    }
    if(front=rear)
    {
        front=rear=-1;
    }
    else if(rear==0)
    {
        rear=MAX-1;
    }
    else
    {
        rear--;
    }
}
int main()
{
    isempty();
    isfull();
    insertFront(10);
    insertRear(20);
    deleteFront();
    deleteRear();
    
}