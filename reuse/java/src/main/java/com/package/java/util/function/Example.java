import java.util.function.BiFunction;
import java.util.function.Function;

public class Example {
    public static void main(String[] args) {
        printCalcFunc(val -> new Long(val) - 1, 5);
        printCalcBiFunc((val1, val2) -> {
            return new Long(val1) + val2 == 5;
        }, 1, 3L);
        printCalcBiFunc((val1, val2) -> {
            return new Long(val1) + val2 == 5;
        }, 2, 3L);
    }

    /**
     * print calculate function
     * 
     * @param func  lambda
     * @param arg1
     */
    public static void printCalcFunc(Function<Integer, Long> func, Integer arg1) {
        Long res = func.apply(arg1);
        System.out.println(res);
    }

    public static void printCalcBiFunc(BiFunction<Integer, Long, Boolean> func, Integer arg1, Long arg2) {
        Boolean res = func.apply(arg1, arg2);
        System.out.println(res);
    }
}
