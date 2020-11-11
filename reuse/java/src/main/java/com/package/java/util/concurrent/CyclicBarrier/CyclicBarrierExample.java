import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;

public class CyclicBarrierExample implements Runnable {
    public static void main(String[] args) {
        CyclicBarrierExample cyclicBarrierExample = new CyclicBarrierExample();
        Thread t1 = new Thread(cyclicBarrierExample);
        t1.start();
    }

    public void run() {
        System.out.println("Number of parties required to trip the barrier = " + newBarrier.getParties());
        System.out.println("Sum of product and sum = " + (Calc1.product + Calc2.sum));
        Calc1 calc1 = new Calc1();
        Calc2 calc2 = new Calc2();

        Thread t1 = new Thread(calc1);
        Thread t2 = new Thread(calc2);

        t1.start();
        t2.start();

        try {
            CyclicBarrierExample.newBarrier.await();
        } catch (InterruptedException | BrokenBarrierException e) {
            e.printStackTrace();
        }

        System.out.println("Sum of product and sum = " + (Calc1.product + Calc2.sum));
        newBarrier.reset();
        System.out.println("Barrier reset succeddful");
    }

    public static CyclicBarrier newBarrier = new CyclicBarrier(3);
}

class Calc1 implements Runnable {
    public static int product = 0;

    public void run() {
        product = 2 * 3;
        try {
            CyclicBarrierExample.newBarrier.await();
        } catch (InterruptedException | BrokenBarrierException e) {
            e.printStackTrace();
        }
    }
}

class Calc2 implements Runnable {
    public static int sum = 0;

    public void run() {
        System.out.println("Is the barrier broken? - " + CyclicBarrierExample.newBarrier.isBroken());
        sum = 10 + 20;
        try {
            CyclicBarrierExample.newBarrier.await(3000, TimeUnit.MILLISECONDS);
            System.out.println("Number of parites waiting at the barrier at this point = "
                    + CyclicBarrierExample.newBarrier.getNumberWaiting());
        } catch (InterruptedException | BrokenBarrierException e) {
            e.printStackTrace();
        } catch (TimeoutException e) {
            e.printStackTrace();
        }
    }
}
