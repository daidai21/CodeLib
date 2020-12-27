import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.FutureTask;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class FutureTaskExample {
    public static void main(String[] args) {
        MyRunnable myRunnable1 = new MyRunnable(1000);
        MyRunnable myRunnable2 = new MyRunnable(2000);
        FutureTask<String> futureTask1 = new FutureTask<>(myRunnable1, "FutureTask1 is complete");
        FutureTask<String> futureTask2 = new FutureTask<>(myRunnable2, "FutureTask2 is complete");
        ExecutorService executorService = Executors.newFixedThreadPool(2);
        executorService.submit(futureTask1);
        executorService.submit(futureTask2);
        while (true) {
            try {
                if (futureTask1.isDone() && futureTask2.isDone()) {
                    System.out.println("Both FutureTask Complete");
                    executorService.shutdown();
                    return;
                }
                if (!futureTask1.isDone()) {
                    System.out.println("FutureTask1 output = " + futureTask1.get());
                }
                System.out.println("Waiting for FutureTask2 to complete");
                String s = futureTask2.get(250, TimeUnit.MILLISECONDS);
                if (s != null) {
                    System.out.println("FutureTask2 output=" + s);
                }
            } catch (TimeoutException e) {
                System.out.println("TimeoutException");
            } catch (Exception e) {
                System.out.println("Exception: " + e);
            }
        }
    }
}

class MyRunnable implements Runnable {
    private final long waitTime;

    public MyRunnable(int timeInMillis) {
        this.waitTime = timeInMillis;
    }

    @Override
    public void run() {
        try {
            Thread.sleep(waitTime);
            System.out.println(Thread.currentThread().getName());
        } catch (InterruptedException e) {
            Logger.getLogger(MyRunnable.class.getName()).log(Level.SEVERE, null, e);
        }
    }
}
