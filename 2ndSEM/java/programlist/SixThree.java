//WAP to implement a function using call by value to swap two float numbers.

public class SixThree {
    public static void main(String[] arg) {
        float a = 1;
        float b = 2;
        System.out.println("a and b (inside main function)");
        System.out.println("a = " + a + " b = " + b);
        swap(a, b);
    }

    private static void swap(float a, float b) {
        float temp;
        temp = a;
        a = b;
        b = temp;
        System.out.println("a and b (inside swap function)");
        System.out.println("a = " + a + " b = " + b);
    }
}

