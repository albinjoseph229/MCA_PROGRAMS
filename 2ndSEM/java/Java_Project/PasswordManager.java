import javax.crypto.*;
import javax.crypto.spec.SecretKeySpec;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.sql.*;
import java.util.Base64;
import java.util.Scanner;

public class PasswordManager {
    private static final String DATABASE_URL = "jdbc:mysql://localhost:3306/passwords_db";
    private static final String USERNAME = "root";
    private static final String PASSWORD = ""; // If password is empty

    private static final String ENCRYPTION_KEY = "ThisIsASecretKey"; // Change this key
    private static final String ENCRYPTION_ALGORITHM = "AES";

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        if (login()) {
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
        } else {
            System.out.println("Login failed. Exiting...");
        }
    }

    private static boolean login() {
        System.out.print("Enter username: ");
        String username = scanner.nextLine();
        System.out.print("Enter password: ");
        String enteredPassword = scanner.nextLine();

        // Check if username and password are valid (for simplicity, hardcoded)
        return username.equals("admin") && enteredPassword.equals("admin123");
    }

    private static void createTableIfNotExists() {
        try (Connection connection = DriverManager.getConnection(DATABASE_URL, USERNAME, PASSWORD)) {
            String sql = "CREATE TABLE IF NOT EXISTS passwords (name VARCHAR(100) PRIMARY KEY, password VARCHAR(200))";
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

        try {
            Cipher cipher = Cipher.getInstance(ENCRYPTION_ALGORITHM);
            SecretKeySpec secretKeySpec = new SecretKeySpec(ENCRYPTION_KEY.getBytes(), ENCRYPTION_ALGORITHM);
            cipher.init(Cipher.ENCRYPT_MODE, secretKeySpec);
            byte[] encryptedPassword = cipher.doFinal(password.getBytes());

            // Convert encrypted password byte array to Base64 for storage
            String encryptedPasswordBase64 = Base64.getEncoder().encodeToString(encryptedPassword);

            try (Connection connection = DriverManager.getConnection(DATABASE_URL, USERNAME, PASSWORD)) {
                String sql = "INSERT INTO passwords (name, password) VALUES (?, ?)";
                try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
                    preparedStatement.setString(1, name);
                    preparedStatement.setString(2, encryptedPasswordBase64);
                    preparedStatement.executeUpdate();
                    System.out.println("Password added successfully.");
                }
            }
        } catch (NoSuchAlgorithmException | NoSuchPaddingException | InvalidKeyException |
                BadPaddingException | IllegalBlockSizeException | SQLException e) {
            System.out.println("Failed to add password. Please try again.");
            e.printStackTrace();
        }
    }

    private static void retrievePassword() {
        System.out.print("Enter the website or application name: ");
        String name = scanner.nextLine();

        try {
            Cipher cipher = Cipher.getInstance(ENCRYPTION_ALGORITHM);
            SecretKeySpec secretKeySpec = new SecretKeySpec(ENCRYPTION_KEY.getBytes(), ENCRYPTION_ALGORITHM);
            cipher.init(Cipher.DECRYPT_MODE, secretKeySpec);

            try (Connection connection = DriverManager.getConnection(DATABASE_URL, USERNAME, PASSWORD)) {
                String sql = "SELECT password FROM passwords WHERE name = ?";
                try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
                    preparedStatement.setString(1, name);
                    ResultSet resultSet = preparedStatement.executeQuery();
                    if (resultSet.next()) {
                        String encryptedPasswordBase64 = resultSet.getString("password");
                        byte[] encryptedPassword = Base64.getDecoder().decode(encryptedPasswordBase64);
                        byte[] decryptedPassword = cipher.doFinal(encryptedPassword);
                        String password = new String(decryptedPassword);

                        System.out.println("Password: " + password);
                    } else {
                        System.out.println("Password not found for " + name);
                    }
                }
            }
        } catch (NoSuchAlgorithmException | NoSuchPaddingException | InvalidKeyException |
                BadPaddingException | IllegalBlockSizeException | SQLException e) {
            System.out.println("Failed to retrieve password. Please try again.");
            e.printStackTrace();
        }
    }
}
