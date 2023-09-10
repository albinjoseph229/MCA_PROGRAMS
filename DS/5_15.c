#include <stdio.h>

// Define a constant for the maximum number of terms
#define MAX_TERMS 100

int main() {
    int numTerms;


    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &numTerms);

    // Create arrays to store coefficients and degrees for each term
    int coefficients[MAX_TERMS];
    int degrees[MAX_TERMS];

    // Read coefficients and degrees from the user
    for (int i = 0; i < numTerms; i++) {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%d", &coefficients[i]);

        printf("Enter the degree for term %d: ", i + 1);
        scanf("%d", &degrees[i]);
    }

    // Display the polynomial
    printf("The polynomial is: ");
    for (int i = 0; i < numTerms; i++) {
        if (coefficients[i] != 0) {
            if (i > 0) {
                if (coefficients[i] > 0) {
                    printf(" + ");
                } else {
                    printf(" - ");
                    coefficients[i] = -coefficients[i]; // Make negative coefficients positive for display
                }
            }

            if (degrees[i] == 0) {
                printf("%d", coefficients[i]);
            } else if (degrees[i] == 1) {
                printf("%dx", coefficients[i]);
            } else {
                printf("%dx^%d", coefficients[i], degrees[i]);
            }
        }
    }
    printf("\n");

    return 0;
}
