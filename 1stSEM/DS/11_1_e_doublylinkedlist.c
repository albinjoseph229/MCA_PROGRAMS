#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node dll;
dll *head = NULL;
void insert(int a)
{
    dll *t;
    if (head == NULL)
    {
        head = (dll *)malloc(sizeof(dll));
        head->data = a;
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        for (t = head; t->next != NULL; t = t->next)
            ;
        t->next = (dll *)malloc(sizeof(dll));
        t->next->data = a;
        t->next->next = NULL;
        t->next->prev = t;
    }
    printf("\n%d is inserted\n",a);
}
void delete(int a)
{
    dll *t;
    if (head == NULL)
        printf("D L L is empty");
    else if (head->data == a)
    {
        if (head->next == NULL)
            head = NULL;
        else
        {
            head = head->next;
            head->prev = NULL;
        }
        printf("\n %d is deleted\n",a);
    }
    else
    {
        for (t = head; t != NULL && t->data != a; t = t->next)
            ;
        if (t == NULL)
            printf("Element Not Found");

        else if (t->next == NULL)
            t->prev->next = NULL;
        else
        {
            t->next->prev = t->prev;
            t->prev->next = t->next;
        }
        printf("\n %d is deleted\n",a);
    }
}
void disp()
{
    dll *t;
    for (t = head; t != NULL; t = t->next)
    {
        printf("%d\t", t->data);
    }
}
int main()
{
    int ch, e, n;
    printf("\n DOUBLY LINKED LIST\n-------------------\n");
    do
    {
        printf("\n1.Insertion\n2.Deletion\n3.Display\n4.exit\nchoose your option:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element:");
            scanf("%d", &e);
            insert(e);
            break;
        case 2:
            printf("\nEnter element to be deleted:");
            scanf("%d", &n);
            delete (n);
            break;
        case 3:
            disp();
            break;
        case 4:
            exit(1);
            break;
        }
    } while (1);
    return 0;
}
