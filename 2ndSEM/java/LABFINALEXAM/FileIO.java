import java.io.*;
import java.util.Scanner;

public class FileIO {
    public static void main(String[] args) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("a.txt"));
             Scanner scanner = new Scanner(System.in)) {
            System.out.println("Enter the input:");
            String s = scanner.nextLine();
            writer.write(s);
            System.out.println("Data written to a.txt successfully.");
        } catch (IOException e) {
            System.out.println("An error occurred: " + e.getMessage());
        }
    }
}
