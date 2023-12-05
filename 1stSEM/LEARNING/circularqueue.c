#include<stdio.h>
int cq[5];
int f=-1,r=-1;
void enqueue()
{
    if(r+1%5==f)
    {
        printf("error queue is full!\n");
    }
    else{
        if(f==-1)
        {
            f=0;
        }
        printf("enter the element\n");
        r=(r+1)%5;
        scanf("%d",&cq[r]);
    }
}
void dequeue()
{
    if(f==-1)
    {
        printf("Error queue is empty!\n");
    }
    else if(f==r)
    {
        printf("Deleted element: %d",cq[f]);
        f=r=-1;
    }
    else
    {
        printf("Deleted element: %d",cq[f]);
        f=(f+1)%5;
    }
}
void display()
{
    int i;
    printf("\nfront=%d and rear=%d\nqueue elements are: ",f,r);
    if(r>f)
    {
        for(i=f;i<=r;i++)
        printf("%d\t",cq[i]);
    }
    else{
        for(i=f;i<=4;i++)
        {
            printf("%d\t",cq[i]);
        }
        for(i=0;i<=r;i++)
        {
            printf("%d\t",cq[i]);
        }
    }
}
int main()
{
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    display();
    enqueue();
    display();
}