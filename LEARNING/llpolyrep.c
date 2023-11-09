#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

int n;
struct node *head = NULL;


void insertnode(){
    for(int i=0;i<n;i++){
        printf("enter the coefficient and exponent for term %d: ",i+1);
        struct node* newnode=(struct node *)malloc(sizeof(struct node));
        scanf("%d%d",&newnode->coeff,&newnode->exp);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
        }
        else{
            struct node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
}

void print()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL)
        {
            printf("+");
        }
    }
    printf("\n");
}
int main()
{
    printf("enter the number of tems");
    scanf("%d", &n);
    insertnode();
    print();
}