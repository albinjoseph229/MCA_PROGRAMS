#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
void insert(int e)
{
    struct node* t;
    if(head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node*));
        head->data=e;
        head->next=NULL;
    }
    else{
        t=head;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=(struct node*)malloc(sizeof(struct node*));
        t->next->data=e;
        t->next->next=NULL;
    }
}
void display()
{
    struct node* t;
    if(head==NULL)
    {
        printf("linked list is empty\n");
    }
    else{
        t=head;
        while(t!=NULL){
            printf("%d\n",t->data);
            t=t->next;
        }
    }
}
void delete(int e)
{
    if(head==NULL)
    {
        printf("linked list is empty");
    }
    else if(head->data==e)
    {
        head=head->next;
    }
    else{
        
    }
}
int main()
{
    insert(20);
    insert(30);
    insert(40);
    display();

}