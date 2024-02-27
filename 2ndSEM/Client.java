import java.io.*;
import java.net.Socket;

public class Client {
    private static DataOutputStream dataOutputStream = null;
    private static DataInputStream dataInputStream = null;
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    
    public static void main(String[] args) {
        // Create Client Socket connect to port 900
        try {
            System.out.println("Enter the ip address of the receiver");
            String ip=reader.readLine();
            Socket socket = new Socket(ip, 900); 
            dataInputStream = new DataInputStream(socket.getInputStream());
            dataOutputStream = new DataOutputStream(socket.getOutputStream());

            System.out.println("Enter the path of file to send");
            String path=reader.readLine();
            System.out.println("Sending the File to the Server");
            // Call sendFile method to send file to the server
            sendFile(path);

            dataInputStream.close();
            dataOutputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void sendFile(String filePath) throws IOException {
        int bytes = 0;
        File file = new File(filePath);
        FileInputStream fileInputStream = new FileInputStream(file);

        // Send file size to the server
        dataOutputStream.writeLong(file.length());

        // Send the file to the server
        byte[] buffer = new byte[4 * 1024];
        while ((bytes = fileInputStream.read(buffer)) != -1) {
            dataOutputStream.write(buffer, 0, bytes);
            dataOutputStream.flush();
        }

        fileInputStream.close();
        System.out.println("File sent successfully.");
    }
}
