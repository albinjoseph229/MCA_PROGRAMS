import java.io.*;

class twotwo {
    public static void main(String args[]) {
        try {
            int num1;
            int num2;
            int num3;
            DataInputStream d = new DataInputStream(System.in);
            System.out.println("Albin Joseph");
            System.out.println("Enter First Number");
            num1 = Integer.parseInt(d.readLine());
            System.out.println("Enter second Number");
            num2 = Integer.parseInt(d.readLine());
            System.out.println("Enter third Number");
            num3 = Integer.parseInt(d.readLine());
            int min = Math.min(Math.min(num1, num2), num3);
            System.out.println("Min Number is "+min);
        } catch (Exception e) {
            System.out.println("Error" + e);
        }
    }

}
