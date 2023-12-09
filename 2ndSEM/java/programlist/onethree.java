import java.io.*;

class onethree {
    public static void main(String args[]) {
        DataInputStream din = new DataInputStream(System.in);
        try {
            int num1, num2;
            System.out.println("Albin Joseph");
            System.out.println("Enter the first number:");
            num1 = Integer.parseInt(din.readLine());

            System.out.println("Enter the second number:");
            num2 = Integer.parseInt(din.readLine());

            System.out.println("Sum of " + num1 + " and " + num2 + " is " + (num1 + num2));
        } catch (Exception e) {
            System.out.println("Error: " + e);
        }
    }
}
