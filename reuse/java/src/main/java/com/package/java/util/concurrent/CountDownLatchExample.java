import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;

public class CountDownLatchExample {
    public static void main(String[] args) throws InterruptedException {
        CountDownLatch countDownLatch = new CountDownLatch(3);
        Thread thread1 = new TranslateThread("1st content", countDownLatch);
        Thread thread2 = new TranslateThread("2nd content", countDownLatch);
        Thread thread3 = new TranslateThread("3rd content", countDownLatch);

        thread1.start();
        thread2.start();
        thread3.start();

        countDownLatch.await(10, TimeUnit.SECONDS);
        System.out.println("All thread run over.");
    }
}

class TranslateThread extends Thread {

    private String content;
    private final CountDownLatch countDownLatch;

    public TranslateThread(String content, CountDownLatch countDownLatch) {
        this.content = content;
        this.countDownLatch = countDownLatch;
    }

    @Override
    public void run() {
        if (Math.random() > 0.5) {
            throw new RuntimeException("Error");
        }
        System.out.println(content + " over");
        countDownLatch.countDown();
    }
}
