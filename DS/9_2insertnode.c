#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node* head=NULL;
void atend(int e){
    if(head==NULL){
        head=(struct node*)malloc(sizeof(struct node));
        head->data=e;
        head->next;
    }
    else{
        struct node *t;
        t=head;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=(struct node *)malloc(sizeof(struct node));
        t->next->data=e;
        t->next->next=NULL;
    }
}
void atbegin(int e)
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
        head=(struct node*)malloc(sizeof(struct node));
        head->data=e;
        head->next=t->next;

    }
}
void display()
{
    if(head==NULL)
    {
        printf("head is null");
    }
    else
    {
        struct node *t;
        t=head;
        while(t!=NULL) 
        {
            printf("%d\t",t->data);
            t=t->next;
        }  
    }
}
int main()
{
    atend(10);
    atbegin(20);
    display();
}