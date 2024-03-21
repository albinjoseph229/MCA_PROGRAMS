import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import java.sql.*;

public class BusReservationSystemGUI extends Application {
    private static Connection con;
    private static Statement st;
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Bus Reservation System");

        VBox vbox = new VBox();
        vbox.setSpacing(10);
        vbox.setPadding(new Insets(20));

        Label titleLabel = new Label("BUS RESERVATION SYSTEM");
        titleLabel.setStyle("-fx-font-size: 20px;");

        Button loginButton = new Button("Login");
        loginButton.setOnAction(e -> login());

        Button signupButton = new Button("Signup");
        signupButton.setOnAction(e -> signup());

        Button exitButton = new Button("Exit");
        exitButton.setOnAction(e -> {
            System.out.println("Exiting...");
            System.exit(0);
        });

        vbox.getChildren().addAll(titleLabel, loginButton, signupButton, exitButton);

        Scene scene = new Scene(vbox, 300, 250);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void login() {
        Stage loginStage = new Stage();
        loginStage.setTitle("Login");

        VBox vbox = new VBox();
        vbox.setSpacing(10);
        vbox.setPadding(new Insets(20));

        Label usernameLabel = new Label("Username:");
        TextField usernameField = new TextField();

        Label passwordLabel = new Label("Password:");
        PasswordField passwordField = new PasswordField();

        Button loginButton = new Button("Login");
        loginButton.setOnAction(e -> {
            String username = usernameField.getText();
            String password = passwordField.getText();
            authenticateUser(username, password);
            loginStage.close();
        });

        vbox.getChildren().addAll(usernameLabel, usernameField, passwordLabel, passwordField, loginButton);

        Scene scene = new Scene(vbox, 250, 200);
        loginStage.setScene(scene);
        loginStage.show();
    }

    private void authenticateUser(String username, String password) {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/bus?characterEncoding=utf8", "root", "");
            st = con.createStatement();

            String query = "SELECT * FROM users WHERE username='" + username + "' AND password='" + password + "'";
            ResultSet rs = st.executeQuery(query);
            if (rs.next()) {
                System.out.println("Login successful!");
                displayOptions();
            } else {
                System.out.println("Invalid username or password. Please try again.");
            }
        } catch (Exception e) {
            System.out.println("Error: " + e);
        }
    }

    private void signup() {
        Stage signupStage = new Stage();
        signupStage.setTitle("Signup");

        VBox vbox = new VBox();
        vbox.setSpacing(10);
        vbox.setPadding(new Insets(20));

        Label usernameLabel = new Label("Username:");
        TextField usernameField = new TextField();

        Label passwordLabel = new Label("Password:");
        PasswordField passwordField = new PasswordField();

        Button signupButton = new Button("Signup");
        signupButton.setOnAction(e -> {
            String username = usernameField.getText();
            String password = passwordField.getText();
            registerUser(username, password);
            signupStage.close();
        });

        vbox.getChildren().addAll(usernameLabel, usernameField, passwordLabel, passwordField, signupButton);

        Scene scene = new Scene(vbox, 250, 200);
        signupStage.setScene(scene);
        signupStage.show();
    }

    private void registerUser(String username, String password) {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/bus?characterEncoding=utf8", "root", "");
            st = con.createStatement();

            String checkUsernameQuery = "SELECT * FROM users WHERE username='" + username + "'";
            ResultSet existingUserResult = st.executeQuery(checkUsernameQuery);
            if (existingUserResult.next()) {
                System.out.println("Username already exists. Please choose a different username.");
                return;
            }

            String insertUserQuery = "INSERT INTO users (username, password) VALUES ('" + username + "', '" + password + "')";
            st.executeUpdate(insertUserQuery);
            System.out.println("Signup successful! You can now login.");
        } catch (Exception e) {
            System.out.println("Error: " + e);
        }
    }

    private void displayOptions() {
        System.out.println("1. Book a bus");
        System.out.println("2. Logout");

        int choice = scanner.nextInt();
        scanner.nextLine(); // consume newline
        switch (choice) {
            case 1:
                bookBus();
                break;
            case 2:
                System.out.println("Logging out...");
                break;
            default:
                System.out.println("Invalid choice. Please enter a valid option.");
        }
    }

    private void bookBus() {
        try {
            String sql = "select * FROM bus_tb";
            ResultSet rs = st.executeQuery(sql);
            System.out.println("\n\tBUS\n");
            System.out.println("ID\tBUS_NO\t\t\tAVAILABLE SEATS\t\t\tFROM\t\t\tTO");
            System.out.println("_____________________________________________________________________________");
            while (rs.next()) {
                int id = rs.getInt("bid");
                int no = rs.getInt("bus_no");
                int available_seats = rs.getInt("available_seats");
                String from = rs.getString("from");
                String to = rs.getString("To");

                System.out.printf("%-5d\t%-15d\t%-20d\t%-20s\t%-20s\n", id, no, available_seats, from, to);
            }
        } catch (Exception e) {
            System.out.println("Error displaying: " + e);
        }
    }
}
