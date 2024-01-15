//Multiple interfaces
import java.io.*;
interface I1{
    void disp();
}
interface I2{
    void print();
}
class C1 implements I1,I2
{
    public void disp(){
        System.out.println("in disp I1");
    }
    public void print(){
        System.out.println("in print I2");
    }
}
class Pgrm10{
    public static void main(String args[]){
        C1 obj=new C1();
        obj.disp();
        obj.print();
    }
}