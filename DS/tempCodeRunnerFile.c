#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void atend(int e)
{
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
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
        t->next = (struct node *)malloc(sizeof(struct node));
        t->next->data = e;
        t->next->next = NULL;
    }
}

void atbegin(int e)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newnode->data = e;
    newnode->next = head;
    head = newnode;
}

void afterelement(int e, int n)
{
    struct node *t, *a;
    t = head;
    while ((t->next != NULL) && (t->data != n))
    {

        t = t->next;
    }
    if ((t->next == NULL) && (t->data != n))
    {
        printf("element not found");
    }
    else
    {
        a = (struct node *)malloc(sizeof(struct node));
        a->data = e;
        a->next = t->next;
        t->next = a;
    }
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
int menu()
{
    int ch;
    printf("\n 1-At Begining \n 2-At End \n 3-After Element \n 4-Display \n 5-Exit \n Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}
int elemnt()
{
    int n;
    printf("Enter the element: ");
    scanf("%d", &n);
    return n;
}

int main()
{
    int ch;
    int n, m;
    for (ch = menu(); ch != 5; ch = menu())
    {
        switch (ch)
        {
        case 1:
            n = elemnt();
            atbegin(n);
            break;
        case 2:
            n = elemnt();
            atend(n);
            break;
        case 3:
            n = elemnt();
            printf("\nEnter the elemnt after which you want to enter new element: ");
            scanf("%d", &m);
            afterelement(n, m);
            break;
        case 4:
            disp();
            break;
        default:
            printf("invalid choice");
            break;
        }
    }

    return 0;
}
