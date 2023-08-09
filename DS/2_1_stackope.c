#include <stdio.h>
int a[5], top = -1;

void push(int e) {
    if (top + 1 == 5) {
        printf("Stack is full\n");
    } else {
        a[++top] = e;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Deleted Element %d\n", a[top--]);
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Element at top is %d\n", a[top]);
    }
}

int menu() {
    int ch;
    printf("\n1. push\n2. pop\n3. Peek\n4. Exit\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void process() {
    int ch, e;
    for (ch = menu(); ch != 4; ch = menu()) {
        switch (ch) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &e);
                push(e);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            default:
                printf("\nInvalid Choice\n");
        }
    }
}

int main() {
    process();
    return 0;
}
