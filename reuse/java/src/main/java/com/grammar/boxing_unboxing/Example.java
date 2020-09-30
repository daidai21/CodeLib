
public class Example {
    public static void main(String[] args) {
        // 装箱
        // int -> Integer
        Integer I = 1;
        // 拆箱
        // Integer -> int
        int i = I;

        // 在通过valueOf方法创建Integer对象的时候，如果数值在[-128,127]之间，便返回指向IntegerCache.cache中已经存在的对象的引用；否则创建一个新的Integer对象。
        Integer i1 = 100;
        Integer i2 = 100;
        Integer i3 = 200;
        Integer i4 = 200;

        System.out.println(i1 == i2);
        System.out.println(i3 == i4);

        // 注意，Integer、Short、Byte、Character、Long这几个类的valueOf方法的实现是类似的。
        // Double、Float的valueOf方法的实现是类似的。
        Double d1 = 100.0;
        Double d2 = 100.0;
        Double d3 = 200.0;
        Double d4 = 200.0;

        System.out.println(d1 == d2);
        System.out.println(d3 == d4);

        // Java 基本类型的包装类的大部分都实现了常量池技术，即 Byte,Short,Integer,Long,Character,Boolean；这 5 种包装类默认创建了数值[-128，127] 的相应类型的缓存数据，但是超出此范围仍然会去创建新的对象。
    }
}
