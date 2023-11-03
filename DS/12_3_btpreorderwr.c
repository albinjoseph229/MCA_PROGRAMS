#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
typedef struct node tree;
struct stack
{
    tree *ptr;
    struct stack *next;
};
typedef struct stack stack;
tree *root = NULL;
stack *top = NULL;
void push(tree *t)
{
    stack *temp = (stack *)malloc(sizeof(stack));
    temp->ptr = t;
    temp->next = top;
    top = temp;
}
tree *pop()
{
    tree *t = NULL;
    if (top != NULL)
    {
        t = top->ptr;
        top = top->next;
    }
    return t;
}
void preorderwor(tree *r)
{
    tree *t;
    for (t = r; t != NULL; t = t->left)
    {
        printf("%d\t", t->data);
        push(t);
    }
    t = pop();
    while (t != NULL)
    {
        if (t->right != NULL)
        {
            for (t = t->right; t != NULL; t = t->left)
            {
                printf("%d\t", t->data);
                push(t);
            }
        }
        t = pop();
    }
}
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
        x = root;
        while (x != NULL)
        {
            p = x;
            if (e < x->data)
            {
                x = x->left;
            }
            else if (e > x->data)
            {
                x = x->right;
            }
        }
        if (e < p->data)
        {
            p->left = (tree *)malloc(sizeof(tree));
            p->left->data = e;
            p->left->left = NULL;
            p->left->right = NULL;
        }
        else if (e > p->data)
        {
            p->right = (tree *)malloc(sizeof(tree));
            p->right->data = e;
            p->right->left = NULL;
            p->right->right = NULL;
        }
    }
}
void main()
{
    int ch, e, ch1;
    printf("\nBINARY SEARCH TREE");
    do
    {
        printf("\n1.Insertion\n2.preorderdisplay\n3.Exit\nChoose your option:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter no: ");
            scanf("%d", &e);
            insert(e);
            break;
        case 2:
            printf("\n");
            preorderwor(root);
            break;

        case 3:
            exit(1);
            break;
        }
    } while (1);
}
