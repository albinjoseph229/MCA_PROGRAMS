// WAP with nested functions to find the maximum of three numbers.
//  Function1 should take in two arguments and find the maximum. 
//  Function2 should take in the third number and the maximum from function1 to find the maximum.)
import java.io.*;
import java.util.*;

class FourOne {
    public static void main(String[] args) {
        int a, b, c, m;
        Scanner s = new Scanner(System.in);
        System.out.println("Enter three no.s:");
        a = s.nextInt();
        b = s.nextInt();
        c = s.nextInt();

        m = function.func1(a, b);
        function.func2(m, c);

    }
}

class function {
    public static int func1(int n1, int n2) {
        if (n1 > n2) {
            return n1;
        } else {
            return n2;
        }
    }

    public static void func2(int m, int n3) {
        if (m > n3) {
            System.out.println(m + " is  greatest Number");
        } else {
            System.out.println(n3 + " is  greatest Number");
        }
    }
}