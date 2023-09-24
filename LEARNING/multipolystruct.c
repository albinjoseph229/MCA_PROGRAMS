#include <stdio.h>

struct poly {
    int coeff;
    int exp;
};

int main() {
    struct poly p1[10], p2[10], p3[100]; // p3 should have enough space for the product
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

    k = 0;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            p3[k].coeff = p1[i].coeff * p2[j].coeff;
            p3[k].exp = p1[i].exp + p2[j].exp;
            k++;
        }
    }

    // Simplify the result by combining like terms
    for (i = 0; i < k; i++) {
        for (j = i + 1; j < k; j++) {
            if (p3[i].exp == p3[j].exp) {
                p3[i].coeff += p3[j].coeff;
                // Remove the j-th term by shifting the remaining terms
                for (int l = j; l < k - 1; l++) {
                    p3[l] = p3[l + 1];
                }
                k--; // Reduce the count of terms
                j--; // Adjust the index since we removed a term
            }
        }
    }

    printf("\nThe product of the two polynomials is: ");
    for (i = 0; i < k; i++) {
        printf("%dx^%d", p3[i].coeff, p3[i].exp);
        if (i < k - 1) {
            printf(" + ");
        }
    }
    
    printf("\n");

    return 0;
}
