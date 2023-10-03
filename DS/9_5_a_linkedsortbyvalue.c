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
            printf("%d\t",t->data);
            t=t->next;
        }
        printf("\n");
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
            if((j->data)>(j->next->data))
            {
                t=j->data;
                j->data=j->next->data;
                j->next->data=t;
            }
        }
    }
}
int main()
{
    

    insert(100);
    insert(20);
    insert(300);
    insert(40);  
    insert(10);
    disp();
    sort();
    disp();  
} 