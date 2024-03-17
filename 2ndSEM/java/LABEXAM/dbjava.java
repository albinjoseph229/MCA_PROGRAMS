import java.io.*;
import java.sql.*;

public class dbjava {
    public static void main(String args[]) throws Exception {
        String url = "jdbc:mysql://localhost:3306/dbjava";
        String uname = "root";
        String pasword = "";
        String query = "select * from students";

        Class.forName("com.mysql.jdbc.Driver");
        Connection con = DriverManager.getConnection(url, uname, pasword);

        System.out.println("Connection Established");
        Statement st = con.createStatement();
        ResultSet rs = st.executeQuery(query);
        
        // Iterate over the ResultSet to print all data
        while (rs.next()) {
            String name = rs.getString("name");
            String id = rs.getString("id");
            System.out.println(name + " " + id);
        }

        st.close(); // close statement
        con.close(); // close connection
        System.out.println("Connection Closed....");
    }
}
 