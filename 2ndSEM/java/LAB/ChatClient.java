import java.net.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.IOException;

public class ChatClient {
    public static void main(String[] args) {
        try {
            String serverIP = "103.141.56.210"; // Replace with the actual IP address of the server

            Socket socket = new Socket(serverIP, 5000);
            System.out.println("Connected to server: " + socket.getInetAddress().getHostAddress());

            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

            BufferedReader consoleInput = new BufferedReader(new InputStreamReader(System.in));

            String serverMessage;
            String clientMessage;

            while (true) {
                // Read message from the server
                serverMessage = in.readLine();
                System.out.println("Server: " + serverMessage);

                // If the server sends "bye", exit the loop and close the connection
                if (serverMessage.equalsIgnoreCase("bye")) {
                    break;
                }

                // Read message from the client console and send it to the server
                System.out.print("Client: ");
                clientMessage = consoleInput.readLine();
                out.println(clientMessage);
            }

            // Close resources
            in.close();
            out.close();
            consoleInput.close();
            socket.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}