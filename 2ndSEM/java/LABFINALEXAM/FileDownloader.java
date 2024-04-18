import java.io.*;
import java.net.*;

public class FileDownloader {

    public static void main(String args[]) throws Exception {
        String urlStr = "https://rajagiri.edu";
        String filePath = "downloaded_files/file.txt";

        URL url = new URL(urlStr);

        InputStream in = url.openStream();
        FileOutputStream out = new FileOutputStream(filePath);

        byte[] buffer = new byte[4096];
        int bytesRead;

        while ((bytesRead = in.read(buffer)) != -1) {
            out.write(buffer, 0, bytesRead);
            System.out.write(buffer, 0, bytesRead);
        }

        System.out.println("File downloaded successfully!");
    }
}
