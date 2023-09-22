#include <stdio.h>

int main()
{
    int c1[10], e1[10], c2[10], e2[10], c3[20], e3[20];
    int i, j, n1, n2, k = 0;

    printf("Enter the number of terms for polynomial 1: ");
    scanf("%d", &n1);

    printf("Enter the polynomial 1 terms:\n");
    for (i = 0; i < n1; i++)
    {
        printf("Enter the coefficient: ");
        scanf("%d", &c1[i]);
        printf("Enter the exponent: ");
        scanf("%d", &e1[i]);
    }

    printf("Enter the number of terms for polynomial 2: ");
    scanf("%d", &n2);

    printf("Enter the polynomial 2 terms:\n");
    for (i = 0; i < n2; i++)
    {
        printf("Enter the coefficient: ");
        scanf("%d", &c2[i]);
        printf("Enter the exponent: ");
        scanf("%d", &e2[i]);
    }

    i = j = 0;

    while (i < n1 && j < n2)
    {
        if (e1[i] == e2[j])
        {
            c3[k] = c1[i] + c2[j];
            e3[k] = e1[i];
            i++;
            j++;
            k++;
        }
        else if (e1[i] > e2[j])
        {
            c3[k] = c1[i];
            e3[k] = e1[i];
            i++;
            k++;
        }
        else
        {
            c3[k] = c2[j];
            e3[k] = e2[j];
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        c3[k] = c1[i];
        e3[k] = e1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        c3[k] = c2[j];
        e3[k] = e2[j];
        j++;
        k++;
    }

    printf("Resultant polynomial after addition:\n");
    for (i = 0; i < k; i++)
    {
        printf("%dx^%d", c3[i], e3[i]);
        if (i < k - 1)
            printf(" + ");
    }

    return 0;
}
