// EncapsulationDemo class demonstrating encapsulation
class EncapsulationDemo {
    // Private data members
    private String name;
    private int age;
    
    // Getter method for name
    public String getName() {
        return name;
    }
    
    // Setter method for name
    public void setName(String name) {
        // Perform validation if needed
        this.name = name;
    }
    
    // Getter method for age
    public int getAge() {
        return age;
    }
    
    // Setter method for age
    public void setAge(int age) {
        // Perform validation if needed
        if (age >= 0) {
            this.age = age;
        } else {
            System.out.println("Age cannot be negative.");
        }
    }
}

// Main class to test encapsulation
public class EncapsulationExample {
    public static void main(String[] args) {
        // Creating an object of EncapsulationDemo class
        EncapsulationDemo obj = new EncapsulationDemo();
        
        // Setting values using setter methods
        obj.setName("John");
        obj.setAge(30);
        
        // Accessing values using getter methods
        System.out.println("Name: " + obj.getName());
        System.out.println("Age: " + obj.getAge());
        
        // Trying to set negative age (which will not be allowed)
        obj.setAge(-5); // This will print "Age cannot be negative."
    }
}
