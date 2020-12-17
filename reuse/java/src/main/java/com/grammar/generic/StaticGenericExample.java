public class StaticGenericExample {
    public static void main(String[] args) {
        System.out.println(Cmp.equal(123L, "789"));
        System.out.println(Cmp.<Long, String>equal(123L, "123"));
    }
}

class Cmp<T1, T2> {
    public static <T1, T2> boolean equal(T1 t1, T2 t2) {
        return t1.toString().equals(t2.toString());
    }

    public T1 bigger(T1 t1, T2 t2) {
        return t1;
    }
}
