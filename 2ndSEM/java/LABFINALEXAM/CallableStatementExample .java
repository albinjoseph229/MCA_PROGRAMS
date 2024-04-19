import java.sql.CallableStatement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class CallableStatementExample {
    public static void main(String[] args) {
        // JDBC URL for Oracle database
        String jdbcUrl = "jdbc:oracle:thin:@localhost:1521:ORCL"; // Change this according to your database configuration
        String username = "your_username";
        String password = "your_password";

        Connection connection = null;
        CallableStatement callableStatement = null;

        try {
            // Load the Oracle JDBC driver
            Class.forName("oracle.jdbc.driver.OracleDriver");

            // Create a connection to the database
            connection = DriverManager.getConnection(jdbcUrl, username, password);

            // Prepare a CallableStatement to call the stored procedure
            callableStatement = connection.prepareCall("{call your_stored_procedure(?, ?, ?)}");

            // Set input parameters (if any)
            callableStatement.setString(1, "input_param1");
            callableStatement.setInt(2, 123);
            callableStatement.setString(3, "input_param2");

            // Execute the stored procedure
            callableStatement.execute();

            // You can process any output parameters or result sets here

            System.out.println("Stored procedure executed successfully.");
        } catch (ClassNotFoundException e) {
            System.out.println("Oracle JDBC Driver not found!");
            e.printStackTrace();
        } catch (SQLException e) {
            System.out.println("SQL Exception!");
            e.printStackTrace();
        } finally {
            try {
                // Close the resources
                if (callableStatement != null) {
                    callableStatement.close();
                }
                if (connection != null) {
                    connection.close();
                }
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}