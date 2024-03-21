r
import java.sql.*;
import java.util.Scanner;

class bdi {
    Connection con;
    Statement st;

    public bdi(String dbname) {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/" + dbname + "?characterEncoding=utf8",
                    "root", "");
            if (con != null) {
                st = con.createStatement();
            } else {
                System.out.println("Failed to establish connection.");
            }
        } catch (Exception e) {
            System.out.println("Error :" + e);
        }
    }

    public void idu(String sql) {
        try {
            st.executeUpdate(sql);
        } catch (Exception e) {
            System.out.println("Error :" + e);
        }
    }

    public ResultSet select(String sql) {
        ResultSet rs = null;
        try {
            rs = st.executeQuery(sql);
        } catch (Exception e) {
            System.out.println("Error :" + e);
        }
        return rs;
    }
}

public class bus_reservation_system {
    private static Scanner scanner = new Scanner(System.in);
    private static bdi bs = new bdi("bus");

    public static void main(String args[]) {

        System.out.println("BUS RESERVATION SYSTEM");
        System.out.println("1. Login");
        System.out.println("2. Signup");
        System.out.println("3. Exit");
        System.out.print("Enter your choice: ");

        int choice = scanner.nextInt();
        scanner.nextLine();

        switch (choice) {
            case 1:
                login();
                break;
            case 2:

                break;
            case 3:
                System.out.println("Exiting...");
                System.exit(0);
                break;
            default:
                System.out.println("Invalid choice. Please enter a valid option.");
        }

    }

    public static void login() {
    System.out.println("Login");
    System.out.print("Enter username: ");
    String username = scanner.nextLine();
    System.out.print("Enter password: ");
    String password = scanner.nextLine();

    String query = "SELECT * FROM users WHERE username='" + username + "' AND password='" + password + "'";
    ResultSet rs = bs.select(query);
    try {
        if (rs.next()) {
            System.out.println("Login successful!");
            // After successful login, prompt the user to choose an action
            
            System.out.println("2. Book a bus");
            System.out.println("3. Logout");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // consume newline
            switch (choice) {
                case 1:
                    display();
                    break;
                case 2:
                    bookBus();
                    break;
                case 3:
                    System.out.println("Logging out...");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }
        } else {
            System.out.println("Invalid username or password. Please try again.");
        }
    } catch (Exception e) {
        System.out.println("Error: " + e);
    }
}

public static void signup() {
    System.out.println("Signup");
    System.out.print("Enter username: ");
    String username = scanner.nextLine();
    System.out.print("Enter password: ");
    String password = scanner.nextLine();

    // Check if the username already exists
    String checkUsernameQuery = "SELECT * FROM users WHERE username='" + username + "'";
    ResultSet existingUserResult = bs.select(checkUsernameQuery);
    try {
        if (existingUserResult.next()) {
            System.out.println("Username already exists. Please choose a different username.");
            return;
        }
    } catch (SQLException e) {
        System.out.println("Error: " + e);
        return;
    }

    // Insert new user into the database
    String insertUserQuery = "INSERT INTO users (username, password) VALUES ('" + username + "', '" + password + "')";
    bs.idu(insertUserQuery);
    System.out.println("Signup successful! You can now login.");
}

    public static void display() {
        try {
            String sql = "select * FROM bus_tb";
            ResultSet rs = bs.select(sql);
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

    public static void bookBus() {
        display();
        System.out.print("\nEnter the ID of the bus you want to book: ");
        int bid = scanner.nextInt();
        scanner.nextLine(); // Consume newline character
        System.out.print("Enter number of seats to book: ");
        int seatsToBook = scanner.nextInt();
        scanner.nextLine(); // Consume newline character
        // Check if the requested number of seats is available
        String checkAvailabilityQuery = "SELECT available_seats FROM bus_tb WHERE bid = " + bid;
        ResultSet availabilityResult = bs.select(checkAvailabilityQuery);
        try {
            if (availabilityResult.next()) {
                int availableSeats = availabilityResult.getInt("available_seats");
                if (seatsToBook <= availableSeats) {
                    // Proceed with booking
                    int updatedSeats = availableSeats - seatsToBook;
                    String updateQuery = "UPDATE bus_tb SET available_seats = " + updatedSeats + " WHERE bid = " + bid;
                    bs.idu(updateQuery);
                    System.out.println("Booking successful! Thank you for choosing our service.");
                } else {
                    System.out.println("Sorry, the requested number of seats is not available.");
                }
            } else {
                System.out.println("Invalid bus ID.");
            }
        } catch (SQLException e) {
            System.out.println("Error: " + e);
        }
    }
}