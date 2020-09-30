
public class IntegerExample {
    public static void main(String[] args) {
        // Integer对象 用equals比较
        Integer x = 3;
        Integer y = 3;
        System.out.println(x == y); // true
        Integer a = new Integer(3);
        Integer b = new Integer(3);
        System.out.println(a == b); // false
        System.out.println(a.equals(b)); // true
    }
}
