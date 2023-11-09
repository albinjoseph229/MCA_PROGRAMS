#include <stdio.h>

int queue[10];
int front = -1;
int rear = -1;
int n;

void enqueue() {
    if ((rear + 1) % 10 == front) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        printf("Enter the element: ");
        scanf("%d", &queue[rear = (rear + 1) % 10]);
        printf("%d enqueued.\n", queue[rear]);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        printf("%d is removed.\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % 10;
        }
    }
}

int main() {
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    dequeue();
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    dequeue();
    dequeue();
    
    return 0;
}
