import java.io.*;

public class FileCopier {
    public static void main(String[] args) {
        String sourceFilePath = "source.txt"; // Path of the source file
        String destinationFilePath = "destination.txt"; // Path of the destination file

        try (BufferedReader reader = new BufferedReader(new FileReader(sourceFilePath));
             BufferedWriter writer = new BufferedWriter(new FileWriter(destinationFilePath))) {

            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
                writer.write(line); // Write current line to destination file
                writer.newLine(); // Add newline character
            }

            System.out.println("File copied successfully!");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
