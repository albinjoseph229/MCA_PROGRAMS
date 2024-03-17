import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.Socket;
import java.net.ServerSocket;

public class FileTransferGUI extends JFrame {
    private JTextField ipField, filePathField, destinationField;
    private JButton sendButton, receiveButton;
    private JLabel statusLabel;

    public FileTransferGUI() {
        setTitle("File Transfer");
        setSize(500, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(6, 1));

        ipField = new JTextField(30);
        filePathField = new JTextField(30);
        destinationField = new JTextField(30);
        sendButton = new JButton("Send File");
        receiveButton = new JButton("Receive File");
        statusLabel = new JLabel();

        JPanel ipPanel = new JPanel();
        ipPanel.setLayout(new FlowLayout());
        ipPanel.add(new JLabel("Enter IP Address: "));
        ipPanel.add(ipField);

        JPanel filePanel = new JPanel();
        filePanel.setLayout(new FlowLayout());
        filePanel.add(new JLabel("Enter File Path: "));
        filePanel.add(filePathField);

        JPanel destPanel = new JPanel();
        destPanel.setLayout(new FlowLayout());
        destPanel.add(new JLabel("Enter Destination: "));
        destPanel.add(destinationField);

        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new FlowLayout());
        buttonPanel.add(sendButton);
        buttonPanel.add(receiveButton);

        JPanel statusPanel = new JPanel();
        statusPanel.setLayout(new FlowLayout());
        statusPanel.add(statusLabel);

        add(ipPanel);
        add(filePanel);
        add(destPanel);
        add(buttonPanel);
        add(statusPanel);

        sendButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String ip = ipField.getText();
                String filePath = filePathField.getText();
                if (!ip.isEmpty() && !filePath.isEmpty()) {
                    sendFile(ip, filePath);
                } else {
                    statusLabel.setText("IP Address or File Path is empty.");
                }
            }
        });

        receiveButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String destination = destinationField.getText();
                if (!destination.isEmpty()) {
                    receiveFile(destination);
                } else {
                    statusLabel.setText("Destination path is empty.");
                }
            }
        });
    }

    private void sendFile(String ip, String filePath) {
        try {
            Socket socket = new Socket(ip, 900);
            DataOutputStream dataOutputStream = new DataOutputStream(socket.getOutputStream());

            File file = new File(filePath);
            FileInputStream fileInputStream = new FileInputStream(file);

            dataOutputStream.writeLong(file.length());

            byte[] buffer = new byte[4 * 1024];
            int bytes;
            while ((bytes = fileInputStream.read(buffer)) != -1) {
                dataOutputStream.write(buffer, 0, bytes);
                dataOutputStream.flush();
            }

            fileInputStream.close();
            dataOutputStream.close();
            socket.close();

            statusLabel.setText("File sent successfully.");
        } catch (IOException ex) {
            statusLabel.setText("Error: " + ex.getMessage());
        }
    }

    private void receiveFile(String destination) {
        try {
            ServerSocket serverSocket = new ServerSocket(900);
            statusLabel.setText("Server waiting for client connection...");
            Socket clientSocket = serverSocket.accept();
            statusLabel.setText("Client connected.");

            DataInputStream dataInputStream = new DataInputStream(clientSocket.getInputStream());
            FileOutputStream fileOutputStream = new FileOutputStream(destination);

            long fileSize = dataInputStream.readLong();

            byte[] buffer = new byte[4 * 1024];
            int bytes;
            while (fileSize > 0 && (bytes = dataInputStream.read(buffer, 0, (int) Math.min(buffer.length, fileSize))) != -1) {
                fileOutputStream.write(buffer, 0, bytes);
                fileSize -= bytes;
            }

            fileOutputStream.close();
            dataInputStream.close();
            clientSocket.close();
            serverSocket.close();

            statusLabel.setText("File received successfully.");
        } catch (IOException ex) {
            statusLabel.setText("Error: " + ex.getMessage());
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new FileTransferGUI().setVisible(true);
            }
        });
    }
}
