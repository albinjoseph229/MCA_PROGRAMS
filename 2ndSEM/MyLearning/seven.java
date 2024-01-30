//call by reference example
class seven{
    int number=10;
    
    // pass object as parameter
    public static void increment(seven pb){
        pb.number = pb.number+1;  // increment variable by 1
        System.out.println("value in method: "+pb.number);
    }
    
    public static void main(String[] args) {
     seven pb=new seven(); // pb is an object of class seven
        
        System.out.println("value before method call: "+pb.number);
        increment(pb); // pass object of the class seven
        System.out.println("value after method call: "+pb.number);
    }
}