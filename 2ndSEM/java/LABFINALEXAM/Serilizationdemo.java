import java.io.*;

class person implements Serializable
{
    String name;
    transient int age;

    public person(String n,int a)
    {
        this.name=n;
        this.age=a;
    }
}

public class Serilizationdemo
{
    public static void main(String args[]) throws Exception
    {
        person p=new person("Albin",21);

        ObjectOutputStream out=new ObjectOutputStream(new FileOutputStream("person.ser"));
        out.writeObject(p);
        out.close();


        ObjectInputStream in=new ObjectInputStream(new FileInputStream("person.ser"));
        person dp=(person)in.readObject();
        in.close();

        System.out.println("Name: "+dp.name+"age: "+dp.age);
        
    }
}