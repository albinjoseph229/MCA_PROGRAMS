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
	if (root == NULL)
	{
		root = (tree *)malloc(sizeof(tree));
		root->data = e;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		tree *x = NULL;
		tree *p = root;

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
void postorderwr(tree *root)
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
	insert(150);
	insert(250);
	postorder(root);
	printf("\n");
	postorderwr(root);
	return 0;
}