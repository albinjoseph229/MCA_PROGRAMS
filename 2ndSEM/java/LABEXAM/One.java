package LABEXAM;
import java.util.*;
public class One {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number1");
        int num1=sc.nextInt();
        System.out.println("Number1="+num1);
        System.out.println("Enter number2");
        int num2=sc.nextInt();
        System.out.println("Number2="+num2);
        int output= num1+num2;
        System.out.println("Output="+output);
        sc.close();
    }

}
