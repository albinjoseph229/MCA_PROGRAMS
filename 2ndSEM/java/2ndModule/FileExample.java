import java.io.File;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.IOException;

public class FileExample {
    public static void main(String[] args) {
        String fileName = "example.txt";
        String data = "Hello, World!";

        // Create a new file
        File file = new File(fileName);

        // Write data to the file
        try (FileOutputStream fos = new FileOutputStream(file)) {
            fos.write(data.getBytes());
            System.out.println("Data written to file successfully.");
        } catch (IOException e) {
            System.out.println("Error writing data to file: " + e.getMessage());
        }

        // Read data from the file
        try (FileInputStream fis = new FileInputStream(file)) {
            byte[] buffer = new byte[(int) file.length()];
            fis.read(buffer);
            String readData = new String(buffer);
            System.out.println("Data read from file: " + readData);
        } catch (IOException e) {
            System.out.println("Error reading data from file: " + e.getMessage());
        }
    }
}
