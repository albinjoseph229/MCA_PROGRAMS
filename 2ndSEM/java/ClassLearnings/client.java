import java.io.*;
import java.net.*;
import java.util.Scanner;

public class client {
    public static void main(String args[]) {
        Socket as;
        DataInputStream sin;
        DataOutputStream sout;
        try {
            as = new Socket("localhost", 1234);
            System.out.println("Connected to server.");

            sin = new DataInputStream(as.getInputStream());
            sout = new DataOutputStream(as.getOutputStream());

            Scanner scanner = new Scanner(System.in);

            String received;
            String toSend;

            while (true) {
                System.out.print("Client: ");
                toSend = scanner.nextLine();
                sout.writeUTF(toSend);
                if (toSend.equals("quit")) {
                    System.out.println("Client is closing...");
                    break;
                }

                received = sin.readUTF();
                System.out.println("Server says: " + received);
                if (received.equals("quit")) {
                    System.out.println("Server is stopping...");
                    break;
                }
            }

            as.close();
            scanner.close();
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}
