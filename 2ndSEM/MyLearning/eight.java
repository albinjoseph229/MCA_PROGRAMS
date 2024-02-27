//multi threading by extending thread class example
class MyThread extends Thread {
    public void run() {
        // Code to be executed in the thread
        System.out.println("Thread is running");
        try{
            Thread.sleep(1000);
        }
        catch(Exception e){
            System.out.println("Error"+e);
        }
        
    }
}

public class eight {
    public static void main(String[] args) {
        // Create an instance of MyThread
        MyThread thread = new MyThread();
        
        // Start the thread
        thread.start();
        
        // Code to be executed in the main thread
        System.out.println("Main thread is running");
    }
}
