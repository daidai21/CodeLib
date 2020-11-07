
public class finallyExample {
    public static void main(String[] args) {
        System.out.println(foo());
    }

    private static String foo() {
        try {
            System.out.println("try");
            throw new Exception();
        } catch (Exception e) {
            System.out.println("catch");
            return "catch return";
        } finally {
            System.out.println("finally");
        }
    }
}
