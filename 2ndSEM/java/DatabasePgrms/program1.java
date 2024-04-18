import java.sql.*;

public class program1 {
    // JDBC URL, username, and password of MySQL server
    private static final String JDBC_URL = "jdbc:mysql://localhost:3306/java_db";
    private static final String USERNAME = "root";
    private static final String PASSWORD = "";

    public static void main(String[] args) {
        Connection connection = null;
        try {
            // Establishing a connection to MySQL database
            connection = DriverManager.getConnection(JDBC_URL, USERNAME, PASSWORD);
            System.out.println("Connected to the MySQL database!");

            // Creating a statement
            Statement statement = connection.createStatement();

            // Executing a simple SQL query to insert data
            Scanner sc=new Scanner(System.in);
            String insertQuery = "INSERT INTO mytable (id, name) VALUES (1, 'albin')";
            int rowsAffected = statement.executeUpdate(insertQuery);
            if (rowsAffected > 0) {
                System.out.println("Data inserted successfully!");
            } else {
                System.out.println("No rows affected.");
            }

            // Executing a SELECT query to retrieve data
            String selectQuery = "SELECT * FROM mytable";
            ResultSet resultSet = statement.executeQuery(selectQuery);

            // Iterating over the result set and printing the records
            while (resultSet.next()) {
                int id = resultSet.getInt("id");
                String name = resultSet.getString("name");
                System.out.println("ID: " + id + ", Name: " + name);
            }

            // Closing the result set, statement, and connection
            resultSet.close();
            statement.close();
            connection.close();
        } catch (SQLException e) {
            System.out.println(e);
        }
    }
}
