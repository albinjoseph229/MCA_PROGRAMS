#include <stdio.h>
#include <stdlib.h>

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

        if (x->data > e)
        {
            x->left = (tree *)malloc(sizeof(tree));
            x->left->data = e;
            x->left->left = NULL;
            x->left->right = NULL;
        }
        else
        {
            x->right = (tree *)malloc(sizeof(tree));
            x->right->data = e;
            x->right->left = NULL;
            x->right->right = NULL;
        }
    }
}

void preorder(tree *r)
{
    if (r != NULL)
    {
        printf("%d\t", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(tree *r)
{
    if (r != NULL)
    {
        postorder(r->left);
        postorder(r->right);
        printf("%d\t", r->data);
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

void main()
{
    int ch,e;
    while (1)
    {
        printf("\nEnter Your Choice \n1-Insert\n2-Inorder\n3-preorder\n4-postorder\n5-exit\n");
            scanf("%d", &ch);
        {
            switch (ch)
            {
            case 1:
                printf("\nEnter the element:");
                scanf("%d", &e);
                insert(e);
                break;
            case 2:
                inorder(root);
            break;
            case 3:
                preorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                return;
                break;
            default:
                printf("\nInvalid choice");
                break;
            }
        }
    }
}
