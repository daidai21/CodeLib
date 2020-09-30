import java.util.Date;

public class ReadWriteEfficiencyExample {
    public static void main(String[] args) {
        ReadWriteEfficiencyExample readWriteEfficiencyExample =
            new ReadWriteEfficiencyExample();
        readWriteEfficiencyExample.check();
    }

    public void check() {
        long t1 = System.currentTimeMillis();
        for (int i = 0; i < 1000_000_000; ++i) {
            i1++;
        }
        long t2 = System.currentTimeMillis();
        System.out.println("normal: " + (t2 - t1) + "\n");

        t2 = System.currentTimeMillis();
        for (int i = 0; i < 1000_000_000; ++i) {
            i2++;
        }
        long t3 = System.currentTimeMillis();
        System.out.printf("volatile: " + (t3 - t2) + "\n");

        t3 = System.currentTimeMillis();
        for (int i = 0; i < 1000_000_000; ++i) {
            i3++;
        }
        long t4 = System.currentTimeMillis();
        System.out.printf("static: " + (t4 - t3) + "\n");

    }

    private int i1 = 0;
    private volatile int i2 = 0;
    private static int i3 = 0;
}
