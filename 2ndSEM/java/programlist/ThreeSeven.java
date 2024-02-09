//WAP to calculate sum of digits of a number 
//(functions with argument and return type.)
import java.util.*;

public class ThreeSeven {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        System.out.println("Enter a number: ");
        int number = s.nextInt();
        int sum = sumofdigits(number);

        System.out.println("Sum of digits: " + sum);

        s.close();
    }

    public static int sumofdigits(int num) {

        int sum = 0;

        while (num != 0) {
            int digit = num % 10;
            sum += digit;
            num /= 10;
        }
        return sum;

    }

}