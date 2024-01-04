import java.io.*;
class twofive
{
    public static void main(String args[])
    {
        System.out.println("Albin Joseph");
        int arr[][]=new int[10][10];
        DataInputStream din=new DataInputStream(System.in);
        int rno,cno,rsum,csum,i,j;
        try
        {
            System.out.println("Enter number of colums");
            rno=Integer.parseInt(din.readLine());
            System.out.println("Enter the number of rows");
            cno=Integer.parseInt(din.readLine());
            for(i=0;i<rno;i++)
            {
                for(j=0;j<cno;j++)
                {
                    System.out.println("enter the["+i+"]["+j+"] th element");
                    arr[i][j]=Integer.parseInt(din.readLine());
                }
            }
            System.out.println("Rowsum is ");
            for(i=0;i<rno;i++)
            {
                rsum=0;
                for(j=0;j<cno;j++)
                {
                    rsum=rsum+arr[i][j];
                    System.out.println(""+arr[i][j]);
                }
                System.out.println("|"+rsum);
            }
            System.out.println("Column Sum is");
            for(i=0;i<cno;i++)
            {
                csum=0;
                for(j=0;j<rno;j++);
                {
                    csum=csum+arr[i][j];
                    System.out.println(""+arr[i][j]);
                }
                System.out.println("|"+csum);
            }
        }
        catch(Exception e)
        {
            System.out.println("Error"+e);
        }  
    }
}