#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node tree;
tree *root = NULL;
void insert(int e)
{
    tree *p, *x;
    if (root == NULL)
    {
        root = (tree *)malloc(sizeof(tree));
        root->data = e;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        p = root;
        while (p != NULL)
        {
            x = p;
            if (p->data > e)
                p = p->left;
            else
                p = p->right;
        }
        if (x->data < e)
        {
            if (x->data < e)
            {
                x->right = (tree *)malloc(sizeof(tree));
                x->right->data = e;
                x->right->left = NULL;
                x->right->left = NULL; 
            }
            else
            {
                x->left = (tree *)malloc(sizeof(tree));
                x->left->data = e;
                x->left->left = NULL;
                x->left->right = NULL;
            }
        }
    }
}
void inorder(tree *r)
{
    if (r != NULL)
    {
        inorder(r->left);
        printf("%d\t", r->data);
        inorder(r->right);
    }
}
int main()
{
    insert(100);
    insert(50);
    insert(120);
    insert(200);
    insert(10);
    insert(60);
    inorder(root);
    return 0;
}