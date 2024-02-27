import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    private static DataOutputStream dataOutputStream = null;
    private static DataInputStream dataInputStream = null;
    static DataInputStream in=new DataInputStream(System.in);

    public static void main(String args[]) {
        // Create Server Socket on port 900
        try (ServerSocket serverSocket = new ServerSocket(900)) {
            System.out.println("Server waiting for client connection...");

            // Accept client connection
            Socket clientSocket = serverSocket.accept();
            System.out.println("Client connected.");

            dataInputStream = new DataInputStream(clientSocket.getInputStream());
            dataOutputStream = new DataOutputStream(clientSocket.getOutputStream());

            // Call receiveFile method to receive file from the client
            System.out.println("Enter the Destination");
            String path=in.readLine();

            receiveFile(path);

            dataInputStream.close();
            dataOutputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void receiveFile(String savePath) throws IOException {
        int bytes;
        long fileSize = dataInputStream.readLong();
        FileOutputStream fileOutputStream = new FileOutputStream(savePath);

        byte[] buffer = new byte[4 * 1024];
        while (fileSize > 0 && (bytes = dataInputStream.read(buffer, 0, (int) Math.min(buffer.length, fileSize))) != -1) {
            fileOutputStream.write(buffer, 0, bytes);
            fileSize -= bytes;
        }

        fileOutputStream.close();
        System.out.println("File received successfully.");
    }
}
