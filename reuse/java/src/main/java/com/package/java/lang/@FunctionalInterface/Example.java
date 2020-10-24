
public class Example {
    public static void main(String[] args) {
        Hello hello = param -> "Hello " + param;
        String res = hello.message("Tom");
        System.out.println(res);
    }
}


@FunctionalInterface
interface Hello {
    String message(String info);
}


