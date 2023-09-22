#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

char stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

void push(char);
char pop();
int isEmpty();
void inToPost();
int isOperator(char);
int precedence(char);
void print();

int main()
{
    printf("Enter the infix expression: ");
    gets(infix);
    inToPost();
    print();
    return 0;
}

void inToPost()
{
    int i, j = 0;
    char symbol, next;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];

        if (symbol == '(')
        {
            push(symbol);
        }
        else if (symbol == ')')
        {
            while ((next = pop()) != '(')
                postfix[j++] = next;
        }
        else if (isOperator(symbol))
        {
            while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                postfix[j++] = pop();
            push(symbol);
        }
        else
        {
            postfix[j++] = symbol;
        }
    }
    while (!isEmpty())
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void print()
{
    int i = 0;
    printf("The equivalent postfix expression is: ");
    while (postfix[i])
    {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}

void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    top++;
    stack[top] = c;
}

char pop()
{
    char c;
    if (top == -1)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    c = stack[top];
    top = top - 1;
    return c;
}

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
