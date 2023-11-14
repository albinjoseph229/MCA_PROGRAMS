#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void postorderTraversal(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* prev = NULL;
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
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Postorder traversal of binary tree is: ");
    postorderTraversal(root);

    return 0;
}
