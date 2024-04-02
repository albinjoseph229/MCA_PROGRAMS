import java.net.*;

public class InetAddressExample {
    public static void main(String[] args) {
        try {
            // Get InetAddress object representing localhost
            InetAddress localhost = InetAddress.getLocalHost();
            System.out.println("Localhost IP Address: " + localhost.getHostAddress());
            System.out.println("Localhost Hostname: " + localhost.getHostName());

            // Get InetAddress object by IP address
            InetAddress address = InetAddress.getByName("8.8.8.8");
            System.out.println("Google DNS IP Address: " + address.getHostAddress());
            System.out.println("Google DNS Hostname: " + address.getHostName());

            // Get InetAddress object by hostname
            InetAddress google = InetAddress.getByName("www.google.com");
            System.out.println("Google IP Address: " + google.getHostAddress());
            System.out.println("Google Hostname: " + google.getHostName());

            // Check reachability
            System.out.println("Google is reachable: " + google.isReachable(1000));
        } catch (UnknownHostException e) {
            System.out.println("Unknown host: " + e.getMessage());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
