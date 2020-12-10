
public class ChildrenDiscount implements Discount {
    public double calculate(double price) {
        System.out.println("ChildrenDiscount: ");
        return price - 10;
    }
}
