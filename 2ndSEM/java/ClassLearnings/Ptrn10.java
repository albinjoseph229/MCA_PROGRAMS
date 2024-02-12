import java.util.*;

public class Ptrn10 {
    public static void main(String args[]) {
        int n;
        int j;
        Scanner sc = new Scanner(System.in);
        System.out.println("enter the count");
        {
            n = Integer.parseInt(sc.nextLine());
        }

        for (int i = n; i > 0; i--) {
            for (j = 0; j <= n; j++) {
                if (j < i) {
                    System.out.print(" ");
                } else {
                    System.out.print( " *");
                }
            }
            System.out.println();
        }
        sc.close();
    }

}
/*
enter the count
5
      *
     * *
    * * *
   * * * *
  * * * * *
 
 */