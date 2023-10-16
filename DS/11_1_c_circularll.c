#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;
node *head=NULL;

void insert(int e){
	node *newnode=(node*)malloc(sizeof(node));
	newnode->data=e;
	if(head==NULL){
		newnode->next=newnode;
		head=newnode;
	}
	else{
		node *t=head;
		while(t->next!=head)
		{
			t=t->next;
		}
		newnode->next=head;
		t->next=newnode;	
	}
}
void display()
{
	if(head==NULL)
	{
		printf("Linked list is empty\n");
	}
	else{
		node *t=head;
		printf("%d\t", t->data);
		t=t->next;
		while(t!=head)
		{
			printf("%d\t",t->data);
			t=t->next;
		}
		printf("\n");
	}
}
void delete(int e) {
	node *t=head;
    if(head==NULL){
    	printf("linked list is empty\n");
	}
	else if(head->data==e)
	{
		if(head->next==head){
			printf("%d is deleted\n",e);
			head=NULL;
		}
		else{
			
			while(t->next!=head){
				t=t->next;
			}
			printf("%d is deleted\n",e);
			head=head->next;
			t->next=head;
		}
	}
	else{
		while(t->next!=head && t->next->data!=e){
			t=t->next;
		}
		if(t->next->data==e){
			printf("%d is deleted\n",t->next->data);
			t->next=t->next->next;
		}
		else{
			printf("element not found\n");
		}
	}
}
int main()
{
	insert(10);
	insert(29);
	insert(33);
	insert(50);
	display();
	delete(33);
	delete(10);
	delete(50);
	delete(100);
	insert(5);
	display();
	return 0;
}
