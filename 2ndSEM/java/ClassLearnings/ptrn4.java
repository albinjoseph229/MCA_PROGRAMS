import java.util.*;

public class ptrn4 {
    public static void main(String args[]) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the count:");
        n = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                System.out.print("* ");
            }
            System.out.println(); // Move to the next line after printing each row
        }
        sc.close();
    }
}
/*

Enter the count:
7
* * * * * * *
* * * * * *
* * * * *
* * * *
* * *
* *
*

*/