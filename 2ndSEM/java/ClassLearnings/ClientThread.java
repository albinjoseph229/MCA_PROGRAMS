import java.io.*;
import java.net.*;

public class Client extends Thread {

    private Socket socket;
    private Server server;
    private BufferedReader reader;
    private PrintWriter writer;

    public Client(Socket socket, Server server) throws IOException {
        this.socket = socket;
        this.server = server;
        this.reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        this.writer = new PrintWriter(socket.getOutputStream(), true);
    }

    @Override
    public void run() {
        try {
            String message;
            while ((message = reader.readLine()) != null) {
                if (message.equals("quit")) {
                    break;
                }
                System.out.println("Client: " + message);
                server.broadcastMessage(message, this);
            }
        } catch (IOException e) {
            System.err.println("Error reading from client: " + e.getMessage());
        } finally {
            closeConnection();
        }
    }

    public void sendMessage(String message) {
        writer.println(message);
    }

    private void closeConnection() {
        try {
            writer.close();
            reader.close();
            socket.close();
        } catch (IOException e) {
            System.err.println("Error closing client connection: " + e.getMessage());
        }
    }
}
