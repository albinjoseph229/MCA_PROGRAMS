class Rectangle {
    private double length;
    private double width;

    public Rectangle() {
        length = 0.0;
        width = 0.0;
    }

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    public double getLength() {
        return length;
    }

    public double getWidth() {
        return width;
    }

    public double calculatePerimeter() {
        return 2 * (length + width);
    }

    public double calculateArea() {
        return length * width;
    }

    public int sameArea(Rectangle other) {
        double thisArea = calculateArea();
        double otherArea = other.calculateArea();

        if (thisArea == otherArea) {
            return 1;
        } else {
            return 0;
        }
    }
}

public class Eightone {
    public static void main(String[] args) {
        Rectangle rectangle1 = new Rectangle(5.0, 3.0);
        Rectangle rectangle2 = new Rectangle(4.0, 4.0);

        System.out.println("Rectangle 1 - Length: " + rectangle1.getLength() + ", Width: " + rectangle1.getWidth());
        System.out.println("Perimeter of Rectangle 1: " + rectangle1.calculatePerimeter());
        System.out.println("Area of Rectangle 1: " + rectangle1.calculateArea());

        System.out.println();

        System.out.println("Rectangle 2 - Length: " + rectangle2.getLength() + ", Width: " + rectangle2.getWidth());
        System.out.println("Perimeter of Rectangle 2: " + rectangle2.calculatePerimeter());
        System.out.println("Area of Rectangle 2: " + rectangle2.calculateArea());

        System.out.println();

        if (rectangle1.sameArea(rectangle2) == 1) {
            System.out.println("Rectangle 1 and Rectangle 2 have the same area.");
        } else {
            System.out.println("Rectangle 1 and Rectangle 2 do not have the same area.");
        }
    }
}