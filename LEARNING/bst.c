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

    tree* x = NULL;
    tree* p = root;

    // Find the node to be deleted.
    while (p != NULL && p->data != e) {
        x = p;
        if (e < p->data) {
            p = p->left;
        } else {
            p = p->right;
        }
    }

    // If the node to be deleted is not found.
    if (p == NULL) {
        return;
    }

    // If the node to be deleted has no child or one child.
    if (p->left == NULL || p->right == NULL) {
        tree* child = (p->left != NULL) ? p->left : p->right;

        if (x == NULL) {
            root = child;
        } else if (x->left == p) {
            x->left = child;
        } else {
            x->right = child;
        }
    }

    // If the node to be deleted has two children.
    else {
        tree *t=p->right;
				while(t->left!=NULL)
					t=t->left;
				delete(t->data);
				p->data = t->data;
    }
}

int main()
{
    insert(100);
    insert(50);
    insert(200);
    insert(10);
    insert(60);
    insert(150);
    insert(250);
    printf("INODER\n");
    inorder(root);
    printf("\nPREORDER\n");
    preorder(root);
    printf("\nPOSTORDER\n");
    postorder(root);
    delete(100);
    printf("\nINODER\n");
    inorder(root);
    delete(50);
    printf("\n");
    inorder(root);
    delete(150);
    printf("\n");
    inorder(root);
    return 0;
}





