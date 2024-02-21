import java.sql.*;
import java.util.Scanner;

public class PasswordManager {
    private static final String DATABASE_URL = "jdbc:mysql://localhost:3306/passwords_db";
    private static final String USERNAME = "root";
    private static final String PASSWORD = ""; // If password is empty

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        createTableIfNotExists();

        while (true) {
            System.out.println("1. Add a password");
            System.out.println("2. Retrieve a password");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // consume newline

            switch (choice) {
                case 1:
                    addPassword();
                    break;
                case 2:
                    retrievePassword();
                    break;
                case 3:
                    System.out.println("Exiting...");
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }

    private static void createTableIfNotExists() {
        try (Connection connection = DriverManager.getConnection(DATABASE_URL, USERNAME, PASSWORD)) {
            String sql = "CREATE TABLE IF NOT EXISTS passwords (name VARCHAR(100) PRIMARY KEY, password VARCHAR(100))";
            try (Statement statement = connection.createStatement()) {
                statement.executeUpdate(sql);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void addPassword() {
        System.out.print("Enter the website or application name: ");
        String name = scanner.nextLine();
        System.out.print("Enter the password: ");
        String password = scanner.nextLine();

        try (Connection connection = DriverManager.getConnection(DATABASE_URL, USERNAME, PASSWORD)) {
            String sql = "INSERT INTO passwords (name, password) VALUES (?, ?)";
            try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
                preparedStatement.setString(1, name);
                preparedStatement.setString(2, password);
                preparedStatement.executeUpdate();
                System.out.println("Password added successfully.");
            }
        } catch (SQLException e) {
            System.out.println("Failed to add password. Please try again.");
        }
    }

    private static void retrievePassword() {
        System.out.print("Enter the website or application name: ");
        String name = scanner.nextLine();

        try (Connection connection = DriverManager.getConnection(DATABASE_URL, USERNAME, PASSWORD)) {
            String sql = "SELECT password FROM passwords WHERE name = ?";
            try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
                preparedStatement.setString(1, name);
                ResultSet resultSet = preparedStatement.executeQuery();
                if (resultSet.next()) {
                    String password = resultSet.getString("password");
                    System.out.println("Password: " + password);
                } else {
                    System.out.println("Password not found for " + name);
                }
            }
        } catch (SQLException e) {
            System.out.println("Failed to retrieve password. Please try again.");
        }
    }
}
