#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} tree;

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
        x = root;
        while (p != NULL)
        {
            x = p;
            if (e > p->data)
            {
                p = p->right;
            }
            else
            {
                p = p->left;
            }
        }
        if (e > x->data)
        {
            x->right = (tree *)malloc(sizeof(tree));
            x->right->data = e;
            x->right->left = NULL;
            x->right->right = NULL;
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

void postorderTraversal(tree *root)
{
    tree *stack[100];
    int top = -1;
    tree *prev = NULL;
    tree *current = root;

    do
    {
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }
        while (current == NULL && top != -1)
        {
            current = stack[top];
            if (current->right == NULL || current->right == prev)
            {
                printf("%d ", current->data);
                top--;
                prev = current;
                current = NULL;
            }
            else
            {
                current = current->right;
            }
        }
    } while (top != -1);
}

void preorderTraversal(tree *root)
{
    tree *stack[100];
    int top = -1;
    tree *current = root;

    while (current != NULL || top != -1)
    {
        // Print the current node's data
        printf("%d ", current->data);

        // Push the right subtree onto the stack
        if (current->right != NULL)
        {
            stack[++top] = current->right;
        }

        // Move to the left subtree
        current = current->left;

        // If the left subtree is NULL, pop a node from the stack
        if (current == NULL && top != -1)
        {
            current = stack[top--];
        }
    }
}

void inorderTraversal(tree *root)
{
    tree *stack[100];
    int top = -1;
    tree *current = root;

    while (current != NULL || top != -1)
    {
        // Traverse left subtree and push nodes onto the stack
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }

        // Pop a node from the stack, print its data, and move to the right subtree
        if (top != -1)
        {
            current = stack[top--];
            printf("%d ", current->data);
            current = current->right;
        }
    }
}

void postorder(tree *r) {
    if (r == NULL) {
        return;
    }
    postorder(r->left);
    postorder(r->right);
    printf("%d\t", r->data);
}

int main()
{
    insert(100);
    insert(50);
    insert(200);
    insert(10);
    insert(60);
    insert(70);
    insert(80);
    insert(150);
    insert(250);

    printf("\n inorderwr\n");
    inorderTraversal(root);
    printf("\n preorderwr\n");
    preorderTraversal(root);
    printf("\n postorderwr\n");
    postorderTraversal(root);
    printf("\n postorder\n");
    postorder(root);

    return 0;
}