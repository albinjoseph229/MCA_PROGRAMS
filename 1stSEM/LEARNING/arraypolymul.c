#include <stdio.h>

int coeff1[10];
int exp1[10];
int coeff2[10];
int exp2[10];
int coeff3[10];
int exp3[10];
int n1, n2, k, i, j;

void read() {
    printf("Enter the number of terms for the 1st polynomial: ");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%d", &coeff1[i]);
        printf("Enter the degree for term %d: ", i + 1);
        scanf("%d", &exp1[i]);
    }

    printf("Enter the number of terms for the 2nd polynomial: ");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%d", &coeff2[i]);
        printf("Enter the degree for term %d: ", i + 1);
        scanf("%d", &exp2[i]);
    }
}

void mul() {
    k = 0;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            coeff3[k] = coeff1[i] * coeff2[j];
            exp3[k] = exp1[i] + exp2[j]; // Combine degrees by addition
            k++;
        }
    }
}

void display() {
    printf("Result of polynomial multiplication: ");
    for (i = 0; i < k; i++) {
        if (i > 0) {
            printf(" + ");
        }
        printf("%dx^%d", coeff3[i], exp3[i]);
    }
    printf("\n");
}

int main() {
    read();
    mul();
    display();
    return 0;
}
