// Abstract class representing a shape
abstract class Shape {
    // Abstract method to calculate area
    public abstract double calculateArea();
    
    // Non-abstract method
    public void display() {
        System.out.println("This is a shape.");
    }
}

// Concrete class Circle extending Shape
class Circle extends Shape {
    private double radius;
    
    // Constructor
    public Circle(double radius) {
        this.radius = radius;
    }
    
    // Implementation of abstract method to calculate area
    @Override
    public double calculateArea() {
        return Math.PI * radius * radius;
    }
}

// Concrete class Rectangle extending Shape
class Rectangle extends Shape {
    private double length;
    private double width;
    
    // Constructor
    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }
    
    // Implementation of abstract method to calculate area
    @Override
    public double calculateArea() {
        return length * width;
    }
}

// Main class to test abstraction
public class AbstractionExample {
    public static void main(String[] args) {
        // Creating instances of Circle and Rectangle
        Circle circle = new Circle(5);
        Rectangle rectangle = new Rectangle(4, 6);
        
        // Calling abstract method and non-abstract method
        System.out.println("Area of Circle: " + circle.calculateArea());
        circle.display();
        
        System.out.println("Area of Rectangle: " + rectangle.calculateArea());
        rectangle.display();
    }
}
