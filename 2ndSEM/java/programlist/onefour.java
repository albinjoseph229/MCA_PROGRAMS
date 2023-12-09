import java.io.*;

class onefour {
    public static void main(String args[])
    {
        try{
            DataInputStream d=new DataInputStream(System.in);
            int num1;
            int num2;
            int temp;
            System.out.println("Albin Joseph");
            System.out.println("Enter value of A");
            num1=Integer.parseInt(d.readLine());
            System.out.println("Enter value of B");
            num2=Integer.parseInt(d.readLine());
            temp=num1;
            num1=num2;
            num2=temp;
            System.out.println("After Swapping A="+num1+"B="+num2);
        }
        catch(Exception e)
        {
            System.out.println("Error"+e);
        }
    }    
}
