#include <stdio.h>
#include <malloc.h>


typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}tree;

tree *root=NULL;

void insert(int e)
{
    tree *p,*x;
    if(root==NULL)
    {
        root=(tree*)malloc(sizeof(tree));
        root->data=e;
        root->left=NULL;
        root->right=NULL;
    }
    else
    {
        
        p=root;
        x=root;
        while(p!=NULL)
        {
            x=p;
            if(e>p->data)
            {
                p=p->right;
            }
            else
            {
                p=p->left;
            }
        }
        if(e>x->data)
        {
            x->right=(tree*)malloc(sizeof(tree));
            x->right->data=e;
            x->right->left=NULL;
            x->right->right=NULL;
        }
        else
        {
            x->left=(tree*)malloc(sizeof(tree));
            x->left->data=e;
            x->left->left=NULL;
            x->left->right=NULL;
        }
    }
}
void inorder(tree *r)
{
    if(r==NULL)
    {
        return ;
    }
    inorder(r->left);
    printf("%d\t",r->data);
    inorder(r->right);
}
void preorder(tree *r)
{
    if(r==NULL)
    {
        return ;
    }
    printf("%d\t",r->data);
    preorder(r->left);
    preorder(r->right);
}
void postorder(tree *r)
{
    if(r==NULL)
    {
        return ;
    }
    postorder(r->left);
    postorder(r->right);
    printf("%d\t",r->data);
}

void delete(int e) {
    if (root == NULL) {
        return;
    }

    tree* parent = NULL;
    tree* current = root;

    // Search for the node to be deleted.
    while (current != NULL && current->data != e) {
        parent = current;
        if (e < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // If the node to be deleted is not found.
    if (current == NULL) {
        return;
    }
    if(current->left==NULL){
        if(parent)
    }
    
}