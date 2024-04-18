class A{
    int age;
    String name;
    public A(int age,String name){
        this.age=age;
        this.name=name;
    }
    public void disp(){
        System.out.println("Age:"+age+"\nName:"+name);
    }
}
class B extends A{
    String subject;
    public B(int age,String name,String subject){
        super(age,name);
        this.subject=subject;
    }
    public void disp(){
        super.disp();
        System.out.println("Subject:"+subject);
    }
}
public class InheritanceExmp {
    public static void main(String[] args) {
        A obj=new A(12,"tintu");
        B obj2=new B(45,"shibu","maths");
        obj.disp();
        obj2.disp();
    }
    
}
