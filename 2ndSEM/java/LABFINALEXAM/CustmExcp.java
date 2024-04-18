public class CustmExcp {
    public static void main(String[] args) {
        int age = 0;
        try {
            agedisp(age);
        } catch (AgeLessThanZeroException e) {
            System.out.println(e.getMessage());
        }
    }

    public static void agedisp(int age) throws AgeLessThanZeroException {
        if (age <= 0) {
            throw new AgeLessThanZeroException("Age cannot be less than or equal to zero!");
        }
        System.out.println("Age: " + age);
    }
}

class AgeLessThanZeroException extends Exception {
    public AgeLessThanZeroException(String message) {
        super(message);
    }
}
