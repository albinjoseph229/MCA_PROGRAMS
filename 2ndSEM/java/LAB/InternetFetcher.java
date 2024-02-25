import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class InternetFetcher {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java InternetFetcher <URL>");
            return;
        }

        String urlString = args[0];

        try {
            URL url = new URL(urlString);
            HttpURLConnection conn = (HttpURLConnection) url.openConnection();
            conn.setRequestMethod("GET");

            int responseCode = conn.getResponseCode();
            if (responseCode == HttpURLConnection.HTTP_OK) {
                BufferedReader in = new BufferedReader(new InputStreamReader(conn.getInputStream()));
                String inputLine;
                StringBuffer response = new StringBuffer();

                while ((inputLine = in.readLine()) != null) {
                    response.append(inputLine);
                }
                in.close();

                System.out.println("Response from " + urlString + ":");
                System.out.println(response.toString());
            } else {
                System.out.println("Failed to fetch data from " + urlString + ". Response code: " + responseCode);
            }
        } catch (IOException e) {
            System.out.println("Error fetching data from " + urlString + ": " + e.getMessage());
        }
    }
}
