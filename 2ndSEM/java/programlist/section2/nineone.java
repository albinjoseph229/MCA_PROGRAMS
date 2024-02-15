class Employee {
    String name;
    int age;
    String phoneNumber;
    String address;
    double salary;

    void printSalary() {
        System.out.println("Salary: " + salary);
    }
}

class Officer extends Employee {
    String specialization;
}

class Manager extends Employee {
    String department;
}

public class nineone {
    public static void main(String[] args) {
        Officer officer = new Officer();
        officer.name = "John Doe";
        officer.age = 30;
        officer.phoneNumber = "1234567890";
        officer.address = "123 Main Street";
        officer.salary = 5000.0;
        officer.specialization = "Finance";

        Manager manager = new Manager();
        manager.name = "Jane Smith";
        manager.age = 35;
        manager.phoneNumber = "9876543210";
        manager.address = "456 Elm Street";
        manager.salary = 8000.0;
        manager.department = "Sales";

        System.out.println("Officer Details:");
        System.out.println("Name: " + officer.name);
        System.out.println("Age: " + officer.age);
        System.out.println("Phone Number: " + officer.phoneNumber);
        System.out.println("Address: " + officer.address);
        officer.printSalary();
        System.out.println("Specialization: " + officer.specialization);

        System.out.println();

        System.out.println("Manager Details:");
        System.out.println("Name: " + manager.name);
        System.out.println("Age: " + manager.age);
        System.out.println("Phone Number: " + manager.phoneNumber);
        System.out.println("Address: " + manager.address);
        manager.printSalary();
        System.out.println("Department: " + manager.department);
    }
}