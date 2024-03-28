// Class demonstrating static variables, static block, and static method
class StaticExample {
    // Static variable
    static int count;

    // Static block
    static {
        count = 10;
        System.out.println("Static block initialized with count = " + count);
    }

    // Static method
    static void displayCount() {
        System.out.println("Count: " + count);
    }
}

// Main class to test static variables, static blocks, and static methods
public class StaticExampleMain {
    public static void main(String[] args) {
        // Accessing static variable
        System.out.println("Initial Count: " + StaticExample.count);

        // Accessing static method
        StaticExample.displayCount();

        // Modifying static variable
        StaticExample.count = 20;
        System.out.println("Modified Count: " + StaticExample.count);

        // Accessing static method again
        StaticExample.displayCount();
    }
}
