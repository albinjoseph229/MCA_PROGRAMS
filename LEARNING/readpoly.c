#include <stdio.h>
#define MAX 50

int coeff[MAX];
int degree[MAX];
int num;

void read()
{
    for (int i = 0; i < num; i++)
    {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%d", &coeff[i]);
        printf("Enter the degree for term %d: ", i + 1);
        scanf("%d", &degree[i]);
    }
  
}

void display()
{
    printf("Polynomial Terms:\n");
    for (int i = 0; i < num; i++)
    {
        if (i < (num - 1))
        {
            printf("%dx^%d + ", coeff[i], degree[i]);
        }
        else
        {
            if(degree[i]==0 && i==(num-1))
            {
                printf("%d", coeff[i]);
            }
            else
            {
            printf("%dx^%d", coeff[i], degree[i]);
            }
        }
    }
    printf("\n"); // Add a newline at the end for better formatting
}

int main()
{
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &num);
    
    read(); // Call the read function to input coefficients and degrees
    display(); // Call the display function to show the polynomial terms
    
    return 0;
}
