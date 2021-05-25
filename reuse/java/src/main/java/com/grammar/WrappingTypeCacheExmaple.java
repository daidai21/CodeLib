
/**
 * Java中包装类型的cache机制
 * https://shann.xyz/2020/02/29/java/Java%E4%B8%AD%E5%8C%85%E8%A3%85%E7%B1%BB%E5%9E%8B%E7%9A%84cache%E6%9C%BA%E5%88%B6/
 * 
 * 
 */
public class WrappingTypeCacheExmaple {
    public static void main(String[] args) {
        Integer i1 = 127;
        Integer i2 = 127;
        Integer i3 = Integer.valueOf(127);
        Integer i4 = new Integer(127);
        Integer i5 = 128;
        Integer i6 = 128;
        System.out.println(i1 == i2);
        System.out.println(i1 == i3);
        System.out.println(i3 == i4);
        System.out.println(i5 == i6);
        /**
         * 那就是为什么i1==i2输出为true，而i5==i6输出为false呢?
         * 
         * cache范围是：
         * Integer	-128~127
         * Byte	-128~127
         * Short	-128~127
         * Long	-128~127
         * Character	0~128
         * Boolean	true, false
         */

        // String integerCacheHighPropValue = sun.misc.VM.getSavedProperty("java.lang.Integer.IntegerCache.high");
        // System.out.println("integerCacheHighPropValue=" + integerCacheHighPropValue);
    }

}
