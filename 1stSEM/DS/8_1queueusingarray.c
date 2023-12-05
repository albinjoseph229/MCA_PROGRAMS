#include <stdio.h>
int q[30], n;
int f = -1, r = -1;
void enqueue(int e)
{
    if ((f == -1) && (r == -1))
    {
        f = r = 0;
        q[r] = e;
        printf("Enqueued element is :%d\n", q[r]);
    }

    else if (r == n - 1)
        printf("\nQueue Full\n");
    else
    {
        r++;
        q[r] = e;
        printf("Enqueued element is :%d\n", q[r]);
    }

}
void dequeue()
{
    if ((f == -1) && (r == -1))
        printf("\nqueue empty!!\n");
    else if (f == r)
    {
        printf("\nDequeued element is :%d\n", q[f]);
        r = f = -1;
    }
    else
    {
        printf("\nDequeued element is :%d\n", q[f]);
        f++;
    }
}
int menu()
{
    int ch;
    printf("\n 1-ENQUEUE\n 2-DEQUEUE\n 3-EXIT\n Enter the choice: ");
    scanf("%d", &ch);
    return ch;
}
int main()
{
    int i;
    printf("\nEnter the size of queue: ");
    scanf("%d", &n);
    for (i = menu(); i != 3; i = menu())
    {
        switch (i)
        {
        case 1:
            printf("\nEnter the value to enqueue: ");
            scanf("%d", &i);
            enqueue(i);
            break;
        case 2:
            dequeue();
            break;
        default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}
