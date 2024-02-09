// WAP to reverse a number (functions with argument and no return type.)
import java.util.Scanner;

public class ThreeSix {
    // Function to reverse the number
    public static void reverseNumber(int num) {
        int reversedNum = 0;

        // Reverse the number
        while (num != 0) {
            int digit = num % 10; // Extract the last digit
            reversedNum = reversedNum * 10 + digit; // Append the digit to the reversed number
            num /= 10; // Remove the last digit from the original number
        }

        // Print the reversed number
        System.out.println("Reversed number: " + reversedNum);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the number from the user
        System.out.print("Enter a number to reverse: ");
        int number = scanner.nextInt();

        // Call the function to reverse the number
        reverseNumber(number);

        // Close the scanner
        scanner.close();
    }
}