#include <stdio.h>

#define MAX_SIZE 100

int top = -1;
int stack[MAX_SIZE];

void push(int element) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top] = element;
    printf("\n%d is pushed",element);
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
    }
    else{
            printf("\n%d is popped",stack[top]);
            top--;
    }
    
}
void peek()
{
	if(top==-1)
	{
		printf("stack underflow\n");
	}
	else
	{
		printf("\nElement at top is %d\n",stack[top]);
	}
}

int main() {
    push(1);
    push(2);
    push(3);
    peek();
    pop();
    pop();
    pop();
    pop();
    peek();
    return 0;
}
