public class JvmStackCpr {
    public int a = 0;
    public void f1() {}
    public void f2() {
        int b = a;
        f1();
    }
}
