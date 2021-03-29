/**
 * 调用有main函数的类中的其他方法
 */
public class CallClassIncludeMainFunctionExample {
    public static void main(String[] args) {
        new Foo().bar();
        Foo.main(new String[1]);
    }
}

class Foo {
    public static void main(String[] args) {
        System.out.println("Foo.main()");
    }

    public void bar() {
        System.out.println("Foo.bar()");
    }
}
