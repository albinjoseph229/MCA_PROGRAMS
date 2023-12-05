#include <stdio.h>

struct poly {
    int coeff;
    int exp;
};

int main() {
    struct poly p1[10], p2[10], p3[20]; // p3 should have enough space for the sum
    int i, j, k, n1, n2;

    printf("Enter the number of terms for the first polynomial: ");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        printf("Enter the coefficient: ");
        scanf("%d", &p1[i].coeff);
        printf("Enter the degree: ");
        scanf("%d", &p1[i].exp);
    }

    printf("Enter the number of terms for the second polynomial: ");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        printf("Enter the coefficient: ");
        scanf("%d", &p2[i].coeff);
        printf("Enter the degree: ");
        scanf("%d", &p2[i].exp);
    }

    printf("The first polynomial is: ");
    for (i = 0; i < n1; i++) {
        printf("%dx^%d", p1[i].coeff, p1[i].exp);
        if (i < n1 - 1) {
            printf(" + ");
        }
    }

    printf("\nThe second polynomial is: ");
    for (i = 0; i < n2; i++) {
        printf("%dx^%d", p2[i].coeff, p2[i].exp);
        if (i < n2 - 1) {
            printf(" + ");
        }
    }

    i = j = k = 0;
    while (i < n1 && j < n2) {
        if (p1[i].exp == p2[j].exp) {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].exp = p1[i].exp;
            i++;
            j++;
            k++;
        } else if (p1[i].exp < p2[j].exp) {
            p3[k].coeff = p1[i].coeff;
            p3[k].exp = p1[i].exp;
            i++;
            k++;
        } else {
            p3[k].coeff = p2[j].coeff;
            p3[k].exp = p2[j].exp;
            j++;
            k++;
        }
    }

    while (i < n1) {
        p3[k].coeff = p1[i].coeff;
        p3[k].exp = p1[i].exp;
        i++;
        k++;
    }

    while (j < n2) {
        p3[k].coeff = p2[j].coeff;
        p3[k].exp = p2[j].exp;
        j++;
        k++;
    }

    printf("\nThe sum of the two polynomials is: ");
    for (i = 0; i < k; i++) {
        printf("%dx^%d", p3[i].coeff, p3[i].exp);
        if (i < k - 1) {
            printf(" + ");
        }
    }
    
    printf("\n");

    return 0;
}
