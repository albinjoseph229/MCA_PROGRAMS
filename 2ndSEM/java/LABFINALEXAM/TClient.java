//TCP Client Programe
import java.net.*;
import java.util.Scanner;
import java.io.*;
import java.io.DataInputStream;
import java.io.DataOutputStream;
class TClient{
    public static void main(String args[]) {
        Socket cs;
        DataInputStream sin;
        DataOutputStream sout;
        try{
            cs=new Socket("localhost",1234);
            System.out.println("Connected to Server");
            sin=new DataInputStream(cs.getInputStream());
            sout=new DataOutputStream(cs.getOutputStream());
            Scanner scanner=new Scanner(System.in);
            String received;
            String toSent;
            while(true){
                System.out.println("Client:");
                toSent=scanner.nextLine();
                sout.writeUTF(toSent);
                if(toSent.equals("bye"))
                {
                    System.out.println("Client is closing");
                    break;
                }
                received=sin.readUTF();
                System.out.println("Server:"+received);
                if(received.equals("bye"))
                {
                    System.out.println("Server is closing");
                    break;
                }
            }
            cs.close();
            sin.close();
            sout.close();

        }
        catch(Exception e){
            System.out.println(e);
        }
    }
}