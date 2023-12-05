#include <stdio.h>
#include <string.h>

#define MAX 100

char s[MAX];
char stack[MAX];
int top = -1; // Initialize top to -1
int i;

void push(char x); // Function prototype
void pop(); // Function prototype

int main()
{
    printf("Enter the string: ");
    gets(s);
    int len = strlen(s);

    for (i = 0; i < len; i++)
    {
        push(s[i]);
    }

    printf("Reversed string: ");
    for (i = 0; i < len; i++)
    {
        pop();
    }
    printf("\n");

    return 0;
}

void push(char x)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("%c", stack[top]);
        top--;
    }
}
