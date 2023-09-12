#include <stdio.h>
#define MAX_SIZE 10

int deque[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the deque is empty
int isEmpty() {
    return (front == -1 && rear == -1);
}

// Function to check if the deque is full
int isFull() {
    return (rear == MAX_SIZE - 1 && front == 0) || (rear == front - 1);
}

// Function to add an element at the front of the deque
void insertFront(int value) {
    if (isFull()) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX_SIZE - 1;
    } else {
        front--;
    }
    deque[front] = value;
    printf("Inserted %d at the front.\n", value);
}

// Function to add an element at the rear of the deque
void insertRear(int value) {
    if (isFull()) {
        printf("Deque is full. Cannot insert.\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX_SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = value;
    printf("Inserted %d at the rear.\n", value);
}

// Function to remove an element from the front of the deque
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete.\n");
        return;
    }
    printf("Deleted %d from the front.\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX_SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Function to remove an element from the rear of the deque
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete.\n");
        return;
    }
    printf("Deleted %d from the rear.\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX_SIZE - 1;
    } else {
        rear--;
    }
}

// Function to display the elements in the deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) {
            break;
        }
        if (i == MAX_SIZE - 1) {
            i = 0;
        } else {
            i++;
        }
    }
    printf("\n");
}

int main() {
    insertRear(1);
    insertFront(2);
    insertRear(3);
    display();

    deleteFront();
    display();

    insertFront(4);
    insertRear(5);
    display();

    deleteRear();
    display();

    return 0;
}
