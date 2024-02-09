import java.io.*;

public class ThreeEight {
    public static void main(String[] args) {

        int s = sum();
        System.out.println("Sum of Even numbers = " + s);
    }

    private static int sum() {
        DataInputStream din = new DataInputStream(System.in);
        int sum = 0;
        try {

            System.out.print("Enter number: ");
            int n = Integer.parseInt(din.readLine());
            int i = 0;
            while (i <= n) {
                if (i % 2 == 0)
                    sum += i;
                i++;
            }

        } catch (Exception e) {
            System.out.println("Error " + e);
        }
        return sum;
    }
}