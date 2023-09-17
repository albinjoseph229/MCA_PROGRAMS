#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node* next;
};
struct node * head=NULL;
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
void disp(){
    struct node *t;
    if(head==NULL){
        printf("linked list is empty");
    }
    else{
        t=head;
        while(t!=NULL){
            printf("\n%d\t",t->data);
            t=t->next;
        }
    }
}
void delete(int e)
{
    struct node *t;
    if(head==NULL)
    {
        printf("linked list is empty");
    }
    else if(head->data==e)
    {
        head=head->next;
    }
    else{
        t=head;
        while(t->next!=NULL && t->next->data!=e){
            t=t->next;
        }
        if(t->next==NULL){
            printf("\n element not found");
        }
        else{
            t->next=t->next->next;
            printf("\nelement removed");
        }
    }

}
int main()
{
    insert(10);
    insert(20);
    insert(30);
    disp();
    delete(30);
    disp();
}