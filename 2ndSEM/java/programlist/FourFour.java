import java.io.*;

public class FourFour {
    public static void main(String[] args) {
        Queue q = new Queue();

        q.enqueue(0);
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
        q.dequeue();
    }

}

class Queue {
    int array[], front, rear, size, capacity;

    public Queue() {
        this(10);
    }

    public Queue(int capacity) {
        array = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    public void enqueue(int value) {
        if (size == array.length) {
            System.out.println("Queue is full");
            return;
        }
        rear = (rear + 1) % array.length;
        array[rear] = value;
        size++;
    }

    public void dequeue() {
        if (size == 0) {
            System.out.println("Queue is empty. Cannot dequeue.");
        }
        int removedValue = array[front];
        front = (front + 1) % array.length;
        size--;
        System.out.println(removedValue);
    }
}