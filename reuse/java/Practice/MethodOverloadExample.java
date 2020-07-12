public class MethodOverloadExample {
    public static void main(String[] args) {
        Hello h = new Hello();
        h.hello();
        h.hello("Xiaoming");
    }
}


class Hello {
    public void hello() {
        System.out.println("Hello, world!");
    }

    public void hello(String name) {
        System.out.println("Hello, " + name + "!");
    }
}
