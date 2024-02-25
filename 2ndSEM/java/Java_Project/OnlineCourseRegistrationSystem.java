import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class OnlineCourseRegistrationSystem {

    private static final String DB_URL = "jdbc:mysql://localhost:3306/onlinecourse";
    private static final String DB_USER = "root";
    private static final String DB_PASSWORD = "";

    public static void main(String[] args) {
        // Establish database connection
        try (Connection conn = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD)) {
            // Create tables if they don't exist
            initializeDatabase(conn);
            
            Scanner scanner = new Scanner(System.in);
            
            // Dummy data for demonstration
            initializeDummyData(conn);
            
            String currentUser = null;
            while (true) {
                if (currentUser == null) {
                    System.out.println("1. Register\n2. Login\n3. Exit");
                    System.out.print("Choose an option: ");
                    int choice = scanner.nextInt();
                    scanner.nextLine(); // Consume newline
                    
                    switch (choice) {
                        case 1:
                            registerUser(conn, scanner);
                            break;
                        case 2:
                            currentUser = login(conn, scanner);
                            break;
                        case 3:
                            System.out.println("Exiting...");
                            System.exit(0);
                            break;
                        default:
                            System.out.println("Invalid option!");
                    }
                } else {
                    System.out.println("Welcome, " + currentUser + "!");
                    System.out.println("1. View Courses\n2. Logout");
                    System.out.print("Choose an option: ");
                    int choice = scanner.nextInt();
                    scanner.nextLine(); // Consume newline
                    
                    switch (choice) {
                        case 1:
                            displayCourses(conn);
                            break;
                        case 2:
                            displayEnrollments(conn, currentUser);
                            currentUser = null; // Logout
                            break;
                        default:
                            System.out.println("Invalid option!");
                    }
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    // Method to create database tables if they don't exist
    private static void initializeDatabase(Connection conn) throws SQLException {
        try (Statement stmt = conn.createStatement()) {
            String createUserTableSQL = "CREATE TABLE IF NOT EXISTS users ("
                    + "username VARCHAR(255) PRIMARY KEY,"
                    + "password VARCHAR(255)"
                    + ")";
            stmt.executeUpdate(createUserTableSQL);

            String createCoursesTableSQL = "CREATE TABLE IF NOT EXISTS courses ("
                    + "id INT AUTO_INCREMENT PRIMARY KEY,"
                    + "name VARCHAR(255),"
                    + "level VARCHAR(100),"
                    + "instructor VARCHAR(255),"
                    + "enrollment_limit INT,"
                    + "fee VARCHAR(20),"
                    + "duration VARCHAR(20)"
                    + ")";
            stmt.executeUpdate(createCoursesTableSQL);

            String createEnrollmentsTableSQL = "CREATE TABLE IF NOT EXISTS enrollments ("
                    + "username VARCHAR(255),"
                    + "course_id INT,"
                    + "PRIMARY KEY (username, course_id),"
                    + "FOREIGN KEY (username) REFERENCES users(username),"
                    + "FOREIGN KEY (course_id) REFERENCES courses(id)"
                    + ")";
            stmt.executeUpdate(createEnrollmentsTableSQL);
        }
    }

    // Method to register a new user
    private static void registerUser(Connection conn, Scanner scanner) throws SQLException {
        System.out.print("Enter username: ");
        String username = scanner.nextLine();
        System.out.print("Enter password: ");
        String password = scanner.nextLine();

        // Check if the username already exists
        if (userExists(conn, username)) {
            System.out.println("Username already exists. Please choose another username.");
            return;
        }

        // Store user information (with password hashing for security)
        String hashedPassword = hashPassword(password);
        String insertUserSQL = "INSERT INTO users (username, password) VALUES (?, ?)";
        try (PreparedStatement pstmt = conn.prepareStatement(insertUserSQL)) {
            pstmt.setString(1, username);
            pstmt.setString(2, hashedPassword);
            pstmt.executeUpdate();
        }
        System.out.println("Registration successful!");
    }

    // Method to check if a user already exists
    private static boolean userExists(Connection conn, String username) throws SQLException {
        String query = "SELECT * FROM users WHERE username = ?";
        try (PreparedStatement pstmt = conn.prepareStatement(query)) {
            pstmt.setString(1, username);
            try (ResultSet rs = pstmt.executeQuery()) {
                return rs.next();
            }
        }
    }

    // Method to login an existing user
    private static String login(Connection conn, Scanner scanner) throws SQLException {
        System.out.print("Enter username: ");
        String username = scanner.nextLine();
        System.out.print("Enter password: ");
        String password = scanner.nextLine();

        // Verify user credentials
        String query = "SELECT password FROM users WHERE username = ?";
        try (PreparedStatement pstmt = conn.prepareStatement(query)) {
            pstmt.setString(1, username);
            try (ResultSet rs = pstmt.executeQuery()) {
                if (rs.next()) {
                    String hashedPasswordFromDB = rs.getString("password");
                    if (hashedPasswordFromDB.equals(hashPassword(password))) {
                        System.out.println("Login successful!");
                        return username;
                    }
                }
            }
        }
        System.out.println("Invalid username or password!");
        return null;
    }

    // Method to display available courses and enroll in a course
    private static void displayCourses(Connection conn) throws SQLException {
        System.out.println("Available Courses:");
        String query = "SELECT * FROM courses";
        try (Statement stmt = conn.createStatement(); ResultSet rs = stmt.executeQuery(query)) {
            int index = 1;
            while (rs.next()) {
                System.out.println(index + ". " + rs.getString("name") + " (Fee: " + rs.getString("fee") + ", Duration: " + rs.getString("duration") + ")");
                index++;
            }
        }
    }

    // Method to display enrolled courses for the current user
    private static void displayEnrollments(Connection conn, String username) throws SQLException {
        String query = "SELECT courses.name FROM courses "
                     + "INNER JOIN enrollments ON courses.id = enrollments.course_id "
                     + "WHERE enrollments.username = ?";
        try (PreparedStatement pstmt = conn.prepareStatement(query)) {
            pstmt.setString(1, username);
            try (ResultSet rs = pstmt.executeQuery()) {
                if (rs.next()) {
                    System.out.println("Enrolled Courses for " + username + ":");
                    do {
                        System.out.println(rs.getString("name"));
                    } while (rs.next());
                    return;
                }
            }
        }
        System.out.println("No courses enrolled for " + username);
    }

    // Method to hash the password for secure authentication (not secure, for demonstration purposes only)
    private static String hashPassword(String password) {
        // Actual password hashing implementation should be used here
        return password;
    }

    // Method to initialize dummy data (courses) for demonstration
    private static void initializeDummyData(Connection conn) throws SQLException {
        String insertCourseSQL = "INSERT INTO courses (name, level, instructor, enrollment_limit, fee, duration) VALUES (?, ?, ?, ?, ?, ?)";
        try (PreparedStatement pstmt = conn.prepareStatement(insertCourseSQL)) {
            pstmt.setString(1, "Java Programming");
            pstmt.setString(2, "Beginner");
            pstmt.setString(3, "John Doe");
            pstmt.setInt(4, 20);
            pstmt.setString(5, "$100");
            pstmt.setString(6, "3 months");
            pstmt.executeUpdate();

            pstmt.setString(1, "Web Development");
            pstmt.setString(2, "Intermediate");
            pstmt.setString(3, "Jane Smith");
            pstmt.setInt(4, 15);
            pstmt.setString(5, "$150");
            pstmt.setString(6, "4 months");
            pstmt.executeUpdate();

            pstmt.setString(1, "Data Science");
            pstmt.setString(2, "Advanced");
            pstmt.setString(3, "Alice Johnson");
            pstmt.setInt(4, 10);
            pstmt.setString(5, "$200");
            pstmt.setString(6, "6 months");
            pstmt.executeUpdate();
        }
    }
}
