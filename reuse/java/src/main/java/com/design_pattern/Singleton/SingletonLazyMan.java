/**
 * 是否 Lazy 初始化：是
 * 是否多线程安全：否
 * 实现难度：易
 */
public class SingletonLazyMan {
    private static SingletonLazyMan instance;

    private SingletonLazyMan() {}

    public static SingletonLazyMan getInstance() {
        if (instance == null) {
            instance = new SingletonLazyMan();
        }
        return instance;
    }
}
