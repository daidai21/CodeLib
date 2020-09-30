/**
 * 是否 Lazy 初始化：是
 * 是否多线程安全：是
 * 实现难度：易
 */
public class SingletonLazyManThreadSafe {
    private static SingletonLazyManThreadSafe instance;

    private SingletonLazyManThreadSafe() {}

    public static synchronized SingletonLazyManThreadSafe getInstance() {
        if (instance == null) {
            instance = new SingletonLazyManThreadSafe();
        }
        return instance;
    }
}
