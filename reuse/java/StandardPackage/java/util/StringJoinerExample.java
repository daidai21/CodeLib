import java.util.StringJoiner;

/**
 * StringJoiner example
 */
public class StringJoinerExample {
    public static void main(String[] args) {
        String[] names = {"Bob", "Alice", "Grace"};
        StringJoiner sj = new StringJoiner(", ");
        for (String name : names) {
            sj.add(name);
        }
        System.out.println(sj.toString());

        StringJoiner sj1 = new StringJoiner(", ", "Hello ", "!");
        for (String name : names) {
            sj1.add(name);
        }
        System.out.println(sj1.toString());

    }
}
