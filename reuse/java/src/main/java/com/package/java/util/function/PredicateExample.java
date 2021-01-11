import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.function.Predicate;
public class PredicateExample {
    public static void main(String[] args) {
        // 使用迭代器删除列表元素

        ArrayList<String> list = new ArrayList<>(Arrays.asList("I", "love", "you", "too"));
Iterator<String> it = list.iterator();
while(it.hasNext()){
    if(it.next().length()>3) // 删除长度大于3的元素
        it.remove();
}


//使用removeIf()结合匿名名内部类实现

ArrayList<String> list1 = new ArrayList<>(Arrays.asList("I", "love", "you", "too"));
list1.removeIf(new Predicate<String>(){ // 删除长度大于3的元素
    @Override
    public boolean test(String str){
        return str.length()>3;
    }
});

// 使用removeIf()结合Lambda表达式实现
ArrayList<String> list2 = new ArrayList<>(Arrays.asList("I", "love", "you", "too"));
list2.removeIf(str -> str.length()>3); // 删除长度大于3的元素
    }
}
