#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void insert(int e)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = e;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *t;
        t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = newnode;
    }
    printf("\n%d is inserted", newnode->data);
}
void reverse()
{
    struct node *t = head;
    struct node *prev = NULL, *next = NULL;
    while (t != NULL)
    {
        next = t->next;
        t->next = prev;
        prev = t;
        t = next;
    }
    head = prev;
    printf("\nElements Are Reversed");
}
void display()
{
    if (head == NULL)
    {
        printf("\nLinked List Is Empty");
    }
    else
    {
        struct node *t = head;
        while (t != NULL)
        {
            printf("%d\t", t->data);
            t = t->next;
        }
        printf("\n");
    }
}
int menu()
{
    int ch;
    printf("\nEnter Your Choice \n1-Insert \n2-Display \n3-Reverse \n4-Exit\n");
    scanf("%d", &ch);
    return ch;
}
int main()
{
    int ch, e;
    for (ch = menu(); ch != 4; ch = menu())
    {
        switch (ch)
        {
        case 1:
            printf("\nEnter The Element To Insert: ");
            scanf("%d", &e);
            insert(e);
            break;
        case 2:
            display();
            break;
        case 3:
            reverse();
            break;
        default:
            printf("Invalid choice!");
            break;
        }
    }
}