#include<stdio.h>
#include<stdlib.h> // Include stdlib.h for malloc
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void insert(int e)
{
    if(head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node));
        head->data=e;
        head->next=NULL;
    }
    else{
        struct node *t;
        t=head;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=(struct node*)malloc(sizeof(struct node));
        t->next->data=e;
        t->next->next=NULL;

    }
}
void display()
{
    if(head==NULL)
    {
        printf("Linked List Is Empty");
    }
    else{
        struct node *t;
        t=head;
        while(t!=NULL)
        {
            printf("%d\t",t->data);
            t=t->next;
        }
        printf("\n");
    }
}
void atfront()
{
    if(head==NULL)
    {
        printf("Linked List Is Empty");
    }
    else{
        head=head->next;
        printf("First Element Deleted\n");
    }
}
void atend()
{
    if(head==NULL)
    {
        printf("Linked List Is Empty");
    }
    else
    {
        struct node *t;
        t=head;
        while(t->next->next!=NULL)
        {
            t=t->next;
        }
        printf("Last element  is deleted\n");
        t->next=NULL;
    }
}
void specified(int e)
{
    if(head == NULL)
    {
        printf("Linked List Is Empty");
    }
    else if(head->data == e)
    {
        head = head->next;
    }
    else
    {
        struct node *t = head;
        while(t->next != NULL && t->next->data != e)
        {
            t = t->next;
        }

        if(t->next != NULL)
        {
            struct node *temp = t->next;
            t->next = t->next->next;
            free(temp);
            printf("Node with data %d deleted\n", e);
        }
        else
        {
            printf("Element %d not found in the linked list\n", e);
        }
    }
}
int menu()
{
    int ch;
    printf("\n1-Insert Element \n2-Delete From Begining \n3-Delete From End \n4-Delete A Specified Element \n5-Display \n6-Exit \nEnter your choice: ");
    scanf("%d",&ch);
    return ch;
}
int main()
{
   int ch,e;
   for(ch=menu();ch!=6;ch=menu())
   {
        switch(ch)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d",&e);
                insert(e);
                break;
            case 2:
                atfront();
                break;
            case 3:
                atend();
                break;
            case 4:
                printf("Enter the element to be deleted: ");
                scanf("%d", &e);
                specified(e);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
            break;

        }
   }
  
}