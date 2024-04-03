class Counter {
    private int count = 0;

    public void increment() {
        synchronized(this) { // Synchronize access to the critical section
            count++;
        }
    }

    public void decrement() {
        synchronized(this) { // Synchronize access to the critical section
            count--;
        }
    }

    public int getCount() {
        return count;
    }
}

class IncrementThread extends Thread {
    private Counter counter;

    public IncrementThread(Counter counter) {
        this.counter = counter;
    }

    public void run() {
        for (int i = 0; i < 1000; i++) {
            counter.increment();
        }
    }
}

class DecrementThread extends Thread {
    private Counter counter;

    public DecrementThread(Counter counter) {
        this.counter = counter;
    }

    public void run() {
        for (int i = 0; i < 1000; i++) {
            counter.decrement();
        }
    }
}

public class ThreadSynchronizationExample {
    public static void main(String[] args) throws InterruptedException {
        Counter counter = new Counter();
        IncrementThread incrementThread = new IncrementThread(counter);
        DecrementThread decrementThread = new DecrementThread(counter);

        incrementThread.start();
        decrementThread.start();

        incrementThread.join();
        decrementThread.join();

        System.out.println("Final Counter Value: " + counter.getCount());
    }
}
