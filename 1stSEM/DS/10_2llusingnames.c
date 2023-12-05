#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    char data[20];
    struct node *next;
};
typedef struct node node;
node *head = NULL;
void insert(char e[])
{
    if (head == NULL)
    {
        head = (node *)malloc(sizeof(node));
        strcpy(head->data, e);
        head->next = NULL;
    }
    else
    {
        node *t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = (node *)malloc(sizeof(node));
        strcpy(t->next->data, e);
        t->next->next = NULL;
    }
}
void delete_elem(char e[])
{
    node *t;
    int f = 0;
    if (head == NULL)
    {
        printf("\nList is Empty\n");
    }
    else if (strcmp(head->data, e) == 0)
    {
        head = head->next;
    }

    else
    {
        t = head;
        while (t->next != NULL)
        {
            if (strcmp(t->next->data, e) == 0)
            {
                t->next = t->next->next;
                f = 1;
                break;
            }
            t = t->next;
        }
        if (f == 0)
        {
            printf("\n%s not found\n", e);
        }
    }
}
void display()
{
    node *t = head;
    if (t == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    printf("\nNames in the linked list are:");
    while (t != NULL)
    {
        printf("\t%s", t->data);
        t = t->next;
    }
    printf("\n\n");
}
void sort()
{
    node *temp1 = head, *temp2;
    char elem[20];
    if (head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    while (temp1 != NULL)
    {
        temp2 = temp1->next;
        while (temp2 != NULL)

        {
            if (strcmp(temp1->data, temp2->data) > 0)
            {
                strcpy(elem, temp1->data);
                strcpy(temp1->data, temp2->data);
                strcpy(temp2->data, elem);
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    display();
}

void reverse(node *tmp)
{
    if (tmp == NULL)
    {
        return;
    }
    else
    {
        reverse(tmp->next);
    }
    printf("\t%s", tmp->data);
}
void count()
{
    node *tmp = head;
    int count = 0;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    printf("\nNumber of elements in the linked list: %d", count);
}
int main()
{
    int ch;
    char e[20];
    do
    {
        printf("\nLinked list\n============\n 1.Insertion\n 2.Deletion \n 3.Display\n 4.Sort\n 5.Reverse \n 6.Count\n 7.Exit\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {

        case 1:
            fflush(stdin);
            printf("\nEnter the name to insert: ");
            gets(e);
            insert(e);
            break;
        case 2:
            fflush(stdin);
            printf("\nEnter the name you want to delete: ");
            gets(e);
            delete_elem(e);
            break;
        case 3:
            display();
            break;
        case 4:
            sort();
            break;
        case 5:
            if (head == NULL)
                printf("\nList is empty\n");
            else
            {
                printf("\nNames in the linked list in reverse order:");
                reverse(head);
            }
            break;
        case 6:
            count();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
        }
    } while (ch != 7);
    return 0;
}
