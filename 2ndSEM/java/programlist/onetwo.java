import java.io.*;
class onetwo{
    public static void main(String args[])
    {
        try
        {
            System.out.println("Albin Joseph");
            int num1;
            int num2;
            DataInputStream d=new DataInputStream(System.in);
            System.out.println("Enter first number");
            num1=Integer.parseInt(d.readLine());
            System.out.println("Enter second number");
            num2=Integer.parseInt(d.readLine());
            System.out.println("sum is"+(num1+num2));
        }
        catch(Exception e)
        {
            System.out.println("Error"+e);
        }
    }

}