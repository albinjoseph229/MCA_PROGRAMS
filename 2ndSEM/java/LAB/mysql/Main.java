import java.sql.*;
import java.util.Scanner;

public class Main {
    // Database connection details
    private static final String URL = "jdbc:mysql://localhost:3306/investment_portfolio";
    private static final String USERNAME = "root";
    private static final String PASSWORD = "";

    // Database connection method
    private static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(URL, USERNAME, PASSWORD);
    }

    // InvestmentManager class
    static class InvestmentManager {
        private Connection connection;

        public InvestmentManager() {
            try {
                connection = getConnection();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

        public void addInvestment(String name, String type, double buyPrice, int quantity, String date) throws SQLException {
            String query = "INSERT INTO investments (name, type, buy_price, quantity, date_added) VALUES (?, ?, ?, ?, ?)";
            PreparedStatement preparedStatement = connection.prepareStatement(query);
            preparedStatement.setString(1, name);
            preparedStatement.setString(2, type);
            preparedStatement.setDouble(3, buyPrice);
            preparedStatement.setInt(4, quantity);
            preparedStatement.setString(5, date);
            preparedStatement.executeUpdate();
            System.out.println("Investment added successfully.");
        }

        public void sellInvestment(String name, double sellPrice, int quantitySold) throws SQLException {
            String query = "SELECT * FROM investments WHERE name = ?";
            PreparedStatement preparedStatement = connection.prepareStatement(query);
            preparedStatement.setString(1, name);
            ResultSet resultSet = preparedStatement.executeQuery();

            if (resultSet.next()) {
                int quantityAvailable = resultSet.getInt("quantity");
                if (quantityAvailable >= quantitySold) {
                    double buyPrice = resultSet.getDouble("buy_price");
                    double profitLoss = (sellPrice - buyPrice) * quantitySold;
                    String updateQuery = "UPDATE investments SET quantity = ?, profit_loss = ? WHERE name = ?";
                    PreparedStatement updateStatement = connection.prepareStatement(updateQuery);
                    updateStatement.setInt(1, quantityAvailable - quantitySold);
                    updateStatement.setDouble(2, profitLoss);
                    updateStatement.setString(3, name);
                    updateStatement.executeUpdate();
                    System.out.println("Investment sold successfully. Profit/Loss: " + profitLoss);
                } else {
                    System.out.println("Not enough quantity available to sell.");
                }
            } else {
                System.out.println("Investment not found.");
            }
        }

        public void showInvestmentDetails() throws SQLException {
            String query = "SELECT * FROM investments";
            PreparedStatement preparedStatement = connection.prepareStatement(query);
            ResultSet resultSet = preparedStatement.executeQuery();

            double totalInvested = 0;
            double totalProfitLoss = 0;

            System.out.println("Investment Details:");
            while (resultSet.next()) {
                String name = resultSet.getString("name");
                String type = resultSet.getString("type");
                double buyPrice = resultSet.getDouble("buy_price");
                int quantity = resultSet.getInt("quantity");
                double profitLoss = resultSet.getDouble("profit_loss");

                totalInvested += buyPrice * quantity;
                totalProfitLoss += profitLoss;

                System.out.println("Name: " + name + ", Type: " + type + ", Buy Price: " + buyPrice +
                        ", Quantity: " + quantity + ", Profit/Loss: " + profitLoss);
            }
            System.out.println("Total Invested: " + totalInvested);
            System.out.println("Total Profit/Loss: " + totalProfitLoss);
        }
    }

    // Main method
    public static void main(String[] args) {
        InvestmentManager manager = new InvestmentManager();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("1. Add Investment");
            System.out.println("2. Sell Investment");
            System.out.println("3. Show Investment Details");
            System.out.println("4. Exit");
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    System.out.print("Enter investment name: ");
                    String name = scanner.nextLine();
                    System.out.print("Enter investment type: ");
                    String type = scanner.nextLine();
                    System.out.print("Enter buy price: ");
                    double buyPrice = scanner.nextDouble();
                    System.out.print("Enter quantity: ");
                    int quantity = scanner.nextInt();
                    System.out.print("Enter date (YYYY-MM-DD): ");
                    String date = scanner.next();
                    try {
                        manager.addInvestment(name, type, buyPrice, quantity, date);
                    } catch (SQLException e) {
                        e.printStackTrace();
                    }
                    break;
                case 2:
                    System.out.print("Enter investment name to sell: ");
                    String sellName = scanner.next();
                    System.out.print("Enter sell price: ");
                    double sellPrice = scanner.nextDouble();
                    System.out.print("Enter quantity to sell: ");
                    int sellQuantity = scanner.nextInt();
                    try {
                        manager.sellInvestment(sellName, sellPrice, sellQuantity);
                    } catch (SQLException e) {
                        e.printStackTrace();
                    }
                    break;
                case 3:
                    try {
                        manager.showInvestmentDetails();
                    } catch (SQLException e) {
                        e.printStackTrace();
                    }
                    break;
                case 4:
                    System.out.println("Exiting...");
                    System.exit(0);
                default:
                    System.out.println("Invalid choice");
            }
        }
    }
}
