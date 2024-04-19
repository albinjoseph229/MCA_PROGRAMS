import java.sql.*;

public class JdbcDB {
    public static void main(String[] args) throws Exception {
        String url = "jdbc:mysql://localhost:3306/java_db";
        String uname = "root";
        String password = "";

        Class.forName("com.mysql.jdbc.Driver");

        Connection con = DriverManager.getConnection(url, uname, password);

        Statement stmt = con.createStatement();

        stmt.executeUpdate("insert into mytable values(1,'albin joseph')");

        ResultSet rs = stmt.executeQuery("select * from mytable");

        while (rs.next()) {
            int id = rs.getInt("id");
            String name = rs.getString("name");
            System.out.println("ID: " + id + ", Name: " + name);
        }
        rs.close();
        stmt.close();
        con.close();

    }
}