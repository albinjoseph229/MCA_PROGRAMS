import java.io.*;
import java.net.*;

public class FileDownloader {
    public static void main(String[] args) throws Exception {
        String fileUrl = "https://rajagiri.edu"; // URL of the file to download
        String savePath = "downloaded_file.txt"; // Local path to save the downloaded file
        URL url=new URL(fileUrl);

        InputStream inputStream =url.openStream();

        FileOutputStream outputStream = new FileOutputStream(savePath);

        byte[] buffer = new byte[4096]; // Buffer to hold the data

        int bytesRead;
        
        while ((bytesRead = inputStream.read(buffer)) != -1) {
            outputStream.write(buffer, 0, bytesRead); // Write to output stream
            System.out.write(buffer, 0, bytesRead); // Print to console
        }
        System.out.println("\nFile downloaded successfully!");
    }
}
