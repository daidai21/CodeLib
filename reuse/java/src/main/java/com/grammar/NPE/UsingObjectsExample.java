import java.util.Objects;

public class UsingObjectsExample {
    public static void main(String[] args) {
        System.out.println(Objects.equals(null, null));
        System.out.println(Objects.equals(1, null));
        System.out.println(Objects.equals(null, 1));
        System.out.println(Objects.equals(1, 1));
        System.out.println(Objects.equals(1, 2));
    }
}
