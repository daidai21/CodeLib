import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * AtomicInteger ThreadLocal
 */
public class AtomicIntegerExample {
    public static void main(String[] args) {
        for (int i = 0; i < 10; i++) {
            System.out.print(ThreadId.get() + " ");
        }
        System.out.print("\n");

        List<Thread> threads = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            Thread t = new Thread() {
                @Override
                public void run() {
                    System.out.print(Thread.currentThread().getId() + ": " + ThreadId.get() + "; ");
                }
            };
            threads.add(t);
            t.start();
        }
        // FIXME
        for (int i = 0; i < threads.size(); ++i) {
            try {
                Field f = threads.get(i).getClass().getDeclaredField("threadLocals");
                f.setAccessible(true);
                System.out.println(f.get(threads.get(i)));
            } catch (IllegalAccessException e) {
                e.printStackTrace();
            } catch (NoSuchFieldException e) {
                e.printStackTrace();
            }
        }
    }
}

class ThreadId {
    private static final AtomicInteger nextId = new AtomicInteger(0);

    private static final ThreadLocal<Integer> threadId = new ThreadLocal<Integer>() {
        @Override
        protected Integer initialValue() {
            return nextId.getAndIncrement();
        }
    };

    public static int get() {
        return threadId.get();
    }
}
