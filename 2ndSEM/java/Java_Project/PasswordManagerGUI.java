import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

import javax.crypto.*;
import javax.crypto.spec.SecretKeySpec;
import java.io.UnsupportedEncodingException;
import java.security.InvalidKeyException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.sql.*;
import java.util.Base64;
import java.util.Scanner;

public class PasswordManagerGUI extends Application {

    private static final String DATABASE_URL = "jdbc:mysql://localhost:3306/passwords_db";
    private static final String USERNAME = "root";
    private static final String PASSWORD = "";

    private static final String ENCRYPTION_KEY = "ThisIsASecretKey";
    private static final String ENCRYPTION_ALGORITHM = "AES";

    private static final Scanner scanner = new Scanner(System.in);

    private PasswordManager passwordManager = new PasswordManager();

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Password Manager");

        GridPane grid = new GridPane();
        grid.setPadding(new Insets(20, 20, 20, 20));
        grid.setVgap(10);
        grid.setHgap(10);

        Label nameLabel = new Label("Username:");
        GridPane.setConstraints(nameLabel, 0, 0);
        TextField nameInput = new TextField();
        GridPane.setConstraints(nameInput, 1, 0);

        Label passwordLabel = new Label("Password:");
        GridPane.setConstraints(passwordLabel, 0, 1);
        PasswordField passwordInput = new PasswordField();
        GridPane.setConstraints(passwordInput, 1, 1);

        Button loginButton = new Button("Login");
        GridPane.setConstraints(loginButton, 1, 2);
        loginButton.setOnAction(e -> {
            String username = nameInput.getText();
            String password = passwordInput.getText();
            if (passwordManager.login(username, password)) {
                showMainScreen(primaryStage);
            } else {
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("Login Error");
                alert.setHeaderText(null);
                alert.setContentText("Invalid username or password.");
                alert.showAndWait();
            }
        });

        grid.getChildren().addAll(nameLabel, nameInput, passwordLabel, passwordInput, loginButton);

        Scene scene = new Scene(grid, 300, 150);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void showMainScreen(Stage primaryStage) {
        GridPane grid = new GridPane();
        grid.setPadding(new Insets(20, 20, 20, 20));
        grid.setVgap(10);
        grid.setHgap(10);

        // Add main screen components here

        Scene scene = new Scene(grid, 400, 300);
        primaryStage.setScene(scene);
    }

    public static void main(String[] args) {
        launch(args);
    }
}

class PasswordManager {
    public boolean login(String username, String enteredPassword) {
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

    private boolean validatePassword(String enteredPassword, String passwordHashFromDB) {
        // Compare the hashed entered password with the hashed password retrieved from the database
        String hashedEnteredPassword = hashPassword(enteredPassword);
        return hashedEnteredPassword != null && hashedEnteredPassword.equals(passwordHashFromDB);
    }

    // Other methods from the PasswordManager class

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
}
