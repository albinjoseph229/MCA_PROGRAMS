import java.io.*;
import java.net.*;
import java.util.Scanner;

public class server {
    public static void main(String args[]) {
        ServerSocket ss;
        Socket as;
        DataInputStream sin;
        DataOutputStream sout;
        try {
            ss = new ServerSocket(1234);
            System.out.println("Server started. Waiting for a client...");

            as = ss.accept();
            System.out.println("Client connected.");

            sin = new DataInputStream(as.getInputStream());
            sout = new DataOutputStream(as.getOutputStream());

            Scanner scanner = new Scanner(System.in);

            String received;
            String toSend;

            while (true) {
                received = sin.readUTF();
                System.out.println("Client says: " + received);
                if (received.equals("quit")) {
                    System.out.println("Client is closing...");
                    break;
                }

                System.out.print("Server: ");
                toSend = scanner.nextLine();
                sout.writeUTF(toSend);
                if (toSend.equals("quit")) {
                    System.out.println("Server is stopping...");
                    break;
                }
            }

            as.close();
            ss.close();
            scanner.close();
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
