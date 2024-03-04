import java.net.*;

public class UDPServer {
    public static void main(String[] args) {
        DatagramSocket socket = null;
        
        try {
            // Create a DatagramSocket bound to port 9876
            socket = new DatagramSocket(9876);
            
            byte[] receiveData = new byte[1024];
            
            while (true) {
                // Create a DatagramPacket to receive data
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                
                // Receive data from client
                socket.receive(receivePacket);
                
                // Extract data from the received packet
                String receivedMessage = new String(receivePacket.getData(), 0, receivePacket.getLength());
                
                // Display received message
                System.out.println("Received message from client: " + receivedMessage);
                
                // Prepare data to be sent back to client
                String responseMessage = "Message received successfully";
                byte[] sendData = responseMessage.getBytes();
                
                // Create a DatagramPacket to send data
                DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, receivePacket.getAddress(), receivePacket.getPort());
                
                // Send data back to client
                socket.send(sendPacket);
            }
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
