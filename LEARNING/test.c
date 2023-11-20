#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[50];
    struct node* next;
} node;

node * head;

void insert(char* name){
    node* newnode=(node*)maaloc(sizeof(node));
    strcpy(newnode->name,name);
    newnode->next=head;
    head=newnode;
}
void display() {
    node* ptr = head;
    while (ptr != NULL) {
        printf("%s\n", ptr->name);
        ptr = ptr->next;
    }
}
void delete(char * name){
    node * temp=head,*prev;
    if(temp!=NULL && strcmp(temp->name,name)!=0){
        
    }
}