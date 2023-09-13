#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void countofnodes(struct node *head);

int main() {
    struct node *head = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 45;
    head->next = NULL;

    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = 98;
    t->next = NULL;
    head->next = t;

    t = (struct node*)malloc(sizeof(struct node));
    t->data = 3;
    t->next = NULL;
    head->next->next = t;

    countofnodes(head);

    // Free allocated memory
    struct node *current = head;
    while (current != NULL) {
        struct node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

void countofnodes(struct node *head) {
    int count = 0;
    struct node *ptr = head;

    if (head == NULL) {
        printf("Linked list is empty\n");
    } else {
        while (ptr != NULL) {
            count++;
            ptr = ptr->next;
        }
        printf("Number of nodes in the linked list: %d\n", count);
    }
}
