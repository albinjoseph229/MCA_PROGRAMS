import java.io.*;

public class threeone {
    public static void main(String args[]) {
        int a;
        DataInputStream din = new DataInputStream(System.in);
        System.out.print("Enter number to check palindrome or not: ");
        try {
            a = Integer.parseInt(din.readLine());
            if (isPalindrome(a)) {
                System.out.println(a + " is a palindrome.");
            } else {
                System.out.println(a + " is not a palindrome.");
            }
        } catch (Exception e) {
            System.err.println("Error " + e);
        }

    }

    private static int reverseInteger(int num) {
        int reversed = 0;
        while (num != 0) {
            int digit = num % 10;
            reversed = reversed * 10 + digit;
            num /= 10;
        }
        return reversed;
    }

    private static boolean isPalindrome(int num) {
        return num == reverseInteger(num);
    }
}