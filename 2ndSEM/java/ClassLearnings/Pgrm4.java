//constructor
import java.io.*;
class Person{
    int age;
    String name;
    public Person(){    //constructor
        age=0;
        name=" ";
    }
    public Person(int a, String n)
    {
        age=a;
        name=n;
    }
    public void disp()
    {
        System.out.println("Name: "+name+"Age: "+age);
    }
}
class Pgrm2{
    public static void main(String[] args) {
        Person p,q;
        p=new Person();
        q=new Person(25,"ssss");
        p.disp();
        q.disp();
    }
}
