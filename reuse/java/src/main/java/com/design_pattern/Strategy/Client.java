public class Client {
    public static void main(String[] args) {
        MovieTicket mt = new MovieTicket();
        double originalPrice = 100.0;
        mt.setPrice(originalPrice);
        double currentPrice;
        
        mt.setDiscount(new ChildrenDiscount());
        currentPrice = mt.getPrice();
        System.out.println("originalPrice: " + originalPrice);
        System.out.println("---------------------------------");
        System.out.println("currentPrice: " + currentPrice + "\n\n");

        mt.setDiscount(new StudentDiscount());
        currentPrice = mt.getPrice();
        System.out.println("originalPrice: " + originalPrice);
        System.out.println("---------------------------------");
        System.out.println("currentPrice: " + currentPrice + "\n\n");

        mt.setDiscount(new VIPDiscount());
        currentPrice = mt.getPrice();
        System.out.println("originalPrice: " + originalPrice);
        System.out.println("---------------------------------");
        System.out.println("currentPrice: " + currentPrice + "\n\n");
    }
}
