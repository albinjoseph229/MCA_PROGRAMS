#include <stdio.h>
struct poly
{
    int coeff;
    int exp;
};

int main()
{
    int i, num;
    struct poly p[10];
    printf("Enter the number of terms: ");
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        printf("Enter the coefficient: ");
        scanf("%d", &p[i].coeff);
        printf("Enter the degree: ");
        scanf("%d", &p[i].exp);
    }
    printf("The entered polynomial is: ");
    for (i = 0; i < num; i++)
    {
        printf("%dx^%d", p[i].coeff, p[i].exp);
        if (i < num - 1)
        {
            printf(" + ");
        }
    }
    return 0;
}
