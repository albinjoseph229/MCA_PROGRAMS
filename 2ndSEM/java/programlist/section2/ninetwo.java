class Employee {
    protected String name;

    public Employee(String name) {
        this.name = name;
    }

    public void calcSalary() {
        System.out.println("Salary of employee is 10000");
    }

    public void display() {
        System.out.println("Name of class is Employee.");
    }
}

class Engineer extends Employee {
    public Engineer(String name) {
        super(name);
    }

    public void calcSalary() {
        System.out.println("Salary of employee is 20000.");
    }
}

public class ninetwo {
    public static void main(String[] args) {
        Employee employee = new Engineer("John Doe");
        employee.calcSalary();
        employee.display();
    }
}