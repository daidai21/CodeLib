import java.util.concurrent.ThreadFactory;
import java.util.concurrent.atomic.AtomicInteger;


public class NamingThreadFactoryExample {
    public static void main(String[] args) {
        NamingThreadFactory namingThreadFactory = new NamingThreadFactory(
            null, // TODO
            "test");
        
    }
}


final class NamingThreadFactory implements ThreadFactory {
    private final AtomicInteger threadNum = new AtomicInteger();
    private final ThreadFactory delegate;
    private final String name;

    /**
     * Create thread pool factory of naming
     */
    public NamingThreadFactory(ThreadFactory delegate, String name) {
        this.delegate = delegate;
        this.name = name;
    }

    @Override
    public Thread newThread(Runnable runnable) {
        Thread thread = delegate.newThread(runnable);
        thread.setName(name + " [#" + threadNum.incrementAndGet() + "]");
        return thread;
    }
}
