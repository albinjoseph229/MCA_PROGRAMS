#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} tree;

tree *root = NULL;

void insert(int e) {
    tree *p, *x;
    if (root == NULL) {
        root = (tree *)malloc(sizeof(tree));
        root->data = e;
        root->left = NULL;
        root->right = NULL;
    } else {
        p = root;
        x = root;
        while (p != NULL) {
            x = p;
            if (e > p->data) {
                p = p->right;
            } else {
                p = p->left;
            }
        }
        if (e > x->data) {
            x->right = (tree *)malloc(sizeof(tree));
            x->right->data = e;
            x->right->left = NULL;
            x->right->right = NULL;
        } else {
            x->left = (tree *)malloc(sizeof(tree));
            x->left->data = e;
            x->left->left = NULL;
            x->left->right = NULL;
        }
    }
}

void inorder(tree *r) {
    if (r == NULL) {
        return;
    }
    inorder(r->left);
    printf("%d\t", r->data);
    inorder(r->right);
}

void preorder(tree *r) {
    if (r == NULL) {
        return;
    }
    printf("%d\t", r->data);
    preorder(r->left);
    preorder(r->right);
}

void postorder(tree *r) {
    if (r == NULL) {
        return;
    }
    postorder(r->left);
    postorder(r->right);
    printf("%d\t", r->data);
}

void delete(int e) {
    if (root == NULL) {
        return;
    }

    tree *parent = NULL;
    tree *current = root;

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

    // If the node to be deleted has no child or one child.
    if (current->left == NULL) {
        if (parent == NULL) {
            root = current->right;
        } else if (parent->left == current) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
        free(current);
    } else if (current->right == NULL) {
        if (parent == NULL) {
            root = current->left;
        } else if (parent->left == current) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
        free(current);
    }

    // If the node to be deleted has two children.
    else {
        tree *successor = current->right;
        parent = current;
        while (successor->left != NULL) {
            parent = successor;
            successor = successor->left;
        }
        current->data = successor->data;

        if (parent->left == successor) {
            parent->left = successor->right;
        } else {
            parent->right = successor->right;
        }

        free(successor);
    }
}

void postorderTraversal(tree *root) {
    tree *stack[100];
    int top = -1;
    tree *prev = NULL;
    do {
        while (root != NULL) {
            stack[++top] = root;
            root = root->left;
        }
        while (root == NULL && top != -1) {
            root = stack[top];
            if (root->right == NULL || root->right == prev) {
                printf("%d ", root->data);
                top--;
                prev = root;
                root = NULL;
            } else {
                root = root->right;
            }
        }
    } while (top != -1);
}

int main() {
    insert(100);
    insert(50);
    insert(200);
    insert(10);
    insert(60);
    insert(150);
    insert(250);

    printf("INORDER\n");
    inorder(root);
    printf("\nPREORDER\n");
    preorder(root);
    printf("\nPOSTORDER\n");
    postorder(root);

    delete(100);
    printf("\nINORDER\n");
    inorder(root);

    delete(50);
    printf("\nINORDER\n");
    inorder(root);

    delete(150);
    printf("\nINORDER\n");
    inorder(root);

    printf("\npostorder without recursion\n");
    postorderTraversal(root);
    return 0;
}
