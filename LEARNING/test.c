#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}tree;
tree *root=NULL;
tree *p=NULL,*x=NULL;

void insert(int e)
{
    if(root==NULL){
        root=(tree*)malloc(sizeof(tree));
        root->data=e;
        root->left=NULL;
        root->right=NULL;
    }
    else{
        p=root;
        while(p!=NULL)
        {
            x=p;
            if(p->data<e){
                p=p->right;
            }
            else{
                p=p->left;
            }
        }
        if(x->data<e){
            x->right=(tree*)malloc(sizeof(tree));
            x->right->data=e;
            x->right->left=NULL;
            x->right->right=NULL;
        }

        else{
            x->left=(tree*)malloc(sizeof(tree));
            x->left->data=e;
            x->left->left=NULL;
            x->left->right=NULL;
        }
    }

}
void inorder(tree *r){
    if(r!=NULL){
        inorder(r->left);
        printf("%d\t",r->data);
        inorder(r->right);
    }
}
void delete(int e)
int main(){
    insert(100);
    insert(50);
    insert(10);
    insert(30);
    insert(150);
    insert(200);
    inorder(root);
}