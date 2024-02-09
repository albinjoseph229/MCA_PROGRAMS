//WAP to display even numbers upto ‘n’ using a static function
import java.io.*;

public class FourSix {
    public static void main(String[] args) {
        DataInputStream din = new DataInputStream(System.in);

        System.out.print("Enter the value of n: ");
        try {
            int n = Integer.parseInt(din.readLine());
            evenNum(n);
        } catch (Exception e) {
            System.out.println("Error " + e);
        }
    }

    private static void evenNum(int n) {
        System.out.println("Even numbers up to " + n + ": ");
        int i = 0;
        while (i <= n) {
            if (i % 2 == 0)
                System.out.print(i + " ");
            i++;
        }

    }

}