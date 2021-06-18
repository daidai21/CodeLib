/**
 * 
 */
public class Example {
    public static void main(String[] args) {
        Foo foo = new Foo();
    }
}

class Foo {
    static int v = 123;

    public Foo() {
        System.out.println("Foo()");
    }

    static {
        System.out.println("static {}");
    }

    {
        System.out.println("{}");
    }

    public static void staticMethod() {
        System.out.println("static method");
    }
}
