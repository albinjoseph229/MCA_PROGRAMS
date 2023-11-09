#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node *next;
};

int n1, n2, n;
struct node *poly1 = NULL;
struct node *poly2 = NULL;
struct node *result = NULL;

void insertTerm(struct node **poly, int coeff, int exp) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->next = NULL;

    if (*poly == NULL) {
        *poly = newnode;
    } else {
        struct node *temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void addPolynomials() {
    struct node *temp1 = poly1;
    struct node *temp2 = poly2;

    while (temp1 != NULL || temp2 != NULL) {
        if (temp1 == NULL) {
            insertTerm(&result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        } else if (temp2 == NULL) {
            insertTerm(&result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else if (temp1->exp > temp2->exp) {
            insertTerm(&result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else if (temp2->exp > temp1->exp) {
            insertTerm(&result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        } else {
            // Exponents are equal, so add coefficients
            insertTerm(&result, temp1->coeff + temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
}

void print(struct node *poly) {
    struct node *temp = poly;
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
    printf("Enter the number of terms for the first polynomial: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        int coeff, exp;
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }

    printf("Enter the number of terms for the second polynomial: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        int coeff, exp;
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }

    addPolynomials();

    printf("First Polynomial: ");
    print(poly1);
    printf("Second Polynomial: ");
    print(poly2);
    printf("Result of Polynomial Addition: ");
    print(result);
    return 0;
}
