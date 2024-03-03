import java.io.*;

public class Student implements Serializable {

    private int id;
    private String name;

    public Student(int id, String name) {

        this.id = id;
        this.name = name;

    }

    public void disp() {
        System.out.println(id + " " + name);
    }
}