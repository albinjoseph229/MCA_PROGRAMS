#include<stdio.h>
int queue[5];
int rear=-1;
int front=-1;
void enqueue(int data)
{
    if(rear==5)
    {
        printf("queue is full\n");
    }
    else{
        if(front==-1)
        {
            front=0;
        }
        rear++;
        queue[rear]=data;
        printf("element inserted sucessfully\n");
    }
}
void dequeue()
{
    if(front==-1)
    {
        printf("queue is empty \n");
    }
    else{
        printf("removed element is %d: \n",queue[front]);
        front++;
        if(front==rear)
        {
            front=rear=-1;
        }
    }

}
void display()
{
    int i;
    printf("\nqueue elements are: ");
    for(i=front;i<=rear;i++)
    {
        printf("%d\t",queue[i]);
    }
    
}
int main()
{
    // enqueue(10);
    // enqueue(20);
    // enqueue(30);
    // enqueue(40);
    // enqueue(50);
    // enqueue(40);
    // enqueue(50);
    // dequeue();
    // dequeue();
    enqueue(5);
    enqueue(8);
    enqueue(33);
    enqueue(11);
    enqueue(3);
    display();
    dequeue();
    display();
}