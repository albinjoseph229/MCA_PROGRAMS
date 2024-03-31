// Class extending Thread class
class MyThread extends Thread {
    // Override the run method
    public void run() {
        // Thread logic here
    }
}

// Main class to test multi-threading
public class MultiThreadingExample2 {
    public static void main(String[] args) {
        // Create and start a thread
        MyThread thread = new MyThread();
        thread.start();
    }
}
