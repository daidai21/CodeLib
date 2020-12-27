import java.lang.Throwable;

public class ThrowableExample {
    public static void main(String[] args) throws Exception {
        try {
            testException();
        } catch (Throwable t) {
            System.out.println("Exception: " + t.toString());
        }
    }

    public static void testException() throws Exception {
        throw new Exception("New Exception Thrown");
    }
}
