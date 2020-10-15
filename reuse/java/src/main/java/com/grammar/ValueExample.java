public class ValueExample {
    public static void main(String[] args) {
        double v0 = 1e-9;
        System.out.printf("%.9f\n", v0);
        System.out.printf("%.8f\n", v0);

        double v1 = 1e9;
        System.out.printf("%.0f\n", v1);
        System.out.printf("%.1f\n", v1);

        double v2 = -1e9;
        System.out.printf("%.0f\n", v2);
        System.out.printf("%.1f\n", v2);
    }
}
s
