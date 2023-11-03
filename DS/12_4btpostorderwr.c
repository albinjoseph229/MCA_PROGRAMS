#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    int info;
    struct node *right;
};

struct node* insert(struct node* root, int key) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = key;
    newNode->left = newNode->right = NULL;

    if (root == NULL) {
        return newNode;
    }

    struct node* current = root;
    struct node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (key < current->info) {
            current = current->left;
        } else if (key > current->info) {
            current = current->right;
        } else {
            free(newNode);
            return root; // Duplicate key, no need to insert
        }
    }

    if (key < parent->info) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
}

void postorder(struct node* root) {
    if (root == NULL) {
        return;
    }

    struct node* current = root;
    struct node* temp = NULL;

    while (current != NULL) {
        if (current->right == NULL) {
            printf("%d ", current->info);
            current = current->left;
        } else {
            temp = current->right;
            while (temp->left != NULL && temp->left != current) {
                temp = temp->left;
            }

            if (temp->left == NULL) {
                temp->left = current;
                current = current->right;
            } else {
                temp->left = NULL;
                printf("%d ", current->info);
                current = current->left;
            }
        }
    }
}

int main() {
    struct node *root = NULL;
    int choice, k;

    printf("\n BINARY SEARCH TREE\n--------------------");

    while (1) {
        printf("\n");
        printf("1.Insert\n2.Display Postorder\n3.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &k);
                root = insert(root, k);
                break;

            case 2:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 3:
                exit(0);

            default:
                printf("Wrong choice\n");
        }
    }

    return 0;
}
