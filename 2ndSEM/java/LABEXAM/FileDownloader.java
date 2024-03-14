import java.io.*;
import java.net.URI;
import java.net.http.*;
import java.nio.file.*;

public class FileDownloader {
    public static void main(String[] args) {
        String fileUrl = "https://example.com/path/to/file.txt"; // Replace with the URL of the file you want to download
        String saveDir = "downloads"; // Directory where you want to save the downloaded file

        try {
            HttpClient httpClient = HttpClient.newHttpClient();
            HttpRequest request = HttpRequest.newBuilder()
                    .uri(URI.create(fileUrl))
                    .build();

            Path filePath = Paths.get(saveDir, "file.txt");
            HttpResponse<InputStream> response = httpClient.send(request, HttpResponse.BodyHandlers.ofInputStream());

            // Create directory if it doesn't exist
            Files.createDirectories(Paths.get(saveDir));

            // Save the downloaded file
            Files.copy(response.body(), filePath, StandardCopyOption.REPLACE_EXISTING);

            System.out.println("File downloaded successfully.");
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}
