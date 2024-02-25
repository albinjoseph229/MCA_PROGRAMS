import javax.crypto.*;
import javax.crypto.spec.SecretKeySpec;

import java.io.UnsupportedEncodingException;
import java.security.InvalidKeyException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.sql.*;
import java.util.Base64;
import java.util.Scanner;

/**
 * The PasswordManager class is responsible for managing passwords in a database.
 * It provides functionality to set up a username and password, login, add, retrieve,
 * edit, and remove passwords.
 */
public class PasswordManager {
    private static final String DATABASE_URL = "jdbc:mysql://localhost:3306/passwords_db";
    private static final String USERNAME = "root";
    private static final String PASSWORD = ""; // If password is empty

    private static final String ENCRYPTION_KEY = "ThisIsASecretKey"; // Change this key
    private static final String ENCRYPTION_ALGORITHM = "AES";

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        if (isFirstTimeLogin()) {
            System.out.println("First-time login detected. Please set up your username and password.");
            setupUsernameAndPassword();
        }

        if (login()) {
            createTableIfNotExists();

            while (true) {
                System.out.println("1. Add a password");
                System.out.println("2. Retrieve a password");
                System.out.println("3. Edit a password");
                System.out.println("4. Remove a password");
                System.out.println("5. Exit");
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
                        editPassword();
                        break;
                    case 4:
                        removePassword();
                        break;
                    case 5:
                        System.out.println("Exiting...");
                        System.exit(0);
                        break;
                    default:
                        System.out.println("Invalid choice. Please try again.");
                }
            }
        } else {
            System.out.println("Login failed. Exiting...");
        }
    }

    private static boolean isFirstTimeLogin() {
        try (Connection connection = DriverManager.getConnection(DATABASE_URL, USERNAME, PASSWORD)) {
            String sql = "SELECT COUNT(*) AS count FROM users";
            try (Statement statement = connection.createStatement()) {
                ResultSet resultSet = statement.executeQuery(sql);
                if (resultSet.next()) {
                    int userCount = resultSet.getInt("count");
                    return userCount == 0; // Return true if there are no users in the database
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return false;
    }

    private static void setupUsernameAndPassword() {
        System.out.print("Set up your username: ");
        String username = scanner.nextLine();

        String password;
        String confirmPassword;
        do {
            System.out.print("Set up your password: ");
            password = scanner.nextLine();
            System.out.print("Confirm your password: ");
            confirmPassword = scanner.nextLine();

            if (!password.equals(confirmPassword)) {
                System.out.println("Passwords do not match. Please try again.");
            }
        } while (!password.equals(confirmPassword));

        // Store the username and password in the database
        try (Connection connection = DriverManager.getConnection(DATABASE_URL, USERNAME, PASSWORD)) {
            String sql = "INSERT INTO users (username, password_hash) VALUES (?, ?)";
            try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
                preparedStatement.setString(1, username);
                preparedStatement.setString(2, hashPassword(password));
                preparedStatement.executeUpdate();
                System.out.println("Username and password set successfully.");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static boolean login() {
        System.out.print("Enter username: ");
        String username = scanner.nextLine();
        System.out.print("Enter password: ");
        String enteredPassword = scanner.nextLine();
    
        try (Connection connection = DriverManager.getConnection(DATABASE_URL, USERNAME, PASSWORD)) {
            String sql = "SELECT password_hash FROM users WHERE username = ?";
            try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
                preparedStatement.setString(1, username);
                ResultSet resultSet = preparedStatement.executeQuery();
                if (resultSet.next()) {
                    String passwordHashFromDB = resultSet.getString("password_hash");
                    return validatePassword(enteredPassword, passwordHashFromDB);
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return false;
    }
    
    private static boolean validatePassword(String enteredPassword, String passwordHashFromDB) {
        // Compare the hashed entered password with the hashed password retrieved from the database
        String hashedEnteredPassword = hashPassword(enteredPassword);
        return hashedEnteredPassword != null && hashedEnteredPassword.equals(passwordHashFromDB);
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
        } catch (NoSuchAlgorithmException | NoSuchPaddingException | InvalidKeyException | BadPaddingException
                | IllegalBlockSizeException | SQLException e) {
            System.out.println("Failed to add password. Please try again.");
            e.printStackTrace();
        }
    }

    private static void removePassword() {
        System.out.print("Enter the website or application name to remove its password: ");
        String name = scanner.nextLine();

        try {
            try (Connection connection = DriverManager.getConnection(DATABASE_URL, USERNAME, PASSWORD)) {
                String sql = "DELETE FROM passwords WHERE name = ?";
                try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
                    preparedStatement.setString(1, name);
                    int rowsAffected = preparedStatement.executeUpdate();
                    if (rowsAffected > 0) {
                        System.out.println("Password for " + name + " removed successfully.");
                    } else {
                        System.out.println("No password found for " + name);
                    }
                }
            }
        } catch (SQLException e) {
            System.out.println("Failed to remove password. Please try again.");
            e.printStackTrace();
        }
    }

    private static void editPassword() {
        System.out.print("Enter the website or application name to edit its password: ");
        String name = scanner.nextLine();
        System.out.print("Enter the new password: ");
        String newPassword = scanner.nextLine();

        try {
            Cipher cipher = Cipher.getInstance(ENCRYPTION_ALGORITHM);
            SecretKeySpec secretKeySpec = new SecretKeySpec(ENCRYPTION_KEY.getBytes(), ENCRYPTION_ALGORITHM);
            cipher.init(Cipher.ENCRYPT_MODE, secretKeySpec);
            byte[] encryptedPassword = cipher.doFinal(newPassword.getBytes());
            String encryptedPasswordBase64 = Base64.getEncoder().encodeToString(encryptedPassword);

            try (Connection connection = DriverManager.getConnection(DATABASE_URL, USERNAME, PASSWORD)) {
                String sql = "UPDATE passwords SET password = ? WHERE name = ?";
                try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
                    preparedStatement.setString(1, encryptedPasswordBase64);
                    preparedStatement.setString(2, name);
                    int rowsAffected = preparedStatement.executeUpdate();
                    if (rowsAffected > 0) {
                        System.out.println("Password for " + name + " updated successfully.");
                    } else {
                        System.out.println("No password found for " + name);
                    }
                }
            }
        } catch (NoSuchAlgorithmException | NoSuchPaddingException | InvalidKeyException | BadPaddingException
                | IllegalBlockSizeException | SQLException e) {
            System.out.println("Failed to edit password. Please try again.");
            e.printStackTrace();
        }
    }
     private static String hashPassword(String password) {
        try {
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            byte[] hash = digest.digest(password.getBytes("UTF-8"));
            return Base64.getEncoder().encodeToString(hash);
        } catch (NoSuchAlgorithmException | UnsupportedEncodingException e) {
            e.printStackTrace();
            return null;
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
        } catch (NoSuchAlgorithmException | NoSuchPaddingException | InvalidKeyException | BadPaddingException
                | IllegalBlockSizeException | SQLException e) {
            System.out.println("Failed to retrieve password. Please try again.");
            e.printStackTrace();
        }
    }
}
