// WAP to find the factorial of n, using recursion.

import java.io.*;
import java.util.*;

public class FourTwo {
    public static void main(String[] args) {
        int n;
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the no. to find factorial: ");
        n = s.nextInt();

        System.out.println("factorial of " + n + "  is " + fact(n));
    }

    static int fact(int n) {
        if (n >= 1)
            return n * fact(n - 1);
        else
            return 1;
    }
}