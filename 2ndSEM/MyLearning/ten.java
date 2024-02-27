import java.io.*;
import java.util.Scanner;
class ten{
    public static void main(String args[]){
        FileOutputStream fout;
        Scanner s =new Scanner(System.in);
        String fname;
        String data;
        try{
            System.out.println("Enter the file name");
            fname=s.nextLine();
            System.out.println("Enter the data");
            data=s.nextLine();
            while(!data.equals("quit")){
                fout.write(data.getBytes());
                data=s.nextLine();
            }
            fout.close();
        }
        catch(Exception e){
            
        }
    }
}