//WAP to display numbers from n to 1 and vice versa, using recursion.

import java.io.*;
import java.util.*;

class FourThree {
    public static void main(String args[]) {
        int n;
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the value for n:");
        n = s.nextInt();
        func1(n);
        System.out.println();
        func2(n);
    }

    static void func1(int n) {
        if (n >= 1) {

            func1(n - 1);
            System.out.print("\t" + n);
        }
    }

    static void func2(int n) {
        if (n >= 1) {
            System.out.print("\t" + n);
            func2(n - 1);

        }
    }
}