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
        return Math.PI *r*r;
    }
    public double perimeter(){
        return 2*Math.PI*r;
    }
}
class Pgrm9
{
    public static void main(String args[]){
        IShape obj[];
        int n,i,ch;
        DataInputStream din= new DataInputStream(System.in);
        try{
            System.out.println("Enter the number of objects");
            n=Integer.parseInt(din.readLine());
            obj=new IShape[n];
            for(i=0;i<n;i++){
                System.out.println("1-Recatngle\n2-Circle");
                ch=Integer.parseInt(din.readLine());
                if(ch==1){
                    double l,b;
                    System.out.println("Enter the l And b");
                    l=Double.parseDouble(din.readLine());
                    b=Double.parseDouble(din.readLine());
                    obj[i]=new Rectangle(l,b);
                }
                else{
                    double r;
                    System.out.println("Enter the r");
                    r=Double.parseDouble(din.readLine());
                    obj[i]=new Circle(r);
                }
            }
            for(i=0;i<n;i++){
                System.out.println(obj[i].area());
                System.out.println(obj[i].perimeter());
            }
        }
        catch(Exception e)
        {
            System.out.println("Error"+e);
        }
    }
}