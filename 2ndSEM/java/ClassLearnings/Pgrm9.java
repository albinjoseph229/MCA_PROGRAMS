//polymorphism
import java.io.*;

interface IShape{
    public double area();
    public double perimeter();
}
class Rectangle implements IShape{
    double l,b;
    public Rectangle(double l, double b){
        this.l=l;
        this.b=b;
    }
    public double area(){
        return l*b;
    }
    public double perimeter()
    {
        return 2*(l+b);
    }
}
class Circle implements IShape{
    double r;
    public Circle(double r){
        this.r=r;
    }
    public double area()
    {
        return (22/7)*r*r;
    }
    public double perimeter(){
        return 2*(22/7)*r;
    }
}
class Pgrm9
{
    public static void main(String args[]){
        ishape obj[];
        int n,i,ch;
        DataInputStream din= new DataInputStream(System.in);
    }
}