//WAP (menu driven) to demonstrate method overriding in java, by displaying details of a student, and a teacher.
import java.io.*;

class person {

    String name;
    int age;

    public void read() {
        DataInputStream din = new DataInputStream(System.in);
        try {
            System.out.print("Enter name: ");
            name = din.readLine();
            System.out.print("Enter age: ");
            age = Integer.parseInt(din.readLine());
        } catch (Exception e) {
            System.out.println("Error " + e);
        }
    }

    public void disp() {
        System.out.println("Name: " + name + " age: " + age);
    }
}

class teacher extends person {
    int tid;
    String sub;

    public void read() {
        DataInputStream din = new DataInputStream(System.in);
        try {
            System.out.print("Enter Teachers Id: ");
            tid = Integer.parseInt(din.readLine());
            System.out.print("Enter Subject: ");
            sub = din.readLine();

        } catch (Exception e) {
            System.out.println("Error " + e);
        }
    }

    public void disp() {
        System.out.println("TeacherId: " + tid + " Subject: " + sub);
    }
}

class student extends person {
    int sid;
    String course;

    public void read() {
        super.read();
        DataInputStream din = new DataInputStream(System.in);
        try {
            System.out.print("Enter Students Id: ");
            sid = Integer.parseInt(din.readLine());
            System.out.print("Enter Course enrolled: ");
            course = din.readLine();

        } catch (Exception e) {
            System.out.println("Error " + e);
        }
    }

    public void disp() {
        super.disp();
        System.out.println("StudentId: " + sid + " Course: " + course);
    }
}

public class FiveOne {
    public static void main(String[] args) {
        student s = new student();
        teacher t = new teacher();
        for (int ch = menu(); ch != 5; ch = menu()) {
            switch (ch) {
                case 1:
                    s.read();
                    break;
                case 2:
                    t.read();
                    break;
                case 3:
                    s.disp();
                    break;
                case 4:
                    t.disp();
                    break;
                default:
                    System.out.println("Wrong choice");
                    break;
            }
        }
    }

    private static int menu() {
        int ch = 0;
        System.out.println("*****************************");
        System.out.println("1.Enter Students Details\t2.Enter Teachers Details");
        System.out.println("3.View Students Details\t\t4.View Teachers Details\n5.Exit");
        DataInputStream din = new DataInputStream(System.in);
        System.out.print("Enter Your Choice: ");
        try {
            ch = Integer.parseInt(din.readLine());
        } catch (Exception e) {
            System.out.println("Error " + e);
        }
        return ch;
    }
}