//interface program
import java.io.*;
interface i1 {
    public void print();
    public void disp();
}
class c1 implements i1 {
    public void disp() {
        System.out.println("interface disp");
    }

    public void print() {
        System.out.println("interface print");
    }

    public void draw() {
        System.out.println("draw not in interface");
    }
}
class Pgrm2 {
    public static void main(String args[]) {
        c1 obj = new c1();
        obj.disp();
        obj.print();
        obj.draw();
    }
}