
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, *ptr, sum = 0;
    printf("enter the size: ");
    scanf("%d", &n);

    ptr = (int *)calloc(n, sizeof(int));
    if (ptr == NULL)
    {
        printf("memory allocation failed");
    }
    else
    {
        printf("\nAllocated memory using calloc is: ");
        for (i = 0; i < n; i++)
        {
            printf("%d ", *(ptr + i));
        }

        free(ptr);
    }
    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("\nmemory allocation failed");
    }
    else
    {
        printf("\nAllocated memory using malloc is: ");
        for (i = 0; i < n; i++)
        {
            printf("%d ", *(ptr + i));
        }
        printf("\nenter new size");
        scanf("%d", &n);
        ptr = (int *)realloc(ptr, n * sizeof(int));
        printf("\nAllocated memory using realloc is: ");
        for (i = 0; i < n; i++)
        {
            printf("%d ", *(ptr + i));
        }
    }
}