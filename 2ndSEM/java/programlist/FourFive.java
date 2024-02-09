//Create a class complex having a real and imaginary part. Provide functions for read, display, add and multiplying two complex numbers.

import java.io.*;

public class FourFive {
    public static void main(String[] args) {
        Complex a, b, c;
        System.out.println("FOR A ");
        a = new Complex();
        a.read();
        b = new Complex();
        System.out.println("FOR B ");
        b.read();

        a.disp();
        b.disp();
        c = a.add(b);
        System.out.println("Addition:");
        c.disp();
        System.out.println("Multiplication:");
        c.multi(a);
        b.disp();
    }
}

class Complex {
    int real, imag;

    public void read() {
        DataInputStream din = new DataInputStream(System.in);
        try {
            System.out.print("Enter real number: ");
            real = Integer.parseInt(din.readLine());
            System.out.print("Enter Imag number: ");
            imag = Integer.parseInt(din.readLine());
        } catch (Exception e) {
            System.out.println("Error " + e);
        }
    }

    public void disp() {
        System.out.println("complex no: " + real + " + " + imag + "i");
    }

    public Complex add(Complex a) {
        Complex t = new Complex();
        t.real = a.real + real;
        t.imag = a.imag + imag;
        return t;
    }

    public Complex multi(Complex a) {
        Complex t = new Complex();
        t.real = (a.real * real) - (a.imag * imag);
        t.imag = (a.real * real) + (a.imag * imag);
        return t;
    }
}