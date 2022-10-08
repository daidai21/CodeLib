
import java.util.Random;

// Integer Long Float Double Boolean
public class BenchmarkSerialization {
    public static void main(String[] args) {
        int loopNum = 1000_000;
        Random rand = new Random();
        // 强制类型转换
        long start = System.currentTimeMillis();
        for (int i = 0; i < loopNum; i++) {
            Integer integerVal = rand.nextInt();
            Long longVal = rand.nextLong();
            Float floatVal = rand.nextFloat();
            Double doubleVal = rand.nextDouble();
            Boolean booleanVal = rand.nextBoolean();

            Object serVal;
            serVal = integerVal;
            integerVal = (Integer) serVal;
            serVal = longVal;
            longVal = (Long) serVal;
            serVal = floatVal;
            floatVal = (Float) serVal;
            serVal = doubleVal;
            doubleVal = (Double) serVal;
            serVal = booleanVal;
            booleanVal = (Boolean) serVal;
        }
        System.out.println(System.currentTimeMillis() - start);

         start = System.currentTimeMillis();
        for (int i = 0; i < loopNum; i++) {
            int integerVal = rand.nextInt();
            long longVal = rand.nextLong();
            float floatVal = rand.nextFloat();
            double doubleVal = rand.nextDouble();
            boolean booleanVal = rand.nextBoolean();

            Object serVal;
            serVal = integerVal;
            integerVal = (int) serVal;
            serVal = longVal;
            longVal = (long) serVal;
            serVal = floatVal;
            floatVal = (float) serVal;
            serVal = doubleVal;
            doubleVal = (double) serVal;
            serVal = booleanVal;
            booleanVal = (boolean) serVal;
        }
        System.out.println(System.currentTimeMillis() - start);


        // 序列化String的
        start = System.currentTimeMillis();
        for (int i = 0; i < loopNum; i++) {
            Integer integerVal = rand.nextInt();
            Long longVal = rand.nextLong();
            Float floatVal = rand.nextFloat();
            Double doubleVal = rand.nextDouble();
            Boolean booleanVal = rand.nextBoolean();

            String serVal;
            serVal = integerVal.toString();
            integerVal = Integer.getInteger(serVal);
            serVal = longVal.toString();
            longVal = Long.getLong(serVal);
            serVal = floatVal.toString();
            floatVal = Float.parseFloat(serVal);
            serVal = doubleVal.toString();
            doubleVal = Double.parseDouble(serVal);
            serVal = booleanVal.toString();
            booleanVal = Boolean.getBoolean(serVal);
        }
        System.out.println(System.currentTimeMillis() - start);

    }
}
/**
 * Output:
 * <p>
 * 105
 * 1165
 */
// 性能差了10倍，一个量级
