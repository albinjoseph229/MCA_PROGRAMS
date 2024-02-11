/*Create an interface Shape having two prototypes disp() and calc(),
 to diplay the shape and calculate volume respectively. Create two classes
circle and rectangle which implements the above interface. In the 
main function create a reference of Shape depending on the user-choice. */

import java.util.Scanner;

interface Shape {
    void disp();

    double calc();
}

class Circle implements Shape {
    double radius;

    public Circle() {
        this(10);
    }

    public Circle(double r) {
        radius = r;
    }

    @Override
    public void disp() {
        // System.out.println("This is a circle");
        // System.out.println(" *** ");
        // System.out.println(" * * ");
        // System.out.println("* O *");
        // System.out.println(" * * ");
        // System.out.println(" *** ");
    }

    @Override
    public double calc() {
        return 3.14 * radius * radius;
    }
}

class Rectangle implements Shape {
    double length, breadth;

    public Rectangle() {
        this(10, 5);
    }

    public Rectangle(double l, double b) {
        length = l;
        breadth = b;
    }

    @Override
    public void disp() {
        // System.out.println("This is a rectangle");
        // for (int i = 0; i < breadth; i++) {
        // for (int j = 0; j < length; j++) {
        // System.out.print("* ");
        // }
        System.out.println();
    }

    @Override
    public double calc() {
        return length * breadth;
    }
}

public class SixTwo {
    public static void main(String[] args) {
        System.out.println("Choose the shape: ");
        System.out.println("1. Rectangle\t2. Circle");
        Scanner scanner = new Scanner(System.in);
        int ch = scanner.nextInt();

        Shape shape;
        switch (ch) {
            case 1:
                System.out.print("Enter Length: ");
                double l = scanner.nextDouble();
                System.out.print("Enter Breadth: ");
                double b = scanner.nextDouble();
                shape = new Rectangle(l, b);
                break;
            case 2:
                System.out.print("Enter Radius: ");
                double r = scanner.nextDouble();
                shape = new Circle(r);
                break;
            default:
                System.out.println("Wrong choice");
                scanner.close();
                return;
        }

        shape.disp();
        double area = shape.calc();
        System.out.println("Area: " + area);

        scanner.close();
    }
}
