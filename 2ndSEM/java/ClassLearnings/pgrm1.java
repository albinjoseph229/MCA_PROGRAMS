
//program for adding two numbers using object oriented concepts
import java.io.*;

class Num {
    int a;
    public void read() {
        DataInputStream din = new DataInputStream(System.in);
        try {
            System.out.println("Enter the value");
            a = Integer.parseInt(din.readLine());
        } catch (Exception e) {
            System.out.println(e);
        }
    }
    public void disp() {
        System.out.println("The value is " + a);
    }
    public Num add(Num q) {
        Num temp = new Num();
        temp.a = a + q.a;
        return temp;
    }

}

class Pgrm1 {
    public static void main(String args[]) {
        Num p, q, r;
        p = new Num();
        q = new Num();
        p.read();
        q.read();
        r = p.add(q);
        p.disp();
        q.disp();
        r.disp();
    }
}