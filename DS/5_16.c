#include <stdio.h>

// Define a constant for the maximum number of terms
#define MAX_TERMS 100
#define MAX_RESULT_TERMS (2 * MAX_TERMS)

int main() {
    int numTerms1, numTerms2;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &numTerms1);

    // Create arrays for the first polynomial
    int coefficients1[MAX_TERMS];
    int degrees1[MAX_TERMS];

    // Read coefficients and degrees for each term of the first polynomial
    for (int i = 0; i < numTerms1; i++) {
        printf("Enter the coefficient for term %d of the first polynomial: ", i + 1);
        scanf("%d", &coefficients1[i]);

        printf("Enter the degree for term %d of the first polynomial: ", i + 1);
        scanf("%d", &degrees1[i]);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &numTerms2);

    // Create arrays for the second polynomial
    int coefficients2[MAX_TERMS];
    int degrees2[MAX_TERMS];

    // Read coefficients and degrees for each term of the second polynomial
    for (int i = 0; i < numTerms2; i++) {
        printf("Enter the coefficient for term %d of the second polynomial: ", i + 1);
        scanf("%d", &coefficients2[i]);

        printf("Enter the degree for term %d of the second polynomial: ", i + 1);
        scanf("%d", &degrees2[i]);
    }

    // Create arrays for the resulting polynomial
    int resultCoefficients[MAX_RESULT_TERMS];
    int resultDegrees[MAX_RESULT_TERMS];

    // Perform addition of the two polynomials
    int i = 0, j = 0, k = 0;
    while (i < numTerms1 && j < numTerms2) {
        if (degrees1[i] == degrees2[j]) {
            resultCoefficients[k] = coefficients1[i] + coefficients2[j];
            resultDegrees[k] = degrees1[i];
            i++;
            j++;
            k++;
        } else if (degrees1[i] > degrees2[j]) {
            resultCoefficients[k] = coefficients1[i];
            resultDegrees[k] = degrees1[i];
            i++;
            k++;
        } else {
            resultCoefficients[k] = coefficients2[j];
            resultDegrees[k] = degrees2[j];
            j++;
            k++;
        }
    }

    while (i < numTerms1) {
        resultCoefficients[k] = coefficients1[i];
        resultDegrees[k] = degrees1[i];
        i++;
        k++;
    }

    while (j < numTerms2) {
        resultCoefficients[k] = coefficients2[j];
        resultDegrees[k] = degrees2[j];
        j++;
        k++;
    }

    // Determine the number of terms in the resulting polynomial
    int numResultTerms = k;

    // Display the resulting polynomial
    printf("The resulting polynomial is: ");
    for (int i = 0; i < numResultTerms; i++) {
        if (resultCoefficients[i] != 0) {
            if (i > 0) {
                if (resultCoefficients[i] > 0) {
                    printf(" + ");
                } else {
                    printf(" - ");
                    resultCoefficients[i] = -resultCoefficients[i];
                }
            }

            if (resultDegrees[i] == 0) {
                printf("%d", resultCoefficients[i]);
            } else if (resultDegrees[i] == 1) {
                printf("%dx", resultCoefficients[i]);
            } else {
                printf("%dx^%d", resultCoefficients[i], resultDegrees[i]);
            }
        }
    }
    printf("\n");

    return 0;
}
