//Serialization HAS-A(Composition)

import java.io.*;

class Address implements Serializable {
    String city;
    String state;

    public Address(String city, String state) {
        this.city = city;
        this.state = state;
    }
}

class Employee implements Serializable {
    String name;
    int age;
    Address address; // Composition

    public Employee(String name, int age, Address address) {
        this.name = name;
        this.age = age;
        this.address = address;
    }
}

public class SerializationExample2 {
    public static void main(String[] args) {
        Address address = new Address("New York", "NY");
        Employee employee = new Employee("John", 30, address);

        try (FileOutputStream fos = new FileOutputStream("employee.ser");
             ObjectOutputStream oos = new ObjectOutputStream(fos)) {
            oos.writeObject(employee);
            System.out.println("Employee object serialized successfully.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
