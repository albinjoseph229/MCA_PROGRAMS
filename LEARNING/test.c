#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}tree;

tree * root=NULL;

void insert()
{
    if(root==NULL);
    {
        root=(tree*)malloc(sizeof(tree));
        root->data=e;
        root->left=NULL;
        root->right=NULL;
    }
    else{
        tree *p = root;
        tree *x = NULL;
        while(p!=NULL){
            if(p->datae){
                x=p;
                p=p->left
            }
            else{
                x=p;
                p=p->right;
            }
            if(x->data<e){
                x->right=
            }
        }

    }
}