// Class representing a Car
class Car {
    private String make;
    private String model;
    private int year;

    // Constructor without parameters (default constructor)
    public Car() {
        make = "Unknown";
        model = "Unknown";
        year = 0;
    }

    // Parameterized constructor
    public Car(String make, String model, int year) {
        this.make = make;
        this.model = model;
        this.year = year;
    }

    // Method to display car details
    public void displayDetails() {
        System.out.println("Make: " + make);
        System.out.println("Model: " + model);
        System.out.println("Year: " + year);
    }
}

// Main class to test constructors
public class ConstructorExample {
    public static void main(String[] args) {
        // Creating car objects using constructors
        Car car1 = new Car(); // Using default constructor
        Car car2 = new Car("Toyota", "Corolla", 2022); // Using parameterized constructor
        
        // Displaying details of cars
        System.out.println("Details of Car 1:");
        car1.displayDetails();
        
        System.out.println("\nDetails of Car 2:");
        car2.displayDetails();
    }
}
