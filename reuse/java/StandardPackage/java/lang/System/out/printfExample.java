public class printfExample {
    public static void main(String[] args) {
        double d = 12900000;
        System.out.println(d);
        System.out.printf("%.2f\n", d);
        System.out.printf("%.4f\n", d);

        int n = 12345000;
        System.out.printf("n=%d, hex=%08x\n", n, n);
    }
}
