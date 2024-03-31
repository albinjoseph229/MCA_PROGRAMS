import java.io.File;

public class ListDirectoryContents {
    public static void main(String[] args) {
        // Specify the directory path
        String directoryPath = "path/to/your/directory";

        // Create a File object for the directory
        File directory = new File(directoryPath);

        // Check if the directory exists
        if (directory.exists() && directory.isDirectory()) {
            // List the contents of the directory
            File[] files = directory.listFiles();
            if (files != null) {
                System.out.println("Contents of directory: " + directoryPath);
                for (File file : files) {
                    System.out.println(file.getName());
                }
            } else {
                System.out.println("Directory is empty.");
            }
        } else {
            System.out.println("Invalid directory path.");
        }
    }
}
