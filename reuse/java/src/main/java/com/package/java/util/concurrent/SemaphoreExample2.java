import java.util.concurrent.Semaphore;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Random;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.Semaphore;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Semaphore;

/**
 * 张三、李四和王五和赵六4个人一起去饭店吃饭，不过在特殊时期洗手很重要，饭前洗手也是必须的，可是饭店只有2个洗手池，洗手池就是不能被同时使用的公共资源，这种场景就可以用到Semaphore。
 */
public class SemaphoreExample2 {
    public static void main(String[] args) throws InterruptedException {
        //饭店里只用两个洗手池，所以初始化许可证的总数为2。
        Semaphore washbasin = new Semaphore(2);

        List<Thread> threads = new ArrayList<>(3);
        threads.add(new Thread(new Customer(washbasin, "张三")));
        threads.add(new Thread(new Customer(washbasin, "李四")));
        threads.add(new Thread(new Customer(washbasin, "王五")));
        threads.add(new Thread(new Customer(washbasin, "赵六")));
        for (Thread thread : threads) {
            thread.start();
            Thread.sleep(50);
        }

        for (Thread thread : threads) {
            thread.join();
        }

    }
}

class Customer implements Runnable {
    private Semaphore washbasin;
    private String name;

    public Customer(Semaphore washbasin, String name) {
        this.washbasin = washbasin;
        this.name = name;
    }

    @Override
    public void run() {
        try {
            SimpleDateFormat sdf = new SimpleDateFormat("HH:mm:ss.SSS");
            Random random = new Random();

            washbasin.acquire();
            System.out.println(
            	sdf.format(new Date()) + " " + name + " 开始洗手...");
            Thread.sleep((long) (random.nextDouble() * 5000) + 2000);
            System.out.println(
            	sdf.format(new Date()) + " " + name + " 洗手完毕!");
            washbasin.release();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
