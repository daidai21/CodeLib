/**
 * Short circuit operation
 */
public class ShortCircuitOperation {
    public static void main(String[] args) {
        boolean b = 5 < 3;
        boolean result = b && (5 / 0 > 0);
        System.out.println(result);

        result = true || (5 / 0 > 0);
        System.out.println(result);
    }
}
