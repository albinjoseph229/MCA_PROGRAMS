import java.sql.*;

public class Main {
    public static void main(String[] args) {
        try {
            // Load the MySQL JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");
            
            // Connect to the MySQL database
            String url = "jdbc:mysql://localhost:3306/passwords_db";
            String username = "your_username";
            String password = "";
            Connection connection = DriverManager.getConnection(url, username, password);
            
            // Perform database operations...
            
            // Close the connection
            connection.close();
        } catch (ClassNotFoundException e) {
            System.out.println("MySQL JDBC driver not found.");
            e.printStackTrace();
        } catch (SQLException e) {
            System.out.println("Failed to connect to the database.");
            e.printStackTrace();
        }
    }
}
