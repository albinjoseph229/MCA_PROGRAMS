import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class PreparedStatementExample {
    public static void main(String[] args) {
        // JDBC URL for Oracle database
        String jdbcUrl = "jdbc:oracle:thin:@localhost:1521:ORCL"; // Change this according to your database configuration
        String username = "your_username";
        String password = "your_password";

        Connection connection = null;
        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;

        try {
            // Load the Oracle JDBC driver
            Class.forName("oracle.jdbc.driver.OracleDriver");

            // Create a connection to the database
            connection = DriverManager.getConnection(jdbcUrl, username, password);

            // Prepare a SQL statement with a parameter
            String sql = "SELECT * FROM employees WHERE department = ?";
            preparedStatement = connection.prepareStatement(sql);

            // Set parameter values
            String department = "IT";
            preparedStatement.setString(1, department);

            // Execute the query
            resultSet = preparedStatement.executeQuery();

            // Process the result set
            while (resultSet.next()) {
                String empId = resultSet.getString("emp_id");
                String empName = resultSet.getString("emp_name");
                // Process other columns as needed
                System.out.println("Employee ID: " + empId + ", Employee Name: " + empName);
            }
        } catch (ClassNotFoundException e) {
            System.out.println("Oracle JDBC Driver not found!");
            e.printStackTrace();
        } catch (SQLException e) {
            System.out.println("SQL Exception!");
            e.printStackTrace();
        } finally {
            try {
                // Close the resources
                if (resultSet != null) {
                    resultSet.close();
                }
                if (preparedStatement != null) {
                    preparedStatement.close();
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