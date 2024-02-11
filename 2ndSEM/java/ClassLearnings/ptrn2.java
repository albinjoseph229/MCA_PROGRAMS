import java.util.*;
public class ptrn2 {
    ;
    public static void main(String args[]){
        int count;
        Scanner sc=new Scanner(System.in);
        System.out.println("enter the count");{
            count = Integer.parseInt(sc.nextLine());
        }
        for(int i=1;i<=count;i++){
            for(int j=1;j<=count;j++){
                if(i==1||j==1||i==count||j==count){
                    System.out.print("* ");
                }
                else{
                    System.out.print("  ");
                }
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
* * * * * * * 
*           * 
*           * 
*           * 
*           * 
*           * 
* * * * * * * 
 */