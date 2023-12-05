#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *ptr = NULL;
struct node *head = NULL;
void insert(int val)
{
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = val;
        head->next = NULL;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = (struct node *)malloc(sizeof(struct node));
        ptr->next->data = val;
        ptr->next->next = NULL;
    }
}

void sortList()
{
    struct node *current = head, *index = NULL;
    int temp;

    if (head == NULL)
    {
        return;
    }
    else
    {
        while (current != NULL)
        {

            index = current->next;
            while (index != NULL)
            {

                if (current->data > index->data)

                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}
void Sortaddress()
{
    int swapp, i;
    struct node *ptr1;
    struct node *lptr = NULL;

    if (head == NULL)
        return;

    do
    {
        swapp = 0;
        ptr1 = head;
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1, ptr1->next);
                swapp = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapp);
}
void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void display()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void main()
{
    int ch, val;
    while (1)
    {
        printf("\n1.Insert.\n2.Display linked list\n3.Sort by swapping values\n4.Sort by swapping address\n5.Exit\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number to insert :");
            scanf("%d", &val);
            insert(val);
            break;
        case 2:
            display();
            break;
        case 3:
            sortList();
            printf("\nSorted by swapping values");
            break;
        case 4:
            Sortaddress();
            printf("\nSorted by swapping address");
            break;
        case 5:
            exit(0);
            break;
        default:
        {
            printf("Wrong choice\n");
            break;
        }
        }
    }
}
