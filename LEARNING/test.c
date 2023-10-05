#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
};
struct node * head=NULL;
void atbeginning(int e)
{
    struct node *t=head;
    head=(struct node*)malloc(sizeof(struct node));
        head->data=e;
        head->next=t;

}
void insertatmiddle(int e,int el)
{
    struct node *t=head;
    struct node *a;
    if(head==NULL)
    {
        printf("\nLinked List is empty");
    }
    
    else if(head->data==el)
    {
        head->next=(struct node*)malloc(sizeof(struct node));
        head->next->data=e;
        head->next->next=NULL;
    }
    else {
        while(t->next!=NULL&&t->data!=el)
        {
            t=t->next;
        }
        if(t->next==NULL&&t->data!=el)
        {
            printf("Element not found");
        }
        else{
            struct node *a=(struct node *)malloc(sizeof(struct node));
            a->data=e;
            a->next=t->next;
            t->next=a;
            
        }
    }
}
void insert(int e){
    struct node *t;
    if(head==NULL){
        head=(struct node*)malloc(sizeof(struct node));
        head->data=e;
        head->next=NULL;
    }

    else{
        t=head;
        while(t->next != NULL){
            t=t->next;
        }
        t->next=(struct node *)malloc(sizeof(struct node));
        t->next->data=e;
        t->next->next=NULL;
    }

}
void search(int e) {
    if (head == NULL) {
        printf("Linked list is empty");
    } else {
        struct node *t = head;
        while (t != NULL) {
            if (t->data == e) {
                printf("%d Found", t->data);
                return;  // Element found, so exit the function
            }
            t = t->next;
        }
        printf("\nElement not found");
    }
}
void sort()
{
    struct node *i,*j;
    int t;
    for(i=head;i->next!=NULL;i=i->next)
    {
        for(j=head;j->next!=NULL;j=j->next)
        {
            if(j->data>j->next->data)
            {
                t=j->data;
                j->data=j->next->data;
                j->next->data=t;
            }
        }
    }
    printf("Sorted sucessfully");
}
void display()
{
    if(head==NULL)
    {
        printf("\nLinked list is empty!");
    }
    else{
        struct node *t=head;
        while(t!=NULL){
            printf("%d\t",t->data);
            t=t->next;
        }
    }
    
}
void reverse()
{
    if(head==NULL)
    {
        printf("\nLinked List IS Empty");
    }
    else{
        struct node *next=NULL,*prev=NULL;
        struct node *t=head;
        while(t!=NULL)
        {
            next=t->next;
            t->next=prev;
            prev=t;
            t=next;
        }
        head=prev;
    }
}
int main()
{
    //insertatmiddle(10,220)
    insert(220);
    insertatmiddle(10,220);
    insert(300);
    insert(31);
    insert(10);
    insert(20);
    insertatmiddle(440,20);
    insert(30);
    insert(40);
    atbeginning(60);
    display();
    printf("\n");
    sort();
    reverse();
    display();
}