import java.io.*;
import java.net.*;

public class MyClient {
    public static void main(String[] args) {
        try {
            Socket s = new Socket("localhost", 1234);
            DataInputStream din = new DataInputStream(s.getInputStream());
            DataOutputStream dout = new DataOutputStream(s.getOutputStream());

            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

            String str = "", str2 = "";

            while (!str.equals("stop")) {
                str = reader.readLine();
                dout.writeUTF(str);
                dout.flush();
                str2 = (String) din.readUTF();
                System.out.println("Server says: " + str2);
            }

            dout.close();
            s.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
