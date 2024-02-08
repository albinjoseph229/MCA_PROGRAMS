// WAP to display numbers from m to n using single while loop.
import java.util.*;

public class ThreeTwo {
    public static void main(String args[]) {
        int M, N;

        try {
            Scanner s = new Scanner(System.in);
            System.out.print("Enter value for M: ");
            M = s.nextInt();
            System.out.print("Enter the value for  N: ");
            N = s.nextInt();
            loop1(M, N);

        } catch (Exception e) {
            System.out.println("Error" + e);
        }

    }

    public static void loop1(int a, int b) {

        while (a != b) {
            System.out.print("\t" + a);
            if (a < b) {

                a++;
            } else {

                a--;
            }

        }
        System.out.print("\t" + a);

    }
}