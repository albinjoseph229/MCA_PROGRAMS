#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *ptr;
    char str[50];
    int len, n, i;
    printf("\nEnter the string : ");
    scanf("%s", &str);
    len = strlen(str);
    ptr = (char *)malloc(len * sizeof(char));
    strcpy(ptr, str);
    printf("\nThe string using malloc is : ");
    for (i = 0; i < len; i++)
    {
        printf("%c", *(ptr + i));
    }
    printf("\n\nEnter the new size : ");
    scanf("%d", &n);
    ptr = (char *)realloc(ptr, n);
    printf("\nThe string using realloc is : ");
    for (i = 0; i < n && ptr[i] != '\0'; i++)
    {
        printf("%c", *(ptr + i));
    }
    free(ptr);
    return 0;
}
