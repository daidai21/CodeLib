import java.util.Arrays;
import java.util.List;
import java.util.function.Predicate;

public class Example {
    public static void main(String[] args) {
        List<Integer> list = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9);
        System.out.println("输出所有数据:");
        eval(list, n -> true);

        System.out.println("输出所有偶数:");
        eval(list, n -> n % 2 == 0);

        System.out.println("输出大于 3 的所有数字:");
        eval(list, n -> n > 3);

        System.out.println("输出大于 5 的所有数字:");
        Predicate<Integer> predicate = n -> n > 5;
        eval(list, predicate);
    }

    public static void eval(List<Integer> list, Predicate<Integer> predicate) {
        for (Integer n : list) {
            if (predicate.test(n)) {
                System.out.printf(n + " ");
            }
        }
        System.out.printf("\n");
    }
}
