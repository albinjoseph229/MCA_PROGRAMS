//method overriding
class a{
    public void display(){
        System.out.println("i have a car");
    }
}
class b extends a{
    public void display(){
        System.out.println("i have a bike");
    }
}

public class one {
    public static void main(String[] args){
        a p=new a();
        b q=new b();
        p.display();
        q.display();


    }
    
}