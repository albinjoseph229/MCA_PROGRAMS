//WAP to find the sum of 1+2/2!+3/3!+4/4!++n/n! using a single for loop.

import java.util.Scanner;

public class ThreeFour {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the value of n
        System.out.print("Enter the value of n: ");
        int n = scanner.nextInt();

        // Initialize the total sum
        int tsum = 0;
        int fact = 1; // Initialize factorial

        // Calculate the sum of the series using a single for loop
        for (int i = 1; i <= n; i++) {
            fact *= i; // Calculate factorial of i

            // Add the term to the total sum
            tsum += i / fact;
            System.out.print("\t" + tsum);
        }

        // Print the sum of the series

        // Close the scanner
        scanner.close();
    }
}