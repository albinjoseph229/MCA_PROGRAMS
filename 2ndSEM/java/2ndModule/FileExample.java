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
// We start by defining a file name (example.txt) and some data (Hello, World!) that we want to write to the file.

// We create a new File object named file representing the file with the specified file name.

// Using a FileOutputStream, we write the data to the file. We convert the data string to bytes using getBytes() method and then write these bytes to the file using the write() method.

// We use a try-with-resources statement to automatically close the FileOutputStream after use, ensuring proper resource management and exception handling.

// We then use a FileInputStream to read the data from the file. We create a byte array (buffer) to store the data and read bytes from the file into this buffer using the read() method.

// We convert the bytes back to a string using the String constructor and print the read data to the console.

// Again, we use a try-with-resources statement to automatically close the FileInputStream after use.