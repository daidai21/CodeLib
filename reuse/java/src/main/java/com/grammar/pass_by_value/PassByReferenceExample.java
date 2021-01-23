
/**
 * pass by reference
 */
public class PassByReferenceExample {
    public static void main(String[] args) {
        Foo foo = new Foo(1, "1");
        System.out.println(foo);
        change(foo);
        System.out.println(foo);
        
    }

    private static void change(Foo foo) {
        foo.val1 = 111;
        foo.val2 = "222";
    }

}


class Foo {
    Foo(Integer val1, String val2) {
        this.val1 = val1;
        this.val2 = val2;
    }

    public Integer val1;

    public String val2;

    @Override
    public String toString() {
        return "{val1=" + this.val1 + ";val2=" + this.val2 + "}";
    }

}
