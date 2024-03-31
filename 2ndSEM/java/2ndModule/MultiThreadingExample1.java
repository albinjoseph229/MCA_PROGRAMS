// Class implementing Runnable interface
class MyRunnable implements Runnable {
    // Run method to be executed by the thread
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println(Thread.currentThread().getName() + ": " + i);
            try {
                Thread.sleep(1000); // Pause for 1 second
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted.");
            }
        }
    }
}

// Main class to test multi-threading
public class MultiThreadingExample1 {
    public static void main(String[] args) {
        // Create two threads
        Thread thread1 = new Thread(new MyRunnable(), "Thread 1");
        Thread thread2 = new Thread(new MyRunnable(), "Thread 2");

        // Start the threads
        thread1.start();
        thread2.start();
    }
}
