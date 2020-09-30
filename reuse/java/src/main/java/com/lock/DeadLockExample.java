/* ****************************************************************************
 * File Name   : DeadLockExample.java
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 一  9/28 17:21:05 2020
 *************************************************************************** */

public class DeadLockExample {
    private static Object resources1 = new Object();
    private static Object resources2 = new Object();

    public static void main(String[] args) {
        new Thread(() -> {
            synchronized (resources1) {
                System.out.println(Thread.currentThread() + "get resource1");
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println(Thread.currentThread() + "waiting get resource2");
                synchronized (resources2) {
                    System.out.println(Thread.currentThread() + "get resource2");
                }
            }
        }, "thread1").start();

        new Thread(() -> {
            synchronized (resources2) {
                System.out.println(Thread.currentThread() + "get resource2");
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println(Thread.currentThread() + "waiting get resource1");
                synchronized (resources1) {
                    System.out.println(Thread.currentThread() + "get resource1");
                }
            }
        }, "thread2").start();

    }
}
