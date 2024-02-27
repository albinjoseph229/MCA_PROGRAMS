import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class FileTransfer {
    public static void main(String args[]) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            while (true) {
                System.out.println("1: Send 2: Receive 3: Quit");
                int ch = Integer.parseInt(reader.readLine());
                if (ch == 1) {
                    ProcessBuilder processBuilder = new ProcessBuilder("java", "Client");
                    processBuilder.inheritIO(); // Redirect output to console

                    // Start the process
                    Process process = processBuilder.start();

                    // Wait for the process to complete (optional)
                    int exitCode = process.waitFor();
                    System.out.println("Exit code: " + exitCode);
                } else if (ch == 2) {
                    ProcessBuilder processBuilder = new ProcessBuilder("java", "Server");
                    processBuilder.inheritIO(); // Redirect output to console

                    // Start the process
                    Process process = processBuilder.start();

                    // Wait for the process to complete (optional)
                    int exitCode = process.waitFor();
                    System.out.println("Exit code: " + exitCode);
                } else if (ch == 3) {
                    System.exit(0);
                }
            }
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}
