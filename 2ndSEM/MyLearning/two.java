//method overloading
class a{
    void run(){
        System.out.println("iam running");
    }
    void run(int a){                //method overloading is happening here same method names with different parameters
        System.out.println("iam running "+a+" times");
    }
}
public class two{
    public static void main(String[] args){
        a obj=new a();
        obj.run();
        obj.run(5);
    }
}