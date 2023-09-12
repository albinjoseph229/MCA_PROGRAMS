#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> // Include the math library for pow
#define MAX 100

int stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

void push(int); // Change the argument type to int
int pop(); // Change the return type to int
int isEmpty();
void inToPost();
int isOperator(char);
int precedence(char);
int post_eval(); // Change the return type to int
void print();

int main()
{
    int result;
    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin); // Use fgets instead of gets
    inToPost();
    print();
    result = post_eval();
    printf("The result after postfix evaluation is: %d\n", result);
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

void push(int c) // Change the argument type to int
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    top++;
    stack[top] = c;
}

int pop() // Change the return type to int
{
    int c;
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

int post_eval()
{
    int i, a, b;
    for (i = 0; i < strlen(postfix); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
            push(postfix[i] - '0');
        else
        {
            a = pop();
            b = pop();
            switch (postfix[i])
            {
            case '+':
                push(b + a);
                break;
            case '-':
                push(b - a); 
                break;
            case '*':
                push(b * a);
                break;
            case '/':
                push(b / a);
                break;
            case '^':
                push(pow(b, a));
                break;
            }
        }
    }
    return pop(); // Return the final result
}
