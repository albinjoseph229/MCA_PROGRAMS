//inteface method can invoke other methods present in the class

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
        draw();
        System.out.println("interface print");
    }

    public void draw() {
        System.out.println("draw not in interface");
    }
}
class Pgrm12{
    public static void main(String args[]) {
        i1 obj;
        obj = new c1();
        obj.disp();
        obj.print();
    }
}

