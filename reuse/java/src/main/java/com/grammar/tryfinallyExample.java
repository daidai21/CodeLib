public class tryfinallyExample {
    public static void main(String[] args) {
        System.out.println(func());
    }

    private static int func() {
        // finally 的return会覆盖try中的return
        try {
            return 1;
        } finally {
            return 2;
        }
    }
}
