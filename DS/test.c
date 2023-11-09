#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node* next;
};

int coeff, exp, n;
struct node* head = NULL;

void insertnode() {
    for (int i = 0; i < n; i++) {
        printf("Enter the coefficient and exponent for term %d: ", i + 1);
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d %d", &newnode->coeff, &newnode->exp);
        newnode->next = NULL;
        if (head == NULL) {
            head = newnode;
        } else {
            struct node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

void print() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    insertnode();
    printf("Polynomial: ");
    print();
    return 0;
}
