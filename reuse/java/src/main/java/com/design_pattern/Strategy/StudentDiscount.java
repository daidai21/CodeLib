public class StudentDiscount implements Discount {
    public double calculate(double price) {
        System.out.println("StudentDiscount: ");
        return price * 0.5;
    }
}
