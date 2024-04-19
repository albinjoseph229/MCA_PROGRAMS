//TCP Server Program 
import java.net.*;
import java.io.*;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.util.Scanner;
class TServer{
    public static void main(String args[])throws Exception{
        ServerSocket ss;
        Socket as;
        DataInputStream sin;
        DataOutputStream sout;
        try{
            ss=new ServerSocket(9999);
            System.out.println("Server Started Waiting for client");
            as=ss.accept();
            System.out.println("Client Connected");
            sin=new DataInputStream(as.getInputStream());
            sout=new DataOutputStream(as.getOutputStream()); 
            Scanner scanner=new Scanner(System.in);
            String received;
            String toSent;
            while(true){
                received=sin.readUTF();
                System.out.println("Client Says:"+received);
                if(received.equals("bye"))
                {
                    System.out.println("Client is closeing");
                    break;
                }
                System.out.println("Server");
                toSent=scanner.nextLine();
                sout.writeUTF(toSent);
                if(toSent.equals("bye"))
                {
                    System.out.println("Server is closing");
                    break;
                }
            }
            ss.close();
            as.close();
            sin.close();
            sout.close();
            System.out.println("Connection Closed");
        }
        catch(Exception e){
            System.out.println(e);
        } 
    } 
}