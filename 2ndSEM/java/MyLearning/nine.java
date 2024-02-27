//multi threading by implementing runnable interface example
class MyThread implements Runnable {
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

public class nine {
    public static void main(String[] args) {
        // Create an instance of MyThread
        MyThread obj = new MyThread();
        
        Thread t1= new Thread(obj);

        // Start the thread
        t1.start();
        
        // Code to be executed in the main thread
        System.out.println("Main thread is running");
    }
}
