/**
 * Generic class example
 */
public class GenericClassExample {
    public static void main(String[] args) {
        Box<Integer> integerBox = new Box<Integer>();
        Box<String> stringBox = new Box<String>();
     
        integerBox.set(new Integer(10));
        stringBox.set(new String("Hello"));
     
        System.out.printf("Integer: %d\n", integerBox.get());
        System.out.printf("String : %s\n", stringBox.get());
    }
}


class Box<T> {
    private T t;

    public void set(T t) {
        this.t = t;
    }

    public T get() {
        return this.t;
    }
}
