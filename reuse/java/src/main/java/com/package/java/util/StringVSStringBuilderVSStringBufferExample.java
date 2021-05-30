public class StringVSStringBuilderVSStringBufferExample {
    public static void main(String[] args) {
        // String 类是不可改变的
        // 一旦创建了 String 对象，那它的值就无法改变了
        String string1 = "a";
        System.out.println(System.identityHashCode(string1));
        string1 = string1 + 1;
        System.out.println(System.identityHashCode(string1));

        // StringBuilder 是修改源对象
        StringBuilder stringBuilder1 = new StringBuilder("a");
        System.out.println(System.identityHashCode(stringBuilder1));
        stringBuilder1.append("b");
        System.out.println(System.identityHashCode(stringBuilder1));

        // StringBuffer 是修改源对象
        StringBuffer stringBuffer1 = new StringBuffer("a");
        System.out.println(System.identityHashCode(stringBuffer1));
        stringBuffer1.append("b");
        System.out.println(System.identityHashCode(stringBuffer1));
    }
}
