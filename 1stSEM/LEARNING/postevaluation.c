#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;

void push(int x) {
    if (top != MAX_STACK_SIZE - 1) {
        stack[++top] = x;
    }
}

int pop() {
    if (top == -1) {
        printf("Error: Stack underflow\n");
        return -1; // Assuming -1 represents an error
    } else {
        return stack[top--];
    }
}

int evaluatePostfix(char *expression) {
    int operand1, operand2;
    char *e = expression;

    while (*e != '\0') {
        if (isdigit(*e)) {
            push(*e - '0'); // Convert character to integer
        } else {
            operand2 = pop();
            operand1 = pop();

            switch (*e) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        push(operand1 / operand2);
                    } else {
                        printf("Error: Division by zero\n");
                        return -1; // Assuming -1 represents an error
                    }
                    break;
                default:
                    printf("Error: Invalid operator\n");
                    return -1; // Assuming -1 represents an error
            }
        }
        e++;
    }

    return pop();
}

int main() {
    char postfixExpression[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfixExpression);

    int result = evaluatePostfix(postfixExpression);

    if (result != -1) {
        printf("Result of the postfix expression: %d\n", result);
    }

    return 0;
}
