/* Program to implement run time polymorphism in Java using interface, wrt calculating area of a triangle */

import java.util.Scanner;

interface Shape {
    double calculateArea();
}

class Triangle implements Shape {
    double base;
    double height;

    public Triangle(double b, double h) {
        base = b;
        height = h;
    }

    @Override
    public double calculateArea() {
        return 0.5 * base * height;
    }
}

public class SixOne {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the base of the triangle: ");
        double b = scanner.nextDouble();
        System.out.print("Enter the height of the triangle: ");
        double h = scanner.nextDouble();
        Shape triangle = new Triangle(b, h);

        double area = triangle.calculateArea();
        System.out.println("Area of the triangle: " + area);

        scanner.close();
    }
}
