/**
 * 是否 Lazy 初始化：否
 * 是否多线程安全：是
 * 实现难度：易
 */
public class SingletonHungryMan {
    private static SingletonHungryMan instance = new SingletonHungryMan();

    private SingletonHungryMan() {}

    public static SingletonHungryMan getInstance() {
        return instance;
    }
}
