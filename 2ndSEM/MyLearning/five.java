//this keyword
class MyClass {
    private int number;

    public MyClass(int number) {
        this.number = number;
    }

    public void printNumber() {
        System.out.println("Number: " + this.number);
    }
}

public class five {
    public static void main(String[] args) {
        MyClass obj = new MyClass(10);
        obj.printNumber();
    }
}
