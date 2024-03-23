import java.io.*;
import java.net.*;

public class FileDownloader {
    public static void main(String[] args) {
        String fileUrl = "https://example.com/path/to/file.txt"; 
        String saveDir = "downloads";

        try {
            URL url = new URL(fileUrl);
            HttpURLConnection httpConn = (HttpURLConnection) url.openConnection();
            int responseCode = httpConn.getResponseCode();

            // Check if the response code indicates success
            if (responseCode == HttpURLConnection.HTTP_OK) {
                // Open input stream from the connection
                InputStream inputStream = httpConn.getInputStream();

                // Create directory if it doesn't exist
                File directory = new File(saveDir);
                if (!directory.exists()) {
                    directory.mkdir();
                }

                // Extract file name from URL
                String fileName = fileUrl.substring(fileUrl.lastIndexOf("/") + 1);

                // Create output stream to save the file
                FileOutputStream outputStream = new FileOutputStream(saveDir + File.separator + fileName);

                // Read from input stream and write to output stream
                int bytesRead;
                byte[] buffer = new byte[4096];
                while ((bytesRead = inputStream.read(buffer)) != -1) {
                    outputStream.write(buffer, 0, bytesRead);
                }

                // Close streams
                outputStream.close();
                inputStream.close();

                System.out.println("File downloaded successfully.");
            } else {
                System.out.println("Failed to download file. Server returned response code: " + responseCode);
            }
            httpConn.disconnect();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
