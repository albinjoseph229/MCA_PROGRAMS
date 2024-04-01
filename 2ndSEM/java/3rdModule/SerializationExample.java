import java.io.*;

class Employee implements Serializable {
    private static final long serialVersionUID = 1L;

    private String name;
    private transient String password; // Marked as transient
    private int age;

    public Employee(String name, String password, int age) {
        this.name = name;
        this.password = password;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public String getPassword() {
        return password;
    }

    public int getAge() {
        return age;
    }
}

public class SerializationExample {
    public static void main(String[] args) {
        Employee employee = new Employee("John", "secretpassword", 30);

        // Serialize the Employee object
        try (FileOutputStream fos = new FileOutputStream("employee.ser");
             ObjectOutputStream oos = new ObjectOutputStream(fos)) {
            oos.writeObject(employee);
            System.out.println("Employee object serialized successfully.");
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Deserialize the Employee object
        try (FileInputStream fis = new FileInputStream("employee.ser");
             ObjectInputStream ois = new ObjectInputStream(fis)) {
            Employee deserializedEmployee = (Employee) ois.readObject();
            System.out.println("Employee object deserialized successfully.");
            System.out.println("Name: " + deserializedEmployee.getName());
            // The password field will be null because it's marked as transient
            System.out.println("Password: " + deserializedEmployee.getPassword());
            System.out.println("Age: " + deserializedEmployee.getAge());
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
