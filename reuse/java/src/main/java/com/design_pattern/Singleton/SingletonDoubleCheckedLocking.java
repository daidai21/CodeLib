/**
 * @version JDK1.5 起
 * 是否 Lazy 初始化：是
 * 是否多线程安全：是
 * 实现难度：较复杂
 */
public class SingletonDoubleCheckedLocking {
    private volatile static SingletonDoubleCheckedLocking singletonDoubleCheckedLocking;

    private SingletonDoubleCheckedLocking() {}

    public static SingletonDoubleCheckedLocking getInstance() {
        if (singletonDoubleCheckedLocking == null) {
            synchronized (SingletonDoubleCheckedLocking.class) {
                if (singletonDoubleCheckedLocking == null) {
                    singletonDoubleCheckedLocking = new SingletonDoubleCheckedLocking();
                }
            }
        }
        return singletonDoubleCheckedLocking;
    }
}
