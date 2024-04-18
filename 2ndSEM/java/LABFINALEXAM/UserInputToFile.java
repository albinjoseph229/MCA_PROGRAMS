import java.io.*;

public class UserInputToFile {
    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            System.out.println("Enter text (type 'exit' to quit):");

            // Open the file for writing
            BufferedWriter writer = new BufferedWriter(new FileWriter("output.txt"));

            String userInput;
            while (!(userInput = reader.readLine()).equalsIgnoreCase("exit")) {
                // Write the user input to the file
                writer.write(userInput);
                writer.newLine(); // Add newline after each input line
            }

            // Close the writer
            writer.close();
            System.out.println("Data written to output.txt successfully.");
        } catch (IOException e) {
            System.out.println("An error occurred: " + e.getMessage());
        }
    }
}
