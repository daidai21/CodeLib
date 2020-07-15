import java.util.ArrayList;
import java.util.Vector;


/**
 * Keyword instanceof example
 */
public class KeywordInstanceofExample {
    public static void main(String[] args) {
        Object o = new ArrayList<>();

        if (o instanceof Vector) {
            System.out.println("Object is class java.util.Vector instance");
        } else if (o instanceof ArrayList) {
            System.out.println("Object is class java.util.ArrayList instance");
        } else {
            System.out.println("Object is " + o.getClass() + " instance");
        }
        System.out.println("Object is " + o.getClass() + " instance");
    }
}

