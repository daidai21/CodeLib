/**
 * String.intern()方法的返回值会加入运行时常量池中。
 * 
 */
public class MethodAreaStr {
    public static void main(String[] args) {
        // 由前面的例子可知，str1和str2位于常量池中
        String str1 = "hello";
        String str2 = "hello";
        System.out.println("str1 == str2: " + (str1 == str2));
        // str3和str4都是使用new创建的，位于堆中
        String str3 = new String("hello");
        String str4 = new String("hello");
        System.out.println("str3 == str4: " + (str3 == str4));
        System.out.println("str3 == str1: " + (str3 == str1));
        // str3.intern()返回长常量池已有的与其相等的String对象
        System.out.println("str3.intern() == str1: " + (str3.intern() == str1));

        String s1 = new String("world");
        System.out.println("s1.intern() == \"world\": " + (s1.intern() == "world"));
    }
}
