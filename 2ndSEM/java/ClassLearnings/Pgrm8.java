//interface clled ishape having two prototypes draww and move

import java.io.*;
interface IShape{
    public void draw();
    public void move();
}
class Line implements IShape{
    public void draw(){
        System.out.println("Draw1 inside interface");
    }
    public void move()
    {
        System.out.println("Move1 inside interface");
    }
}
class Circle implements IShape{
    public void draw(){
        System.out.println("Draw2 inside interface");
    }
    public void move(){
        System.out.println("Move2 inside inerface");
    }
}
class Pgrm8{
    public static void main(String[] args) {
        IShape obj;
        obj=new Line();
        obj.draw();
        obj.move();
        obj=new Circle();
        obj.draw();
        obj.move();
    }
}