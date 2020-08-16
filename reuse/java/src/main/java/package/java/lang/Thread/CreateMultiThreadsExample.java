import java.lang.Thread;
import java.lang.System;


public class CreateMultiThreadsExample {
    public static void main(String[] args) {
        // With runnable instance
        Thread t0 = new MyThread0();
        t0.start();

        // With lambda
        Thread t1 = new Thread(() -> {
            System.out.println("Start new thread!");
        });
        t1.start();

        // With main()
        System.out.println("Main start...");
        Thread t2 = new Thread() {
            public void run() {
                System.out.println("thread run...");
                System.out.println("thread end...");
            }
        };
        t2.start();
        System.out.println("Main end...");

        // config priority
        // Thread.setPriority(int n) // 1~10, default 5
    }
}


class MyThread0 extends Thread {
    @Override
    public void run() {
        System.out.println("Start new thread!");
    }
}
