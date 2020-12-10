public class VIPDiscount implements Discount {
    public double calculate(double price) {
        System.out.println("VIPDiscount: ");
        return price * 0.8;
    }
}
