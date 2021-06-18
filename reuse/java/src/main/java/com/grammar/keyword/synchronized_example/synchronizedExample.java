
public class synchronizedExample {
    public static void main(String[] args) {

    }

    void fn() {
        // 修饰代码块
        synchronized (this.var1) {};
        synchronized (this) {};

        // 修饰类
        synchronized (synchronizedExample.class) {};
    }

    private Integer var1;

    // 修饰非静态方法
    synchronized void func1() {}

    // 修饰静态方法
    synchronized static void func2() {}
}
