public class Thread1 extends Thread {
  public static void main(String[] args) {
    Thread1 thread = new Thread1();
    thread.start();
    System.out.println("This code is outside of the thread");
  }
  public void run() {
    System.out.println("This code is running in a thread");
  }
}