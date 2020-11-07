public class ThreadLocalExample {
    public static void main(String[] args) {
        ThreadLocal<Number> threadLocalNumber = new ThreadLocal<>();
        ThreadLocal<String> threadLocalString = new ThreadLocal<>();
        threadLocalNumber.set(100);
        System.out.println("value = " + threadLocalNumber.get());
        threadLocalNumber.set(90);
        System.out.println("value = " + threadLocalNumber.get());
        threadLocalNumber.set(88.45);
        System.out.println("value = " + threadLocalNumber.get());
        threadLocalString.set("hello");
        System.out.println("value = " + threadLocalString.get());

        threadLocalNumber.remove();
        System.out.println("value = " + threadLocalNumber.get());
        threadLocalString.remove();
        System.out.println("value = " + threadLocalString.get());

        for (int i = 0; i < 15; ++i) {
            new NewThread("quiz" + i);
        }
    }
}

class NewThread extends Thread {
    private static ThreadLocal threadLocal = new ThreadLocal() {
        @Override
        protected Object initialValue() {
            return new Integer(question--);
        }
    };

    private static int question = 15;

    public NewThread(String name) {
        super(name);
        start();
    }

    public void run() {
        for (int i = 0; i < 2; ++i) {
            System.out.println(getName() + " " + threadLocal.get());
        }
    }
}
