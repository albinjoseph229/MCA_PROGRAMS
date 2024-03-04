import java.net.*;

public class UDPClient {
    public static void main(String[] args) {
        DatagramSocket socket = null;
        
        try {
            // Create a DatagramSocket
            socket = new DatagramSocket();
            
            // Specify the IP address and port number of the server
            InetAddress serverAddress = InetAddress.getByName("localhost");
            int serverPort = 9876;
            
            // Prepare data to be sent to the server
            String message = "Hello from client";
            byte[] sendData = message.getBytes();
            
            // Create a DatagramPacket to send data
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, serverAddress, serverPort);
            
            // Send data to server
            socket.send(sendPacket);
            
            // Receive response from server
            byte[] receiveData = new byte[1024];
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
            socket.receive(receivePacket);
            
            // Extract data from the received packet
            String receivedMessage = new String(receivePacket.getData(), 0, receivePacket.getLength());
            
            // Display response received from server
            System.out.println("Received response from server: " + receivedMessage);
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            // Close the socket
            if (socket != null) {
                socket.close();
            }
        }
    }
}
