
public class BraceExample {
    public static void main(String[] args) {
        Foo foo = new Foo();
    }
}

class Foo {
    {
        System.out.println("大括号中");
    }

    static {
        System.out.println("static代码块");
    }

    public Foo() {
        System.out.println("构造方法");
    }
}
