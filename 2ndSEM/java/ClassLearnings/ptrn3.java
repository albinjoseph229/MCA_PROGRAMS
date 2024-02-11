import java.util.*;
public class ptrn3 {
    public static void main(String args[]){
        int n;
        Scanner sc=new Scanner(System.in);
        System.out.println("enter the count");{
            n = Integer.parseInt(sc.nextLine());
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=i;j++){
                    System.out.print("*");
            }
            System.out.println();
        }
        sc.close();
    }
    
}
/*
output

enter the count
7

*
**
***
****
*****
******
*******

*/