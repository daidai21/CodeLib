import java.util.ArrayList;


public class TypeErasureExample {
    public static void main(String[] args) throws Exception {
        // 原始类型相等
        ArrayList<String> list1 = new ArrayList<String>();
        list1.add("abc");
        ArrayList<Integer> list2 = new ArrayList<Integer>();
        list2.add(123);
        System.out.println(list1.getClass());
        System.out.println(list2.getClass());
        System.out.println(list1.getClass() == list2.getClass());

        // 通过反射添加其它类型元素
        ArrayList<Integer> list3 = new ArrayList<Integer>();
        list3.add(1);
        list3.getClass().getMethod("add", Object.class).invoke(list3, "abc");
        for (int i = 0; i < list3.size(); ++i) {
            System.out.println(list3.get(i));
        }
    }
}
