import java.io.*;

class twothree {
    public static void main(String args[])
    {
        try{
            DataInputStream d=new DataInputStream(System.in);
            System.out.println("Albin Joseph");
            System.out.println("Enter the size of array");
            int n=Integer.parseInt(d.readLine());
            int[] arr=new int[n];
            for(int i=0;i<n;i++)
            {
                System.out.println("Enter the elements");
                arr[i]=Integer.parseInt(d.readLine());
            }
            System.out.println("Enter the element to search");
            int e=Integer.parseInt(d.readLine());
            for(int i=0;i<n;i++)
            {
                if(arr[i]==e)
                {
                    System.out.println("Elementt Found at index"+i);
                }
            
            }
        }
        catch(Exception e)
        {
            System.out.println("Error"+e);
        }
    }
}