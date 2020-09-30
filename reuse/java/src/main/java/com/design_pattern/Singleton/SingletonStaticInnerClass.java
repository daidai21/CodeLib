/**
 * 是否 Lazy 初始化：是
 * 是否多线程安全：是
 * 实现难度：一般
 */
public class SingletonStaticInnerClass {
    private static class SingletonStaticInnerClassHolder {
        private static final SingletonStaticInnerClass INSTANCE = new SingletonStaticInnerClass();
    }

    private SingletonStaticInnerClass() {}

    public static final SingletonStaticInnerClass getInstance() {
        return SingletonStaticInnerClassHolder.INSTANCE;
    }
}
