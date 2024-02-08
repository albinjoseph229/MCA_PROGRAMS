//WAP to calculate area of a circle (functions with no argument and no return type.)

import java.util.Scanner;

public class ThreeFive {
    public static void main(String[] args) {
        // Call the function to calculate the area of the circle
        CircleArea.calculateArea();
    }

    public class CircleArea {
        // Function to calculate the area of a circle
        public static void calculateArea() {
            Scanner scanner = new Scanner(System.in);

            // Input the radius of the circle
            System.out.print("Enter the radius of the circle: ");
            double radius = scanner.nextDouble();

            // Calculate the area of the circle
            double area = Math.PI * radius * radius;

            // Print the area of the circle
            System.out.println("Area of the circle: " + area);

            // Close the scanner
            scanner.close();
        }
    }
}