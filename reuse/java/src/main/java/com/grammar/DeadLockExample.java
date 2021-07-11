public class DeadLockExample {
    private static Object resource1 = new Object();
    private static Object resource2 = new Object();

    public static void main(String[] args) {
        new Thread(() -> {
            synchronized(resource1) {
                System.out.println(Thread.currentThread() + " get resource1");
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println(Thread.currentThread() + " waiting get resource2");
                synchronized(resource2) {
                    System.out.println(Thread.currentThread() + " get resource2");
                }
            }
        }, "Thread1").start();
        new Thread(() -> {
            synchronized(resource2) {
                System.out.println(Thread.currentThread() + " get resource2");
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println(Thread.currentThread() + " waiting get resource1");
                synchronized(resource1) {
                    System.out.println(Thread.currentThread() + " get resource1");
                }
            }
        }, "Thread2").start();
        // Thread2 中 resource2和resource1位置互换就可以避免死锁了
        // 资源要顺序申请，反序释放
    }
}
