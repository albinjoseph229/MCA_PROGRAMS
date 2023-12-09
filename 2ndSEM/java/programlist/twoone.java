import java.io.*;
class twoone {
    public static void main(String args[])
    {
        try{
            int num1;
            int num2;
            int num3;
            DataInputStream d=new DataInputStream(System.in);
            System.out.println("Albin Joseph");
            System.out.println("Enter First Number");
            num1=Integer.parseInt(d.readLine());
            System.out.println("Enter second Number");
            num2=Integer.parseInt(d.readLine());
            System.out.println("Enter third Number");
            num3=Integer.parseInt(d.readLine());
            if(num2>num1&&num2>num3)
            {
                System.out.println(num2+" is the largest number");
            }
            else if(num1>num2&&num1>num3)
            {
                System.out.println(num1+" is the largest number");
            }
            else
            {
                System.out.println(num3+" is the largest number");
            }
        }
        catch(Exception e)
        {
            System.out.println("Error"+e);
        }
    }
    
}
